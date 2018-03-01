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

int			main(int argc, char **argv)
{
	int		fd;
	
	if (argc != 2)
	{
		ft_putendl("usage: ./fdf 42.fdf");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(read_the_map(fd)))
	{
		ft_putendl("An error occured");
		return (0);
	}
	// manipulate_window();
	return(1);
}
