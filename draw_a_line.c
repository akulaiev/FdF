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

void			draw_a_line(t_minlx line)
{
	int dx;
	int dy;
	int lengthX;
	int lengthY;
	int length;
	int x;
	int y;
	int d;

	dx = (line.x1 - line.x0 >= 0 ? 1 : -1);
	dy = (line.y1 - line.y0 >= 0 ? 1 : -1);
	lengthX = abs(line.x1 - line.x0);
	lengthY = abs(line.y1 - line.y0);
	length = fmax((float)lengthX, (float)lengthY) + 1;
	x = line.x0;
	y = line.y0;
	d = - lengthY;
	if (length == 0)
		mlx_pixel_put(line.mlx_p, line.mlx_nw, line.x0, line.y0, line.col);
	if (lengthY <= lengthX)
	{
		while(length--)
		{
			mlx_pixel_put(line.mlx_p, line.mlx_nw, x, y, line.col);
			x += dx;
			d += 2 * lengthY;
			if (d > 0)
			{
				d -= 2 * lengthX;
				y += dy;
			}
		}
	}
	else
	{
		while(length--)
		{
			mlx_pixel_put(line.mlx_p, line.mlx_nw, x, y, line.col);
			y += dy;
			d += 2 * lengthX;
			if (d > 0)
			{
				d -= 2 * lengthY;
				x += dx;
			}
		}
	}
}
