/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_transform_help.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:43:10 by akulaiev          #+#    #+#             */
/*   Updated: 2018/04/18 18:43:15 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	open_window(t_coords coords)
{
	manipulate_window(&coords);
	mlx_string_put(coords.mlx_p, coords.mlx_nw, 10, 10, 0x42f4d9,
	"Hi! Enjoy exploring my FdF project!!!");
	mlx_hook(coords.mlx_nw, 2, 5, key_react, (void*)&coords);
	set_coord(coords, 0, 0);
	mlx_loop(coords.mlx_p);
}

void	manipulate_window(t_coords *c)
{
	int		win_diagonal;
	int		diagonal;

	diagonal = count_diagonal(c);
	win_diagonal = count_win_diagonal(c, diagonal);
	c->сoeff = 1;
	c->angle_x = -0.17;
	c->angle_y = 0;
	c->angle_z = 0;
	while (diagonal * c->сoeff < (win_diagonal / 1.5))
		c->сoeff++;
	c->shift_right = (c->win_width / 2) - ((c->size_x * c->сoeff) / 2);
	c->shift_down = (c->win_length / 2) - ((c->size_y * c->сoeff) / 2);
	c->mlx_p = mlx_init();
	c->mlx_nw = mlx_new_window(c->mlx_p, c->win_width, c->win_length, "test");
}

int		count_diagonal(t_coords *c)
{
	int		z;
	int		d;
	int		temp;
	int		i;
	int		j;

	i = 0;
	z = 0;
	while (i < c->size_y)
	{
		j = 0;
		while (j < c->size_x)
		{
			if (abs(c->coord_arr[i][j]) > abs(c->coord_arr[i][j + 1]))
			{
				temp = abs(c->coord_arr[i][j]);
				if (temp > z)
					z = temp;
			}
			j++;
		}
		i++;
	}
	d = sqrt((c->size_x * c->size_x) + (c->size_y * c->size_y) + (z * z));
	return (d);
}

int		count_win_diagonal(t_coords *coords, int diagonal)
{
	int		win_diagonal;

	if (diagonal < 100)
	{
		coords->win_width = 850;
		coords->win_length = 850;
		win_diagonal = sqrt((850 * 850) + (850 * 850));
	}
	else if (diagonal > 100 && diagonal < 400)
	{
		coords->win_width = 1250;
		coords->win_length = 1250;
		win_diagonal = sqrt((1250 * 1250) + (1250 * 1250));
	}
	else
	{
		coords->win_width = 2500;
		coords->win_length = 1500;
		win_diagonal = sqrt((2500 * 2500) + (1500 * 1500));
	}
	return (win_diagonal);
}
