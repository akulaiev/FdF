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

int			**get_col(t_data *sz, int i)
{
	t_col	c;

	if (!(c.col_arr = arr_memalloc(sz->count_num_first, sz->i)))
		return (NULL);
	while (i < sz->i)
	{
		c.temp = ft_strsplit(sz->aln[i], ' ');
		c.x = -1;
		while (c.temp[++c.x])
		{
			c.y = -1;
			c.check = 0;
			while (c.temp[c.x][++c.y])
				if (c.temp[c.x][c.y] == 'x' && (c.check = 1))
				{
					sz->col_flag = 1;
					c.col_arr[i][c.x] = ft_atoi_base(&c.temp[c.x][c.y + 1], 16);
				}
			c.check == 0 ? c.col_arr[i][c.x] = 0xffffff : 0;
		}
		ft_double_free((void**)c.temp, sz->count_num_first);
		i++;
	}
	return (c.col_arr);
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

void		add_colours(t_coords *src, int col_num)
{
	const int	gradients[9][2] =
	{{0xef3b36, 0xfdeff9}, {0xf4c4f3, 0xfc67fa}, {0x00bf8f, 0x001510},
	{0x00c3ff, 0xffff1c}, {0x7303c0, 0xec38bc}, {0xef32d9, 0x89fffd},
	{0xfc4a1a, 0xf7b733}, {0x1a2a6c, 0xfdbb2d}, {0xff0084, 0x33001b}};
	int			i;
	int			j;

	i = 0;
	while (i < src->size_y)
	{
		j = 0;
		if (col_num > 0)
		{
			while (j < src->size_x)
			{
				if (src->coord_arr[i][j] <= 0)
					src->col_arr[i][j] = gradients[col_num - 1][0];
				else
					src->col_arr[i][j] = gradients[col_num - 1][1];
				j++;
			}
		}
		i++;
	}
}
