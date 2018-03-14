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

static char		*colour_del(char *all_line, int col_start, int col_end)
{
	char	*temp_str;

	if (!(temp_str = (char *)ft_memalloc(ft_strlen(all_line))))
		return (NULL);
	ft_strncpy(temp_str, all_line, col_start);
	ft_strcat(temp_str, &all_line[col_end]);
	return (temp_str);
}

static t_data	get_all_data(int fd)
{
	t_data	data;

	data.all_line = NULL;
	data.read_line = NULL;
	while (get_next_line(fd, &data.read_line))
	{
		if ((data.all_line = ft_realloc(data.all_line, ft_strlen(data.all_line),
		(ft_strlen(data.read_line) + 1 + ft_strlen(data.all_line)))))
		{
			ft_strcat(data.all_line, data.read_line);
			ft_strcat(data.all_line, "\n");
		}
	}
	return (data);
}

static char			*no_colour(char *no_col, int i)
{
	int		temp_size;
	int 	temp_start;

	while (no_col[i])
	{
		temp_size = 0;
		if (no_col[i] == ',')
		{
			i += 3;
			temp_start = i;
			while (no_col[i] != ' ')
			{
				i++;
				temp_size++;
			}
			if (!(no_col = colour_del(no_col, temp_start - 3, i)))
				return (NULL);
			i -= temp_size + 3;
		}
		i++;
	}
	return (no_col);
}

t_data				read_the_map(int fd)
{
	t_data		data;
	t_chk_num	sizes;
	t_coords	res;
	
	data = get_all_data(fd);
	if (!(data.all_line))
		return (data);
	if (!(data.no_col = (char *)ft_memalloc(ft_strlen(data.all_line) + 1)))
	{
		data.error = 0;
		return (data);
	}
	ft_strcpy(data.no_col, data.all_line);
	data.no_col = no_colour(data.no_col, 0);
	sizes = get_array_size(data.no_col);
	if (!(sizes.i) || !(sizes.count_num_first))
	{
		data.error = 0;
		return (data);
	}
	if (!(res.coord_arr = get_coord_array(data.no_col, sizes.count_num_first, sizes.i)))
		data.error = 0;
	if (!(res.col_arr = get_col_array(data.all_line, sizes.count_num_first, sizes.i)))
		data.error = 0;
	print_arr(res.coord_arr, sizes.count_num_first, sizes.i);
	print_arr(res.col_arr, sizes.count_num_first, sizes.i);
	data.error = 1;
	return (data);
}
