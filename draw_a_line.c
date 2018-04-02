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

int		absolute(int i)
{
	if (i < 0)
		i *= (-1);
	return (i);

	// return i < 0 ? -1 * i : i;
}

void	put_pix_3D(t_minlx line, int x, int y, int z)
{
	y = y * cos(0.25) - x * sin(0.25);
	x = y * sin(0.25) + x * cos(0.25);
	z = z * cos(0.25) - y * sin(0.25);
	y = z * sin(0.25) + y * cos(0.25);
	z = z * cos(0.25) - x * sin(0.25);
	x = z * sin(0.25) + x * cos(0.25);

	x += 50;
	y += 150;
	mlx_pixel_put(line.mlx_p, line.mlx_nw, x, y, line.col);
}

void			pix_put_X(t_minlx line, t_breth brth)
{
	brth.d1 = brth.dy2 - brth.lengthX;
	brth.d2 = brth.dz2 - brth.lengthX;
	while (brth.lengthX--)
	{
		put_pix_3D(line, brth.x, brth.y, brth.z);
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

void			pix_put_Y(t_minlx line, t_breth brth)
{
	brth.d1 = brth.dx2 - brth.lengthY;
	brth.d2 = brth.dz2 - brth.lengthY;
	while (brth.lengthY--)
	{
		put_pix_3D(line, brth.x, brth.y, brth.z);
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

void			pix_put_Z(t_minlx line, t_breth brth)
{
	brth.d1 = brth.dy2 - brth.lengthZ;
	brth.d2 = brth.dx2 - brth.lengthZ;
	while (brth.lengthZ--)
	{
		put_pix_3D(line, brth.x, brth.y, brth.z);
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

void			draw_a_line(t_minlx line, t_dot start, t_dot end)
{
	t_breth	 brth;

	brth.dx = end.x - start.x;
	brth.dy = end.y - start.y;
	brth.dz = end.z - start.z;
	brth.lengthX = absolute(brth.dx);
	brth.lengthY = absolute(brth.dy);
	brth.lengthZ = absolute(brth.dz);
	brth.x_inc = (brth.dx < 0) ? -1 : 1;
	brth.y_inc = (brth.dy < 0) ? -1 : 1;
	brth.z_inc = (brth.dz < 0) ? -1 : 1;
	brth.length = fmax((float)brth.lengthX, (float)brth.lengthY) + 1;
	brth.x = start.x;
	brth.y = start.y;
	brth.z = start.z;
	brth.dx2 = brth.lengthX * 2;
	brth.dy2 = brth.lengthY * 2;
	brth.dz2 = brth.lengthZ * 2;
	if ((brth.lengthX >= brth.lengthY) && (brth.lengthX >= brth.lengthZ))
		pix_put_X(line, brth);
	else if ((brth.lengthY >= brth.lengthX) && (brth.lengthY >= brth.lengthZ))
		pix_put_Y(line, brth);
	else
		pix_put_Z(line, brth);
	put_pix_3D(line, brth.x, brth.y, brth.z);
}
