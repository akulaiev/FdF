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

static t_minlx	manipulate_window(void)
{
	t_minlx	win;

	win.mlx_p = mlx_init();
	win.mlx_nw = mlx_new_window(win.mlx_p, 713, 713, "test_window");
	return (win);
}

t_dot	turn(t_dot dot, double angle)
{
	t_dot 	res;
	double	cos_angle;
	double	sin_angle;

	sin_angle = sin(angle);
	cos_angle = cos(angle);
	res.y = dot.y * cos_angle - dot.x * sin_angle;
	res.x = dot.y * sin_angle + dot.x * cos_angle;
	res.z = dot.z * cos_angle - dot.y * sin_angle;
	res.y = dot.z * sin_angle + dot.y * cos_angle;
	res.z = dot.z * cos_angle - dot.x * sin_angle;
	res.x = dot.z * sin_angle + dot.x * cos_angle;
	return (res);
}

t_dot	enlarge(t_dot dot, int size)
{
	t_dot res;

	res.x = dot.x * size;
	res.y = dot.y * size;
	res.z = dot.z * size;
	return (res);
}

t_dot	shift(t_dot dot, int shift_right, int shift_down)
{
	t_dot res;

	res.x = dot.x + shift_right;
	res.y = dot.y + shift_down;
	return (res);
}

void	put_line(t_minlx win, t_dot start, t_dot end)
{
	start = enlarge(start, 25);
	end = enlarge(end, 25);
	start = turn(start, 0.7);
	end = turn(end, 0.7);
	start = shift(start, 100, 350);
	end = shift(end, 100, 350);
	draw_a_line(win, start, end);
}

void	put_line_right(t_minlx win, int i, int j, t_coords src)
{
	t_dot start;
	t_dot end;

	start.x = j;
	start.y = i;
	start.z = src.coord_arr[i][j];
	end.x = j + 1;
	end.y = i;
	end.z = src.coord_arr[i][j + 1];
	put_line(win, start, end);
}

void	put_line_down(t_minlx win, int i, int j, t_coords src)
{
	t_dot start;
	t_dot end;

	start.x = j;
	start.y = i;
	start.z = src.coord_arr[i][j];
	end.x = j;
	end.y = i + 1;
	end.z = src.coord_arr[i + 1][j];
	put_line(win, start, end);
}

void	set_coord(t_coords src, t_minlx win, int i, int j)
{
	while (i < src.size_y)
	{
		j = 0;
		while (j < src.size_x)
		{
			if (!src.col_arr[i][j])
				win.col = 0xffffff;
			else
				win.col = src.col_arr[i][j];
			if (j < src.size_x - 1)
				put_line_right(win, i, j, src);
			else
				put_line_right(win, i, j - 1, src);
			if (i < src.size_y - 1)
				put_line_down(win, i, j, src);
			else
				put_line_down(win, i - 1, j, src);
			j++;
		}
		i++;
	}
}

int				main(int argc, char **argv)
{
	int			fd;
	t_chk_num	sz;
	t_coords	coords;
	t_minlx		win;

	if (argc != 2)
		return (write(2, "Error: no argument\n", 19));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Error: problem with file\n", 25));
	sz = read_the_map(fd);
	if (!(sz.er))
		return (write(2, "Error: wrong number of params in line\n", 38));
	coords.coord_arr = get_coord(sz.temp_str, sz.count_num_first, sz.i);
	coords.col_arr = get_col(sz, 0, 0);
	coords.size_x = sz.count_num_first;
	coords.size_y = sz.i;
	if (!(coords.coord_arr) || !(coords.col_arr))
		return (write(2, "Error: problem with arrays of coords\n", 37));
	// system("leaks fdf");
	win = manipulate_window();
	mlx_key_hook(win.mlx_nw, key_react, (void*)0);
	set_coord(coords, win, 0, 0);
	mlx_loop(win.mlx_p);
	return (0);
}
