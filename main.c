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

void	put_line(t_coords src, t_dot start, t_dot end)
{
	start = enlarge(start, src.сoeff);
	end = enlarge(end, src.сoeff);
	start = turn_x(start, src.angle_x);
	end = turn_x(end, src.angle_x);
	start = turn_y(start, src.angle_y);
	end = turn_y(end, src.angle_y);
	start = turn_z(start, src.angle_z);
	end = turn_z(end, src.angle_z);
	start = move(start, src.shift_right, src.shift_down);
	end = move(end, src.shift_right, src.shift_down);
	draw_a_line(src, start, end);
}

void	put_line_right(int i, int j, t_coords src)
{
	t_dot start;
	t_dot end;

	start.x = j;
	start.y = i;
	start.z = src.coord_arr[i][j];
	start.col = src.col_arr[i][j];
	end.x = j + 1;
	end.y = i;
	end.z = src.coord_arr[i][j + 1];
	end.col = src.col_arr[i][j + 1];
	put_line(src, start, end);
}

void	put_line_down(int i, int j, t_coords src)
{
	t_dot start;
	t_dot end;

	start.x = j;
	start.y = i;
	start.z = src.coord_arr[i][j];
	start.col = src.col_arr[i][j];
	end.x = j;
	end.y = i + 1;
	end.z = src.coord_arr[i + 1][j];
	end.col = src.col_arr[i + 1][j];
	put_line(src, start, end);
}

void	set_coord(t_coords src, int i, int j)
{
	mlx_string_put(src.mlx_p, src.mlx_nw, 10, 30, 0x42f4d9,
	"Use '+' and '-' to scale the picture, arrows to move it around");
	mlx_string_put(src.mlx_p, src.mlx_nw, 10, 50, 0x42f4d9,
		"and 'w', 's', 'a', 'd', 'q', 'e' for rotations.");
	while (i < src.size_y)
	{
		j = 0;
		while (j < src.size_x)
		{
			if (j < src.size_x - 1)
				put_line_right(i, j, src);
			else
				put_line_right(i, j - 1, src);
			if (i < src.size_y - 1)
				put_line_down(i, j, src);
			else
				put_line_down(i - 1, j, src);
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int			fd;
	t_data		sz;
	t_coords	coords;

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
	coords.col_arr = get_col(sz, 0);
	if (!(coords.coord_arr) || !(coords.col_arr))
		return (write(2, "Error: problem with arrays of coords\n", 37));
	manipulate_window(&coords);
	mlx_string_put(coords.mlx_p, coords.mlx_nw, 10, 10, 0x42f4d9,
	"Hi! Enjoy exploring my FdF project!!!");
	mlx_hook(coords.mlx_nw, 2, 5, key_react, (void*)&coords);
	set_coord(coords, 0, 0);
	mlx_loop(coords.mlx_p);
	return (0);
}
