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
	param = NULL;
	if (keycode == 53)
		exit(0);
	return (0);
}
