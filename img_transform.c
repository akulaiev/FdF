/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_transformation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:00:17 by akulaiev          #+#    #+#             */
/*   Updated: 2018/04/12 16:00:21 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	manipulate_window(t_coords *coords)
{
	int		win_diagonal;
	int		diagonal;
	
	diagonal = count_diagonal(coords);
	if (diagonal < 100)
	{
		coords->win_width = 750;
		coords->win_length = 750;
		win_diagonal = sqrt((750 * 750) + (750 * 750));
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
	coords->сoeff = 1;
	while (diagonal * coords->сoeff < (win_diagonal / 1.5))
		coords->сoeff++;

	coords->shift_right = (coords->win_width / 2) - ((coords->size_x * coords->сoeff) / 2);
	coords->shift_down = (coords->win_length / 2) - ((coords->size_y * coords->сoeff) / 2);

	coords->mlx_p = mlx_init();
	coords->mlx_nw = mlx_new_window(coords->mlx_p, coords->win_width, coords->win_length, "test");
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
	return(d);
}

int		count_win_diagonal(t_coords *c)

t_dot	turn(t_dot dot, double angle)
{
	t_dot 	res;
	double	cos_angle;
	double	sin_angle;

	sin_angle = sin(angle);
	cos_angle = cos(angle);
	res.y = dot.y * cos_angle - dot.x * sin_angle;
	res.x = dot.y * sin_angle + dot.x * cos_angle;
	res.z = dot.z * cos_angle - dot.y * sin_angle;
	res.y = dot.z * sin_angle + dot.y * cos_angle;
	res.z = dot.z * cos_angle - dot.x * sin_angle;
	res.x = dot.z * sin_angle + dot.x * cos_angle;
	return (res);
}

t_dot	enlarge(t_dot dot, int size)
{
	t_dot res;

	res.x = dot.x * size;
	res.y = dot.y * size;
	res.z = dot.z * size;
	return (res);
}

t_dot	move(t_dot dot, int shift_right, int shift_down)
{
	t_dot res;

	res.x = dot.x + shift_right;
	res.y = dot.y + shift_down;
	return (res);
}
