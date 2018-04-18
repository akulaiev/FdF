/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:41:44 by akulaiev          #+#    #+#             */
/*   Updated: 2018/02/27 18:41:46 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		key_react(int keycode, void *param)
{
	printf("%i\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
	{
		mlx_clear_window(((t_coords*)param)->mlx_p, ((t_coords*)param)->mlx_nw);
		((t_coords*)param)->shift_down -= 7;
		set_coord((*(t_coords*)param), 0, 0);
	}
	if (keycode == 125)
	{
		mlx_clear_window(((t_coords*)param)->mlx_p, ((t_coords*)param)->mlx_nw);
		((t_coords*)param)->shift_down += 7;
		set_coord((*(t_coords*)param), 0, 0);
	}
	if (keycode == 124)
	{
		mlx_clear_window(((t_coords*)param)->mlx_p, ((t_coords*)param)->mlx_nw);
		((t_coords*)param)->shift_right += 7;
		set_coord((*(t_coords*)param), 0, 0);
	}
	if (keycode == 123)
	{
		mlx_clear_window(((t_coords*)param)->mlx_p, ((t_coords*)param)->mlx_nw);
		((t_coords*)param)->shift_right -= 7;
		set_coord((*(t_coords*)param), 0, 0);
	}
	if (keycode == 69 || keycode == 24)
	{
		mlx_clear_window(((t_coords*)param)->mlx_p, ((t_coords*)param)->mlx_nw);
		((t_coords*)param)->сoeff += 1;
		set_coord((*(t_coords*)param), 0, 0);
	}
	if (keycode == 78 || keycode == 27)
	{
		mlx_clear_window(((t_coords*)param)->mlx_p, ((t_coords*)param)->mlx_nw);
		((t_coords*)param)->сoeff -= 1;
		set_coord((*(t_coords*)param), 0, 0);
	}
	return (0);
}
