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

static int	check_sp(t_data *chk, int i, int j)
{
	t_chk_sp	sps;

	sps.count_sp = 0;
	while (chk->no_c[0][j])
	{
		if (chk->no_c[0][j] == ' ')
			sps.count_sp++;
		j++;
	}
	while (i < chk->num_lines)
	{
		j = 0;
		sps.count_sp_temp = 0;
		while (j < (int)(ft_strlen(chk->no_c[i])))
		{
			if (chk->no_c[i][j] == ' ')
				sps.count_sp_temp++;
			j++;
		}
		if (sps.count_sp != sps.count_sp_temp)
			return (0);
		i++;
	}
	return (sps.count_sp);
}

static int	check_lt(t_data *chk, int i)
{
	int		j;

	while (i < chk->num_lines)
	{
		j = 0;
		while (j < (int)(ft_strlen(chk->no_c[i])))
		{
			if (ft_isalpha(chk->no_c[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	count_line_num(char *temp_str)
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

int			get_array_size(t_data *dt)
{
	int			j;
	int			check_num;

	if ((!(check_sp(dt, 0, 1))) || (!(check_lt(dt, 0))))
		dt->count_num_first = 0;
	dt->count_num_first = count_line_num(dt->no_c[0]);
	dt->i = 1;
	check_num = 0;
	j = 0;
	while (dt->i < dt->num_lines)
	{
		dt->count_num_temp = count_line_num(dt->no_c[dt->i]);
		if (dt->count_num_first != dt->count_num_temp)
		{
			dt->count_num_first = 0;
			return (1);
		}
		dt->i++;
	}
	return (0);
}
