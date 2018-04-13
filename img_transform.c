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

t_minlx	manipulate_window(t_coords *coords)
{
	t_minlx	win;
	int		diagonal;
	int		win_diagonal;
	int		small_diagonal;
	int		mid_diagonal;
	int		max_diagonal;
	int		small_width;
	int		small_length;
	int		mid_width;
	int		mid_length;
	int		max_width;
	int		max_length;
	int		max_z;
	int		temp;
	int		i;
	int		j;
	
	i = 0;
	max_z = 0;
	while (i < coords->size_y)
	{
		j = 0;
		while (j < coords->size_x)
		{
			if (abs(coords->coord_arr[i][j]) > abs(coords->coord_arr[i][j + 1]))
			{
				temp = abs(coords->coord_arr[i][j]);
				if (temp > max_z)
					max_z = temp;
			}
			j++;
		}
		i++;
	}
	diagonal = sqrt((coords->size_x * coords->size_x) + (coords->size_y * coords->size_y) + (max_z * max_z));
	small_width = 550;
	small_length = 550;
	mid_width = 1250;
	mid_length = 1250;
	max_width = 2500;
	max_length = 1500;
	small_diagonal = sqrt((small_width * small_width) + (small_length * small_length));
	mid_diagonal = sqrt((mid_width * mid_width) + (mid_length * mid_length));
	max_diagonal = sqrt((max_width * max_width) + (max_length * max_length));
	if (diagonal < 100)
	{
		coords->win_width = small_width;
		coords->win_length = small_length;
		win_diagonal = small_diagonal;

	}
	else if (diagonal > 100 && diagonal < 400)
	{
		coords->win_width = mid_width;
		coords->win_length = mid_length;
		win_diagonal = mid_diagonal;
	}
	else
	{
		coords->win_width = max_width;
		coords->win_length = max_length;
		win_diagonal = max_diagonal;
	}
	coords->сoeff = 1;
	while (diagonal * coords->сoeff < (win_diagonal / 1.5))
		coords->сoeff++;

	coords->shift_right = (coords->win_width / 2) - ((coords->size_x * coords->сoeff) / 2);
	coords->shift_down = (coords->win_length / 2) - ((coords->size_y * coords->сoeff) / 2);

	// coords->shift_right = 150;
	// coords->shift_down = 300;

	// coords->shift_right = (coords->win_width / 2) - (coords->size_x / 2);
	// coords->shift_down = (coords->win_length / 2) - (coords->size_y / 2);

	printf("%i %i\n", (coords->size_x * coords->сoeff) / 2, (coords->size_y * coords->сoeff) / 2);
	printf("%i %i\n", coords->win_width / 2, coords->win_length / 2);

	win.mlx_p = mlx_init();
	win.mlx_nw = mlx_new_window(win.mlx_p, coords->win_width, coords->win_length, "test");
	return (win);
}

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

t_dot	centre(t_dot dot, int shift_right, int shift_down)
{
	t_dot res;

	res.x = dot.x + shift_right;
	res.y = dot.y + shift_down;
	return (res);
}
