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

static char		**ft_realloc_2d(char **line, int old)
{
	char	**new_mem;
	int		i;

	i = 0;
	if (!line || !old)
		return ((char**)ft_memalloc(sizeof(char*)));
	new_mem = (char**)ft_memalloc(sizeof(char*) * old + 1);
	while (i < old)
	{
		new_mem[i] = line[i];
		i++;
	}
	free(line);
	return (new_mem);
}

static void		get_all_data(int fd, t_data *dt)
{
	char	*read_line;

	read_line = NULL;
	dt->aln = NULL;
	dt->num_lines = 0;
	while (get_next_line(fd, &read_line))
	{
		dt->aln = ft_realloc_2d(dt->aln, dt->num_lines);
		dt->aln[dt->num_lines] = read_line;
		dt->num_lines++;
	}
}

char			*separate_arrays_help(char *aln, int j)
{
	int		k;
	int		c_end;
	char	*no_c;

	k = 0;
	if ((no_c = (char*)malloc(ft_strlen(aln) + 1)))
	{
		while (aln[j])
		{
			if (aln[j] == ',' && aln[j + 1] == '0'
			&& aln[j + 2] == 'x')
			{
				c_end = j;
				while (aln[c_end] != ' ' && aln[c_end])
					c_end++;
				j = c_end;
			}
			no_c[k] = aln[j];
			j++;
			k++;
		}
		no_c[k] = '\0';
	}
	return (no_c);
}

void			separate_arrays(t_data *dt)
{
	int		i;
	int		j;

	if ((dt->no_c = (char**)malloc(sizeof(char*) * dt->num_lines)))
	{
		i = 0;
		while (i < dt->num_lines)
		{
			j = 0;
			dt->no_c[i] = separate_arrays_help(dt->aln[i], j);
			i++;
		}
	}
}

t_data			read_the_map(int fd)
{
	t_data		dt;

	get_all_data(fd, &dt);
	if ((!(dt.aln)))
	{
		dt.er = 0;
		return (dt);
	}
	separate_arrays(&dt);
	if ((get_array_size(&dt) != 0) || !(dt.i) || !(dt.count_num_first))
	{
		dt.er = 0;
		return (dt);
	}
	dt.er = 1;
	dt.col_flag = 0;
	return (dt);
}
