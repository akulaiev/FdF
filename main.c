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

static t_minlx	manipulate_window()
{
	t_minlx	win;

	win.mlx_p = mlx_init();
	win.mlx_nw = mlx_new_window(win.mlx_p, 713, 713, "test_window");
	return (win);
}

t_dot	turn(t_dot dot, double angle)
{
	t_dot res;

	res.x = dot.x * cos(angle) - dot.y * sin(angle);
	res.y = dot.x * sin(angle) + dot.y * cos(angle);
	return (res);
}

t_dot	enlarge(t_dot dot, int size)
{
	t_dot res;

	res.x = dot.x * size;
	res.y = dot.y * size;
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
	start = turn(start, 2.61799);
	end = turn(end, 2.61799);
	start = shift(start, 600, 350);
	end = shift(end, 600, 350);
	win.x0 = start.x;
	win.x1 = end.x;
	win.y0 = start.y;
	win.y1 = end.y;
	draw_a_line(win);
}

t_minlx	put_line_right(t_minlx win, int i, int j)
{
	t_dot start;
	t_dot end;

	start.x = j;
	start.y = i;
	end.x = j + 1;
	end.y = i;
	put_line(win, start, end);
	return (win);
}

t_minlx	put_line_down(t_minlx win, int i, int j)
{
	t_dot start;
	t_dot end;

	start.x = j;
	start.y = i;
	end.x = j;
	end.y = i + 1;
	put_line(win, start, end);
	return (win);
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
				win = put_line_right(win, i, j);
			else
				win = put_line_right(win, i, j - 1);
			if (i < src.size_y - 1)
				win = put_line_down(win, i, j);
			else
				win = put_line_down(win, i - 1, j);
			j++;
		}
		i++;
	}
}

int				main(int argc, char **argv)
{
	int			fd;
	t_chk_num	sizes;
	t_coords	coords;
	t_minlx		win;

	if (argc != 2)
		return (write(2, "An error occured\n", 17) && 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "An error occured\n", 17) && 1);
	sizes = read_the_map(fd);
	if (!(sizes.er))
		return (write(2, "An error occured\n", 17) && 1);
	coords.coord_arr = get_coord(sizes.temp_str, sizes.count_num_first, sizes.i);
	coords.col_arr = get_col(sizes, 0, 0);
	coords.size_x = sizes.count_num_first;
	coords.size_y = sizes.i;
	if (!(coords.coord_arr) || !(coords.col_arr))
	{
		ft_putendl("An error occured");
		return (0);
	}
	win = manipulate_window();
	mlx_key_hook(win.mlx_nw, key_react, (void*)0);
	set_coord(coords, win, 0, 0);
	mlx_loop(win.mlx_p);
	// system("leaks fdf");
	return (0);
}
