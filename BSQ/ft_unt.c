#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "ft.h"

void			write_info(t_square *sq, t_coords coords, int *size)
{
	sq->len++;
	sq->x = coords.x;
	sq->y = coords.y;
	(*size)++;
}

int			**calc_field(int maxx, int maxy, char **a)
{
	int i;
	int j;
	int **q;

	i = -1;
	q = (int **)malloc(sizeof(int *) * maxx);
	while (++i < maxx)
	{
		j = -1;
		*(q + i) = (int *)malloc(sizeof(int) * maxy);
		while (++j < maxy)
			if (i > 1 && j > 1)
				q[i][j] = q[i - 1][j] + q[i][j - 1] - q[i - 1][j - 1] + a[i][j];
			else if (i == 0 && j == 0)
				q[i][j] = a[i][j];
			else if (i == 0)
				q[i][j] = q[i][j - 1] + a[i][j];
			else if (j == 0)
				q[i][j] = q[i - 1][j] + a[i][j];
	}
	return (q);
}

void			loop(int *size, t_coords *coords, int **test, t_square *sq)
{
	if (coords->y == 0 && coords->x == 0)
		if (!test[*size - 1][*size - 1])
			write_info(sq, *coords, size);
		else
			coords->y++;
	else if (coords->y == 0)
		if (!(test[coords->x + *size - 1][*size - 1]
			- test[coords->x - 1][*size - 1]))
			write_info(sq, *coords, size);
		else
			coords->y++;
	else if (coords->x == 0)
		if (!(test[*size - 1][coords->y + *size - 1]
			- test[*size - 1][coords->y - 1]))
			write_info(sq, *coords, size);
		else
			coords->y++;
	else if (!(test[coords->x + *size - 1][coords->y + *size - 1]
			- test[coords->x + *size - 1][coords->y - 1]
			- test[coords->x - 1][coords->y + *size - 1]
			+ test[coords->x - 1][coords->y - 1]))
		write_info(sq, *coords, size);
	else
		coords->y++;
}

int				f(char **arr, int maxx, int maxy)
{
	t_coords	coords;
	int			size;
	int			**test;
	t_square	sq;

	coords.x = 0;
	coords.y = 0;
	size = 1;
	test = calc_field(maxx, maxy, arr);
	while (size + coords.x <= maxx)
	{
		coords.y = 0;
		while (size + coords.y < maxy)
		{
			if (size + coords.x >= maxy)
				break ;
			loop(&size, &coords, test, &sq);
		}
		coords.x++;
	}
	return (0);
}
