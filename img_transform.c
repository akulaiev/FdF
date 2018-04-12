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

	printf("%i %i\n", coords->size_x, coords->size_y);

	coords->win_width = fmax(coords->size_x, coords->size_y) * 30;
	coords->win_length = coords->win_width;
	coords->сoeff = 15;

	coords->shift_right = 0;
	coords->shift_down = 0;

	// coords->shift_right = (coords->win_width / 2) - (coords->size_x / 2);
	// coords->shift_down = (coords->win_length / 2) - (coords->size_y / 2);
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
