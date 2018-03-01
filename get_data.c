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

static char		*colour_deal(char *all_line, int col_start, int col_end)
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

int				get_array_size(char *all_line)
{
	int				i;
	t_chk_data		chk;

	printf("%s\n", all_line);
	i = 0;
	chk.check_space = 0;
	chk.count_num = 0;
	chk.check_num = 0;
	while (all_line[i])
	{
		if (all_line[i] != '\n' && all_line[i] != ' ' && all_line[i] != '-'
		&& !(ft_isdigit(all_line[i])))
			return (0);
		while (all_line[i] == ' ')
		{
			printf("here\n");
			chk.check_space = 1;
			i++;
		}
		while (ft_isdigit(all_line[i]) && (chk.check_num = 1))
			i++;
		if (chk.check_num)
		{
			chk.count_num++;
			chk.check_num = 0;
		}
		if (all_line[i] == ',')
		{
			while (all_line[i] != ' ')
				i++;
		}
		i++;
	}
	printf("%i\n", chk.check_space);
	if (!chk.check_space)
		return (0);
	printf("%i\n", chk.count_num);
	return (1);
}

int				**read_the_map(int fd)
{
	t_data	data;
	int		i;
	int		array_size;
	int		**coord_arr;

	i = 0;
	data = get_all_data(fd);
	if (!(array_size = get_array_size(data.all_line)))
		return (0);
	while (data.all_line[i])
	{
		data.temp_size = 0;
		if (data.all_line[i] == ',')
		{
			i += 3;
			data.temp_start = i;
			while (data.all_line[i] != ' ')
			{
				i++;
				data.temp_size++;
			}
			if (!(data.all_line = colour_deal(data.all_line, data.temp_start - 3, i)))
				return (NULL);
			i -= data.temp_size + 3;
		}
		i++;
	}
	printf("%s\n", data.all_line);
	return (NULL);
}
