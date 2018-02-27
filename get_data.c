/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:56:22 by akulaiev          #+#    #+#             */
/*   Updated: 2018/02/27 18:56:25 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

char	**read_the_map(int fd)
{
	char	*read_line;
	// char	*all_line;
	// char	**coord_line;
	int		i;

	i = 0;
	get_next_line(fd, &read_line);
	while (get_next_line(fd, &read_line))
		printf("%s\n", read_line);
	return (0);
}
