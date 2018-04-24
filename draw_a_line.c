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

static int		gradient(int col)

static void		pix_put_x(t_coords line, t_breth brth)
{
	brth.d1 = brth.dy2 - brth.lengthX;
	brth.d2 = brth.dz2 - brth.lengthX;
	while (brth.lengthX--)
	{
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

static void		pix_put_y(t_coords line, t_breth brth)
{
	brth.d1 = brth.dx2 - brth.lengthY;
	brth.d2 = brth.dz2 - brth.lengthY;
	while (brth.lengthY--)
	{
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

static void		pix_put_z(t_coords line, t_breth brth)
{
	brth.d1 = brth.dy2 - brth.lengthZ;
	brth.d2 = brth.dx2 - brth.lengthZ;
	while (brth.lengthZ--)
	{
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
		pix_put_x(line, brth);
	else if ((brth.lengthY >= brth.lengthX) && (brth.lengthY >= brth.lengthZ))
		pix_put_y(line, brth);
	else
		pix_put_z(line, brth);
	mlx_pixel_put(line.mlx_p, line.mlx_nw, brth.x, brth.y, line.col);
}
