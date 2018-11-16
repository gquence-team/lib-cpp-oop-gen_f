/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:43:54 by gquence           #+#    #+#             */
/*   Updated: 2018/09/11 18:07:31 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_atoi(char *str)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int		ft_first_str(t_fiefi file, char **str)
{
	int		i;
	int		j;
	char	c[1];
	char	line[14];

	i = 0;
	while (read(file.fd, c, 1) && *c != '\n' && i < 13)
		line[i++] = *c;
	if (i >= 13)
		return (-1);
	if (line[0] == 0)
		return (0);
	if (line[i - 4] <= '0' && line[i - 4] >= '9')
		return (-1);
	line[i] = '\0';
	j = i - 3;
	while (line[j])
	{
		**str = line[j];
		line[j++] = '.';
		++*str;
	}
	*str -= 3;
	j = ft_atoi(line);
	return (j);
}

int		insert_fline(char **line, t_fiefi file, char *strch)
{
	int		i;
	char	*str;
	int		j;
	char	check[1];

	i = 0;
	while (read(file.fd, check, 1) && *check != '\n')
	{
		str = malloc(sizeof(char) * ++i);
		j = 0;
		while (j++ < i)
			str[j - 1] = line[0][j - 1];
		if (*check == strch[0] || *check == strch[1])
			str[i - 1] = *check;
		else
			return (-1);
		free(*line);
		*line = malloc(sizeof(char) * i);
		j = 0;
		while (j++ < i)
			line[0][j - 1] = str[j - 1];
		free(str);
	}
	return (i);
}

int		ft_mk_othmatrix(char **matrix, t_fiefi file, char *str)
{
	char	check[1];
	int		i;
	int		j;

	j = 1;
	while (j < (*file.len_y))
	{
		matrix[j] = malloc(sizeof(char) * (*file.len_x));
		i = 0;
		while (read(file.fd, check, 1) && i < *file.len_x)
		{
			if (*check != '\n')
				matrix[j][i] = *check;
			i++;
		}
		j++;
	}
	if (j != (*file.len_y))
		return (-1);
	return (0);
}

int		ft_mk_matrix(t_fiefi file, char *str)
{
	int		x;
	char	check[1];
	char	**matrix;
	int		i;
	int		j;

	j = 1;
	file.len_x = &x;
	matrix = (char **)malloc(sizeof(char *) * (*file.len_y));
	matrix[0] = malloc(sizeof(char) * 1);
	matrix[0][0] = 0;
	x = insert_fline(matrix, file, str);
	if (x == -1)
		return (-1);
	if (ft_mk_othmatrix(matrix, file, str) == -1)
		return (-1);
	ft_read(file);
	return (0);
}

void	ft_read(t_fiefi file)
{
	char **str;

	*file.len_y = 0;
	str = (char **)malloc(sizeof(char *));
	str[0] = (char *)malloc(sizeof(char) * 3);
	*file.len_y = ft_first_str(file, str);
	if (*file.len_y == -1)
	{
		write(2, "map error\n", 10);
		return ;
	}
	if (*file.len_y == 0)
		return ;
	if (ft_mk_matrix(file, str[0]) == -1)
	{
		write(2, "map error\n", 10);
		return ;
	}
	free(str[0]);
	free(str);
}

int		main(int argc, char **argv)
{
	t_fiefi	file;
	int		i;
	int		a;

	i = 1;
	file.len_y = &a;
	while (argc > i)
	{
		file.fd = open(argv[i++], O_RDONLY);
		if (file.fd == -1)
		{
			write(2, "open() error\n", 14);
			continue;
		}
		ft_read(file);
		close(file.fd);
	}
	return (0);
}
