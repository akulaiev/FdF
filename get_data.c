/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:26:09 by akulaiev          #+#    #+#             */
/*   Updated: 2018/03/15 17:26:12 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static char		*colour_del(char *all_line_cp, int col_start, int col_end)
{
	char	*temp_str;

	if (!(temp_str = (char *)ft_memalloc(ft_strlen(all_line_cp))))
		return (NULL);
	ft_strncpy(temp_str, all_line_cp, col_start);
	ft_strcat(temp_str, &all_line_cp[col_end]);
	free(all_line_cp);
	return (temp_str);
}

static t_data	get_all_data(int fd)
{
	t_data	data;

	data.aln = NULL;
	data.read_line = NULL;
	while (get_next_line(fd, &data.read_line))
	{
		if ((data.aln = ft_realloc(data.aln, ft_strlen(data.aln),
		(ft_strlen(data.read_line) + 1 + ft_strlen(data.aln)))))
		{
			ft_strcat(data.aln, data.read_line);
			ft_strcat(data.aln, "\n");
		}
	}
	return (data);
}

static char		*no_colour(char *all_line_cp, int i)
{
	int		temp_size;
	int		temp_start;

	while (all_line_cp[i])
	{
		temp_size = 0;
		if (all_line_cp[i] == ',')
		{
			i += 3;
			temp_start = i;
			while (all_line_cp[i] != ' ')
			{
				i++;
				temp_size++;
			}
			if (!(all_line_cp = colour_del(all_line_cp, temp_start - 3, i)))
				return (NULL);
			i -= temp_size + 3;
		}
		i++;
	}
	return (all_line_cp);
}

t_chk_num		read_the_map(int fd)
{
	t_data		dt;
	t_chk_num	sz;

	dt = get_all_data(fd);
	if ((!(dt.aln) || !(dt.no_c = (char *)ft_memalloc(ft_strlen(dt.aln) + 1))))
	{
		sz.er = 0;
		return (sz);
	}
	ft_strcpy(dt.no_c, dt.aln);
	dt.no_c = no_colour(dt.no_c, 0);
	sz = get_array_size(dt.no_c, dt.aln);
	free(dt.no_c);
	free(dt.aln);
	if (!(sz.i) || !(sz.count_num_first))
	{
		sz.er = 0;
		return (sz);
	}
	sz.er = 1;
	return (sz);
}
