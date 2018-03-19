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

int				absolute(int i) // needed for the Bresenham's line algorithm
{
	if (i < 0)
		i *= (-1);
	return (i);
}

void			draw_a_line(t_minlx line) // Bresenham's line algorithm
{
	int		tilt;
	int		dir_y;
	int		y;
	int		x;

	y = line.y0;
	x = line.x0;
	dir_y = line.y1 - line.y0;
	if (dir_y > 0)
		dir_y = 1;
	if (dir_y < 0)
		dir_y = -1;
	while (x != line.x1 || y != line.y1)
	{
		mlx_pixel_put(line.mlx_p, line.mlx_nw, x, y, line.col);
		if (line.x0 != line.x1 && (tilt = 0))
			tilt += absolute(line.y1 - line.y0);
		if ((tilt * 2) >= absolute(line.x1 - line.x0))
			tilt -= absolute(line.x1 - line.x0);
		y += dir_y;
		if (line.x1 > line.x0)
			x++;
		else if (line.x1 < line.x0)
			x--;
	}
}

