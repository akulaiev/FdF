/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_transformation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:00:17 by akulaiev          #+#    #+#             */
/*   Updated: 2018/04/12 16:00:21 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_dot	turn_x(t_dot dot, double angle)
{
	t_dot	res;
	double	cos_angle;
	double	sin_angle;

	sin_angle = sin(angle);
	cos_angle = cos(angle);
	res.x = dot.x;
	res.y = dot.y * cos_angle + dot.z * sin_angle;
	res.z = -dot.y * sin_angle + dot.z * cos_angle;
	return (res);
}

t_dot	turn_y(t_dot dot, double angle)
{
	t_dot	res;
	double	cos_angle;
	double	sin_angle;

	sin_angle = sin(angle);
	cos_angle = cos(angle);
	res.x = dot.x * cos_angle + dot.z * sin_angle;
	res.y = dot.y;
	res.z = -dot.x * sin_angle + dot.z * cos_angle;
	return (res);
}

t_dot	turn_z(t_dot dot, double angle)
{
	t_dot	res;
	double	cos_angle;
	double	sin_angle;

	sin_angle = sin(angle);
	cos_angle = cos(angle);
	res.x = dot.x * cos_angle - dot.y * sin_angle;
	res.y = dot.x * sin_angle + dot.y * cos_angle;
	res.z = dot.z * cos_angle - dot.x * sin_angle;
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

t_dot	move(t_dot dot, int shift_right, int shift_down)
{
	t_dot res;

	res.x = dot.x + shift_right;
	res.y = dot.y + shift_down;
	return (res);
}
