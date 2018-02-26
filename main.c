/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:17:45 by akulaiev          #+#    #+#             */
/*   Updated: 2018/02/26 14:17:48 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int 	absolute(int i)
{
	if (i < 0)
		i *= (-1);
	return (i);
}

void 	draw_a_line(void *mlx_p, void *mlx_nw, int x0, int x1, int y0, int y1)
{
	int 	tilt;
	int 	dir_y;
	int 	y;
	int 	x;

	y = y0;
	x = x0;
	tilt = 0;
	dir_y = y1 - y0;
	if (dir_y > 0)
		dir_y = 1;
	if (dir_y < 0)
		dir_y = -1;
	while (x >= x0 && x <= x1)
	{
		mlx_pixel_put(mlx_p, mlx_nw, x, y, 0xf442eb);
		tilt = tilt + absolute(y1 - y0);
		if ((tilt * 2) >= absolute(x1 - x0))
		{
			y += dir_y;
			tilt -= absolute(x1 - x0);
		}
		x++;
	}

}

int		main(void)
{
	void	*mlx_p;
	void	*mlx_nw;

	if (!(mlx_p = mlx_init()))
		return (0);
	if (!(mlx_nw = mlx_new_window(mlx_p, 713, 713, "test_window")))
		return (0);
	draw_a_line(mlx_p, mlx_nw, 0, 513, 0, 113);
	mlx_loop(mlx_p);
}
