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
#include <stdio.h>

static int		check_sp(t_chk_num chk, int i, int j)
{
	t_chk_sp	sps;

	sps.count_sp = 0;
	while (chk.temp_str[0][j])
	{
		if (chk.temp_str[0][j] == ' ')
			sps.count_sp++;
		j++;
	}
	while (chk.temp_str[i])
	{
		j = 0;
		sps.count_sp_temp = 0;
		while (chk.temp_str[i][j])
		{
			if (chk.temp_str[i][j] == ' ')
				sps.count_sp_temp++;
			j++;
		}
		if (sps.count_sp != sps.count_sp_temp)
			return (0);
		i++;
	}
	return (sps.count_sp);
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

static int		count_line_num(char *temp_str)
{
	int		i;
	int		check_num;
	int		count_num;

	check_num = 0;
	count_num = 0;
	i = 0;
	while (i < (int)ft_strlen(temp_str))
	{
		while (ft_isdigit(temp_str[i]))
		{
			check_num = 1;
			i++;
		}
		if (check_num)
		{
			count_num++;
			check_num = 0;
		}
		i++;
	}
	return (count_num);
}

t_chk_num		get_array_size(char *no_col_line, char *all_line)
{
	t_chk_num	chk;
	int			j;
	int			check_num;

	chk.temp_str = ft_strsplit(no_col_line, '\n');
	chk.tc = ft_strsplit(all_line, '\n');
	if ((!(check_sp(chk, 0, 1))) || (!(check_lt(no_col_line, 0))))
		chk.count_num_first = 0;
	chk.count_num_first = count_line_num(chk.temp_str[0]);
	chk.i = 1;
	check_num = 0;
	j = 0;
	while (chk.temp_str[chk.i])
	{
		chk.count_num_temp = count_line_num(chk.temp_str[chk.i]);
		if (chk.count_num_first != chk.count_num_temp)
		{
			chk.count_num_first = 0;
			return (chk);
		}
		chk.i++;
	}
	return (chk);
}
