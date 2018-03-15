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

/*
static void		manipulate_window()
{
	void	*mlx_p;
	void	*mlx_nw;

	mlx_p = mlx_init();
	mlx_nw = mlx_new_window(mlx_p, 713, 713, "test_window");
	set_coord(mlx_p, mlx_nw);
	mlx_key_hook(mlx_nw, key_react, (void*)0);
	mlx_loop(mlx_p);
}
*/

int			main(int argc, char **argv)
{
	int			fd;
	t_chk_num	sizes;
	t_coords	coords;

	if (argc != 2)
	{
		ft_putendl("usage: ./fdf 42.fdf");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putendl("An error occured");
		return (0);
	}
	sizes = read_the_map(fd);
	if (!(sizes.er))
	{
		ft_putendl("An error occured");
		return (0);
	}
	coords.coord_arr = get_coord(sizes.temp_str, sizes.count_num_first, sizes.i);
	coords.col_arr = get_col(sizes, 0, 0);
	if (!(coords.coord_arr) || !(coords.col_arr))
	{
		ft_putendl("An error occured");
		return (0);
	}
	print_arr(coords.coord_arr, sizes.count_num_first, sizes.i);
	print_arr(coords.col_arr, sizes.count_num_first, sizes.i);
	// manipulate_window();
	system("leaks fdf");
	return (1);
}
