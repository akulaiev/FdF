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
	int delta_x;
	int delta_y;
	int len_x;
	int len_y;
	int len;
	int	x;
	int	y;
	int	delta;

	delta_x = (line.x1 - line.x0 >= 0 ? 1 : -1);
	delta_y = (line.y1 - line.y0 >= 0 ? 1 : -1);
	len_x = absolute(line.x1 - line.x0);
	len_y = absolute(line.y1 - line.y0);
	len = fmax((float)len_x, (float)len_y);
	x = line.x0;
	y = line.y0;
	if (!len)
		mlx_pixel_put(line.mlx_p, line.mlx_nw, line.x0, line.y0, line.col);
	if (len_y <= len_x)
	{
		delta = -(len_x);
		len++;
		while(len--)
		{
			mlx_pixel_put(line.mlx_p, line.mlx_nw, x, y, line.col);
			x += delta_x;
			delta += 2 * len_y;
			if (delta)
			{
				delta -= 2 * len_x;
				y += delta_y;
			}
		}
	}
	else
	{
		delta = -(len_y);
		len++;
		while(len--)
		{
			mlx_pixel_put(line.mlx_p, line.mlx_nw, x, y, line.col);
			y += delta_y;
			delta += 2 * len_x;
			if (delta)
			{
				delta -= 2 * len_y;
				x += delta_x;
			}
		}
	}
}



// void			draw_a_line(t_minlx line) // Bresenham's line algorithm
// {
// 	int		tilt;
// 	int		dir_y;
// 	int		y;
// 	int		x;

// 	y = line.y0;
// 	x = line.x0;
// 	dir_y = line.y1 - line.y0;
// 	if (dir_y > 0)
// 		dir_y = 1;
// 	if (dir_y < 0)
// 		dir_y = -1;
// 	while (x != line.x1 || y != line.y1)
// 	{
// 		mlx_pixel_put(line.mlx_p, line.mlx_nw, x, y, line.col);
// 		if (line.x0 != line.x1 && (tilt = 0))
// 			tilt += absolute(line.y1 - line.y0);
// 		if ((tilt * 2) >= absolute(line.x1 - line.x0))
// 			tilt -= absolute(line.x1 - line.x0);
// 		y += dir_y;
// 		if (line.x1 > line.x0)
// 			x++;
// 		else if (line.x1 < line.x0)
// 			x--;
// 	}
// }
