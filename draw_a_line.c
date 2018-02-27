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

static int		absolute(int i) // needed for the Bresenham's line algorithm
{
	if (i < 0)
		i *= (-1);
	return (i);
}

void	draw_a_line(void *mlx_p, void *mlx_nw, minlx line) // can be used in the program
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
		mlx_pixel_put(mlx_p, mlx_nw, x, y, line.col);
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

static minlx	coord_to_struct(int x0, int y0, int x1, int y1) // to be deleted in order of the architecture
{
	minlx	line;

	line.x0 = x0;
	line.y0 = y0;
	line.x1 = x1;
	line.y1 = y1;
	return (line);
}

void	set_coord(void *mlx_p, void *mlx_nw) // to be adjusted due to the program architecture
{
	minlx	line;

	line = coord_to_struct(100, 100, 600, 100);
	line.col = 0xf442eb;
	draw_a_line(mlx_p, mlx_nw, line);
	line = coord_to_struct(100, 100, 100, 600);
	line.col = 0x42f4d9;
	draw_a_line(mlx_p, mlx_nw, line);
	line = coord_to_struct(100, 600, 600, 600);
	line.col = 0x65f441;
	draw_a_line(mlx_p, mlx_nw, line);
	line = coord_to_struct(600, 600, 600, 100);
	line.col = 0xeef441;
	draw_a_line(mlx_p, mlx_nw, line);
}

