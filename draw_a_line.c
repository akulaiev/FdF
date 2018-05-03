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

static int		gradient(int cs, int ce, int line_len, int pix_dist)
{
	t_gradient	g;

	g.start_r = (cs >> 16) & 255;
	g.start_g = (cs >> 8) & 255;
	g.start_b = cs & 255;
	g.end_r = (ce >> 16) & 255;
	g.end_g = (ce >> 8) & 255;
	g.end_b = ce & 256;
	if (cs > ce)
	{
		g.res_r = g.start_r - (g.start_r - g.end_r) / line_len * pix_dist;
		g.res_g = g.start_g - (g.start_g - g.end_g) / line_len * pix_dist;
		g.res_b = g.start_b - (g.start_b - g.end_b) / line_len * pix_dist;
	}
	else
	{
		g.res_r = g.start_r + (g.end_r - g.start_r) / line_len * pix_dist;
		g.res_g = g.start_g + (g.end_g - g.start_g) / line_len * pix_dist;
		g.res_b = g.start_b + (g.end_b - g.start_b) / line_len * pix_dist;
	}
	return ((g.res_r << 16) + (g.res_g << 8) + g.res_b);
}

static void		pix_put_x(t_coords line, t_breth brth, int cs, int ce)
{
	brth.i = 0;
	brth.len_x = brth.leng_x;
	brth.d1 = brth.dy2 - brth.leng_x;
	brth.d2 = brth.dz2 - brth.leng_x;
	while (brth.leng_x--)
	{
		line.col = gradient(cs, ce, brth.len_x, brth.i);
		brth.i++;
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

static void		pix_put_y(t_coords line, t_breth brth, int cs, int ce)
{
	brth.i = 0;
	brth.len_y = brth.leng_y;
	brth.d1 = brth.dx2 - brth.leng_y;
	brth.d2 = brth.dz2 - brth.leng_y;
	while (brth.leng_y--)
	{
		line.col = gradient(cs, ce, brth.len_y, brth.i);
		brth.i++;
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

static void		pix_put_z(t_coords line, t_breth brth, int cs, int ce)
{
	brth.i = 0;
	brth.len_z = brth.leng_z;
	brth.d1 = brth.dy2 - brth.leng_z;
	brth.d2 = brth.dx2 - brth.leng_z;
	while (brth.leng_z--)
	{
		line.col = gradient(cs, ce, brth.len_z, brth.i);
		brth.i++;
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
	brth.leng_x = abs(brth.dx);
	brth.leng_y = abs(brth.dy);
	brth.leng_z = abs(brth.dz);
	brth.x_inc = (brth.dx < 0) ? -1 : 1;
	brth.y_inc = (brth.dy < 0) ? -1 : 1;
	brth.z_inc = (brth.dz < 0) ? -1 : 1;
	brth.length = fmax((float)brth.leng_x, (float)brth.leng_y) + 1;
	brth.x = start.x;
	brth.y = start.y;
	brth.z = start.z;
	brth.dx2 = brth.leng_x << 1;
	brth.dy2 = brth.leng_y << 1;
	brth.dz2 = brth.leng_z << 1;
	if ((brth.leng_x >= brth.leng_y) && (brth.leng_x >= brth.leng_z))
		pix_put_x(line, brth, start.col, end.col);
	else if ((brth.leng_y >= brth.leng_x) && (brth.leng_y >= brth.leng_z))
		pix_put_y(line, brth, start.col, end.col);
	else
		pix_put_z(line, brth, start.col, end.col);
	mlx_pixel_put(line.mlx_p, line.mlx_nw, brth.x, brth.y, line.col);
}
