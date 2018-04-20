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
	if (keycode <= 126 && keycode >= 123)
		pic_move(keycode, param);
	if (keycode == 69 || keycode == 24 || keycode == 78 || keycode == 27)
		pic_scale(keycode, param);
	if ((keycode >= 0 && keycode <= 2) || (keycode >= 12 && keycode <= 14))
		rotate(keycode, param);
	return (0);
}

void	pic_move(int keycode, void *param)
{
	mlx_clear_window(((t_coords*)param)->mlx_p, ((t_coords*)param)->mlx_nw);
	if (keycode == 126)
		((t_coords*)param)->shift_down -= 7;
	if (keycode == 125)
		((t_coords*)param)->shift_down += 7;
	if (keycode == 124)
		((t_coords*)param)->shift_right += 7;
	if (keycode == 123)
		((t_coords*)param)->shift_right -= 7;
	set_coord((*(t_coords*)param), 0, 0);
}

void	pic_scale(int keycode, void *param)
{
	mlx_clear_window(((t_coords*)param)->mlx_p, ((t_coords*)param)->mlx_nw);
	if (keycode == 69 || keycode == 24)
		((t_coords*)param)->сoeff += 1;
	if (keycode == 78 || keycode == 27)
		((t_coords*)param)->сoeff -= 1;
	set_coord((*(t_coords*)param), 0, 0);
}

void	rotate(int keycode, void *param)
{
	mlx_clear_window(((t_coords*)param)->mlx_p, ((t_coords*)param)->mlx_nw);
	if (keycode == 13)
		((t_coords*)param)->angle_x -= 0.17;
	if (keycode == 1)
		((t_coords*)param)->angle_x += 0.17;
	if (keycode == 2)
		((t_coords*)param)->angle_y += 0.17;
	if (keycode == 0)
		((t_coords*)param)->angle_y -= 0.17;
	if (keycode == 14)
		((t_coords*)param)->angle_z -= 0.17;
	if (keycode == 12)
		((t_coords*)param)->angle_z += 0.17;
	set_coord((*(t_coords*)param), 0, 0);
}
