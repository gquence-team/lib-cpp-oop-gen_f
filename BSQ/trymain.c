#include "ft.h"

void	ft_putarr(char **arr, t_coords c, t_square sq, char cr)
{
	int i;
	int j;

	i = -1;
	while (++i < c.x)
	{
		j = -1;
		while (++j < c.y)
		{
			if (i >= sq.x && c.x < sq.x + sq.len && j >= sq.y && j < sq.y + sq.len)
				ft_putchar(cr);
			else
				ft_putchar(arr[i][j]);
		}
	}
}