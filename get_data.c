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
	int		res;

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

static int		check_sp(char *no_col_line, int i, int j)
{
	t_chk_sp	chk;

	chk.line_split = ft_strsplit(no_col_line, '\n');
	chk.count_sp = 0;
	while (chk.line_split[0][j])
	{
		if (chk.line_split[0][j] == ' ')
			chk.count_sp++;
		j++;
	}
	while (chk.line_split[i])
	{
		j = 0;
		chk.count_sp_temp = 0;
		while (chk.line_split[i][j])
		{
			if (chk.line_split[i][j] == ' ')
				chk.count_sp_temp++;
			j++;
		}
		if (chk.count_sp != chk.count_sp_temp)
			return (0);
		i++;
	}
	return (chk.count_sp);
}

static int		check_lt(char *no_col_line, int i, int j)
{
	while (no_col_line[i])
	{
		if (ft_isalpha(no_col_line[i]))
			return (0);
		i++;
	}
	return (1);
}

static int		count_line_num(char **temp_str, int i)
{
	int		j;
	int		check_num;
	int		count_num;

	check_num = 0;
	count_num = 0;
	j = 0;
	while (temp_str[i][j])
	{
		while (ft_isdigit(temp_str[i][j]))
		{
			check_num = 1;
			j++;
		}
		if (check_num)
		{
			count_num++;
			check_num = 0;
		}
		j++;
	}
	return (count_num);
}

t_chk_num				get_array_size(char *no_col_line)
{
	t_chk_num	chk;
	int			j;
	int			check_num;

	if ((!(check_sp(no_col_line, 0, 1))) || (!(check_lt(no_col_line, 0, 0))))
		chk.count_num_first = 0;
	chk.temp_str = ft_strsplit(no_col_line, '\n');
	chk.count_num_first = count_line_num(chk.temp_str, 0);
	chk.i = 1;
	check_num = 0;
	j = 0;
	while (chk.temp_str[chk.i])
	{
		chk.count_num_temp = count_line_num(chk.temp_str, chk.i);
		if (chk.count_num_first != chk.count_num_temp)
			chk.count_num_first = 0;
		chk.i++;
	}
	return (chk);
}

char			*no_colour(char *no_col, int i)
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

int		**arr_memalloc(int size_x, int size_y)
{
	int		i;
	int		**mem;	

	i = 0;
	if ((mem = (int **)malloc(sizeof(int*) * size_x)))
	{
		while (i < size_y)
		{
			if ((mem[i] = ft_memalloc(sizeof(int))))
				i++;
		}
		return (mem);
	}
	return (NULL);
}

int			get_col_array(char *split_nl, int j, int base)
{
	int		res;

	while (split_nl[j] != ' ' || split_nl[j] != 'x')
		j++;
	if (split_nl[j] != ' ')
		return (0);
	if (split_nl[j] != 'x')
		res = ft_atoi_base(&split_nl[j + 1], base);
	return (res);
}

int			**get_array(char *line, int size_x, int size_y, int base)
{
	t_coords	res_coord;
	t_iter		indx;

	if (!(res_coord.coord_arr = arr_memalloc(size_x, size_y)))
		return (res_coord.coord_arr);
	indx.split_nl = ft_strsplit(line, '\n');
	indx.i = 0;
	indx.i1 = 0;
	while (indx.split_nl[indx.i])
	{
		indx.j = 0;
		indx.j1 = 0;
		while (indx.split_nl[indx.i][indx.j])
		{
			if (base == 10)
				res_coord.coord_arr[indx.i1][indx.j1] = ft_atoi_base(&indx.split_nl[indx.i][indx.j], base);
			if (base == 16)
			{
				res_coord.col_arr[indx.i1][indx.j1] = get_col_array(indx.split_nl[indx.i], indx.j, base);
				printf("%i\n", res_coord.col_arr[indx.i1][indx.j1]);
			}
			indx.j1++;
			while (indx.split_nl[indx.i][indx.j] && indx.split_nl[indx.i][indx.j] != ' ')
				indx.j++;
			indx.j++;
		}
		indx.i++;
		indx.i1++;
	}
	if (base == 10)
		return (res_coord.coord_arr);
	else
		return (res_coord.col_arr);
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
	if (!(res.coord_arr = get_array(data.no_col, sizes.count_num_first, sizes.i, 10)))
		data.error = 0;
	if (!(res.col_arr = get_array(data.all_line, sizes.count_num_first, sizes.i, 16)))
		data.error = 0;
	data.error = 1;
	return (data);
}
