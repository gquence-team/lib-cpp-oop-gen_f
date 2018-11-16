/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:05:21 by gquence           #+#    #+#             */
/*   Updated: 2018/09/12 16:26:07 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct	s_square
{
	int x;
	int y;
	int len;
}				t_square;

typedef struct	s_coords
{
	int x;
	int y;
}				t_coords;

typedef struct	s_fiefi
{
	int		fd;
	int		*len_y;
	int		*len_x;
} 				t_fiefi;

void			write_info(t_square *sq, t_coords coords, int *size);
int				**calc_field(int maxx, int maxy, int **a);
void			loop(int *size, t_coords *coords, int **test, t_square *sq);
int				f(int **arr, int maxx, int maxy);
int				ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_atoi(char *str);
int				ft_first_str(t_fiefi file, char **str);
int				insert_fline(char **line, t_fiefi file, char *strch);
int				ft_mk_othmatrix(char **matrix, t_fiefi file, char *str);
int				ft_mk_matrix(t_fiefi file, char *str);
void			ft_read(t_fiefi file);
void            ft_putarr(

#endif
