/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:44:23 by akulaiev          #+#    #+#             */
/*   Updated: 2018/03/14 16:44:25 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int	**arr_memalloc(int size_x, int size_y)
{
	int		i;
	int		**mem;

	i = 0;
	if ((mem = (int **)malloc(sizeof(int*) * size_y)))
	{
		while (i < size_y)
		{
			if ((mem[i] = (int *)malloc(sizeof(int) * size_x)))
				i++;
		}
		return (mem);
	}
	return (NULL);
}

int			**get_col(t_data sz, int i, int i1)
{
	int		**col_arr;
	t_col	c;

	if (!(col_arr = arr_memalloc(sz.count_num_first, sz.i)))
		return (NULL);
	while (i1 < sz.i && sz.aln[i])
	{
		c.j = 0;
		c.j1 = 0;
		while (c.j1 < sz.count_num_first && sz.aln[i][c.j])
		{
			while (sz.aln[i][c.j] != ' ' && sz.aln[i][c.j] != 'x')
				c.j++;
			sz.aln[i][c.j] == ' ' ? col_arr[i1][c.j1] = 0xffffff : 0;
			if (sz.aln[i][c.j] == 'x')
				col_arr[i1][c.j1] = ft_atoi_base(&sz.aln[i][c.j + 1], 16);
			c.j++;
			c.j1++;
		}
		i++;
		i1++;
	}
	ft_double_free((void**)sz.aln, sz.i);
	return (col_arr);
}

int			**get_coord(char **split_nl, int size_x, int size_y)
{
	int		**coord_arr;
	char	**temp_arr;
	int		i;
	int		j;

	if (!(coord_arr = arr_memalloc(size_x, size_y)))
		return (NULL);
	i = 0;
	while (i < size_y)
	{
		temp_arr = ft_strsplit(split_nl[i], ' ');
		j = 0;
		while (j < size_x)
		{
			coord_arr[i][j] = ft_atoi(temp_arr[j]);
			j++;
		}
		ft_double_free((void**)temp_arr, size_x);
		i++;
	}
	ft_double_free((void**)split_nl, size_y);
	return (coord_arr);
}

void		print_arr(int **arr, int size_x, int size_y)
{
	int i;
	int j;

	i = 0;
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			printf("%i ", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}
