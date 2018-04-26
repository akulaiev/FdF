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

static int		gradient(int col_one, int col_two, int line_len, int pix_dist)
{
	// (A1-(A1-B1)/h*x, A2-(A2-B2)/h*x, A3-(A3-B3)/h*x)
	int		start_r;
	int		start_g;
	int		start_b;
	int		end_r;
	int		end_g;
	int		end_b;
	int		res_r;
	int		res_g;
	int		res_b;
	int		res_col;
	int		col_start;
	int		col_end;

	if (col_one <= col_two)
	{
		col_start = col_one;
		col_end = col_two;
	}
	else
	{
		col_start = col_two;
		col_end = col_one;
	}
	start_r = (col_start >> 16) & 255;
	start_g = (col_start >> 8) & 255;
	start_b = col_start & 255;
	end_r = (col_end >> 16) & 255;
	end_g = (col_end >> 8) & 255;
	end_b = col_end & 256;
	res_r = start_r - (start_r - end_r) / line_len * pix_dist;
	res_g = start_g - (start_g - end_g) / line_len * pix_dist;
	res_b = start_b - (start_b - end_b) / line_len * pix_dist;
	res_col = (res_r << 16) + (res_g << 8) + res_b;
	return (res_col);
}

static void		pix_put_x(t_coords line, t_breth brth, int col_start, int col_end)
{
	int		len_x;

	len_x = brth.lengthX;
	brth.d1 = brth.dy2 - brth.lengthX;
	brth.d2 = brth.dz2 - brth.lengthX;
	while (brth.lengthX--)
	{
		line.col = gradient(col_start, col_end, len_x, brth.lengthX);
		mlx_pixel_put(line.mlx_p, line.mlx_nw, brth.x, brth.y, line.col);
		if (brth.d1 > 0)
		{
			brth.y += brth.y_inc;
			brth.d1 -= brth.dx2;
		}
		if (brth.d2 > 0)
		{
			brth.z += brth.z_inc;
			brth.d2 -= brth.dx2;
		}
		brth.d1 += brth.dy2;
		brth.d2 += brth.dz2;
		brth.x += brth.x_inc;
	}
}

static void		pix_put_y(t_coords line, t_breth brth, int col_start, int col_end)
{
	int		len_y;

	len_y = brth.lengthY;
	brth.d1 = brth.dx2 - brth.lengthY;
	brth.d2 = brth.dz2 - brth.lengthY;
	while (brth.lengthY--)
	{
		line.col = gradient(col_start, col_end, len_y, brth.lengthY);
		mlx_pixel_put(line.mlx_p, line.mlx_nw, brth.x, brth.y, line.col);
		if (brth.d1 > 0)
		{
			brth.x += brth.x_inc;
			brth.d1 -= brth.dy2;
		}
		if (brth.d2 > 0)
		{
			brth.z += brth.z_inc;
			brth.d2 -= brth.dy2;
		}
		brth.d1 += brth.dx2;
		brth.d2 += brth.dz2;
		brth.y += brth.y_inc;
	}
}

static void		pix_put_z(t_coords line, t_breth brth, int col_start, int col_end)
{
	int		len_z;

	len_z = brth.lengthZ;
	brth.d1 = brth.dy2 - brth.lengthZ;
	brth.d2 = brth.dx2 - brth.lengthZ;
	while (brth.lengthZ--)
	{
		line.col = gradient(col_start, col_end, len_z, brth.lengthZ);
		mlx_pixel_put(line.mlx_p, line.mlx_nw, brth.x, brth.y, line.col);
		if (brth.d1 > 0)
		{
			brth.y += brth.y_inc;
			brth.d1 -= brth.dz2;
		}
		if (brth.d2 > 0)
		{
			brth.x += brth.x_inc;
			brth.d2 -= brth.dz2;
		}
		brth.d1 += brth.dy2;
		brth.d2 += brth.dx2;
		brth.z += brth.z_inc;
	}
}

void			draw_a_line(t_coords line, t_dot start, t_dot end)
{
	t_breth		brth;

	brth.dx = end.x - start.x;
	brth.dy = end.y - start.y;
	brth.dz = end.z - start.z;
	brth.lengthX = abs(brth.dx);
	brth.lengthY = abs(brth.dy);
	brth.lengthZ = abs(brth.dz);
	brth.x_inc = (brth.dx < 0) ? -1 : 1;
	brth.y_inc = (brth.dy < 0) ? -1 : 1;
	brth.z_inc = (brth.dz < 0) ? -1 : 1;
	brth.length = fmax((float)brth.lengthX, (float)brth.lengthY) + 1;
	brth.x = start.x;
	brth.y = start.y;
	brth.z = start.z;
	brth.dx2 = brth.lengthX << 1;
	brth.dy2 = brth.lengthY << 1;
	brth.dz2 = brth.lengthZ << 1;
	if ((brth.lengthX >= brth.lengthY) && (brth.lengthX >= brth.lengthZ))
		pix_put_x(line, brth, start.col, end.col);
	else if ((brth.lengthY >= brth.lengthX) && (brth.lengthY >= brth.lengthZ))
		pix_put_y(line, brth, start.col, end.col);
	else
		pix_put_z(line, brth, start.col, end.col);
	mlx_pixel_put(line.mlx_p, line.mlx_nw, brth.x, brth.y, line.col);
}
