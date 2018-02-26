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

int		main(void)
{
	void	*mlx_p;
	void	*mlx_nw;

	if (!(mlx_p = mlx_init()))
		return (0);
	if (!(mlx_nw = mlx_new_window(mlx_p, 713, 713, "test_window")))
		return (0);
	mlx_string_put(mlx_p, mlx_nw, 13, 13, 0xf442eb, "Hello, World!");
	mlx_loop(mlx_p);
}
