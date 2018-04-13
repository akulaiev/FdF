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

void	put_line(t_coords src, t_minlx win, t_dot start, t_dot end)
{
	start = enlarge(start, src.сoeff);
	end = enlarge(end, src.сoeff);
	start = turn(start, 0.7);
	end = turn(end, 0.7);
	start = centre(start, src.shift_right, src.shift_down);
	end = centre(end, src.shift_right, src.shift_down);
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
	put_line(src, win, start, end);
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
	put_line(src, win, start, end);
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
	t_data		sz;
	t_coords	coords;
	t_minlx		win;

	if (argc != 2)
		return (write(2, "Error: no argument\n", 19));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Error: problem with file\n", 25));
	sz = read_the_map(fd);
	if (!sz.er)
		return (write(2, "Error: wrong number of params in line\n", 38));
	coords.size_x = sz.count_num_first;
	coords.size_y = sz.i;
	coords.coord_arr = get_coord(sz.no_c, coords.size_x, coords.size_y);
	coords.col_arr = get_col(sz, 0, 0);
	if (!(coords.coord_arr) || !(coords.col_arr))
		return (write(2, "Error: problem with arrays of coords\n", 37));
	// print_arr(coords.col_arr, coords.size_x, coords.size_y);
	// print_arr(coords.coord_arr, coords.size_x, coords.size_y);
	// system("leaks fdf");
	win = manipulate_window(&coords);
	mlx_key_hook(win.mlx_nw, key_react, (void*)0);
	set_coord(coords, win, 0, 0);
	mlx_loop(win.mlx_p);
	return (0);
}
