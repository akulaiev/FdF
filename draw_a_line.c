/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_a_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:30:54 by akulaiev          #+#    #+#             */
/*   Updated: 2018/02/27 18:30:56 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int				absolute(int i)
{
	if (i < 0)
		i *= (-1);
	return (i);
}

void			pix_put_1(t_minlx line, t_breth brth)
{
	while (brth.length--)
	{
		mlx_pixel_put(line.mlx_p, line.mlx_nw, brth.x, brth.y, line.col);
		brth.x += brth.dx;
		brth.d += 2 * brth.lengthY;
		if (brth.d > 0)
		{
			brth.d -= 2 * brth.lengthX;
			brth.y += brth.dy;
		}
	}
}

void			pix_put_2(t_minlx line, t_breth brth)
{
	while (brth.length--)
	{
		mlx_pixel_put(line.mlx_p, line.mlx_nw, brth.x, brth.y, line.col);
		brth.y += brth.dy;
		brth.d += 2 * brth.lengthX;
		if (brth.d > 0)
		{
			brth.d -= 2 * brth.lengthY;
			brth.x += brth.dx;
		}
	}
}

void			draw_a_line(t_minlx line, t_dot start, t_dot end)
{
	t_breth		brth;

	brth.dx = (end.x - start.x >= 0 ? 1 : -1);
	brth.dy = (end.y - start.y >= 0 ? 1 : -1);
	brth.lengthX = absolute(end.x - start.x);
	brth.lengthY = absolute(end.y - start.y);
	brth.length = fmax((float)brth.lengthX, (float)brth.lengthY) + 1;
	brth.x = start.x;
	brth.y = start.y;
	brth.d = -brth.lengthY;
	if (brth.length == 0)
		mlx_pixel_put(line.mlx_p, line.mlx_nw, start.x, start.y, line.col);
	if (brth.lengthY <= brth.lengthX)
		pix_put_1(line, brth);
	else
		pix_put_2(line, brth);
}
