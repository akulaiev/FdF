/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:32:46 by akulaiev          #+#    #+#             */
/*   Updated: 2018/03/14 16:32:47 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static int		check_lt(char *no_col_line, int i)
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

t_chk_num		get_array_size(char *no_col_line)
{
	t_chk_num	chk;
	int			j;
	int			check_num;

	if ((!(check_sp(no_col_line, 0, 1))) || (!(check_lt(no_col_line, 0))))
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
