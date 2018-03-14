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

static int		**arr_memalloc(int size_x, int size_y)
{
	int		i;
	int		**mem;	

	i = 0;
	if ((mem = (int **)malloc(sizeof(int*) * size_y)))
	{
		while (i < size_x)
		{
			if ((mem[i] = (int *)ft_memalloc(sizeof(int) * size_x)))
				i++;
		}
		return (mem);
	}
	return (NULL);
}

int			**get_col_array(char *line, int size_x, int size_y)
{
	int		**coord_arr;
	char	**temp_arr;
	char	**split_nl;
	int		i;
	int		j;

	if (!(coord_arr = arr_memalloc(size_x, size_y)))
		return (NULL);
	split_nl = ft_strsplit(line, '\n');
	i = 0;
	while (i < size_y)
	{
		temp_arr = ft_strsplit(split_nl[i], ' ');
		j = 0;
		while (j < size_x)
		{
			coord_arr[i][j] = ft_atoi_base(temp_arr[j], 16);
			j++;
		}
		i++;
	}
	// int		**col_arr;
	// t_iter	indx;

	// if (!(col_arr = arr_memalloc(size_x, size_y)))
	// 	return (NULL);
	// indx.split_nl = ft_strsplit(line, '\n');
	// indx.i = 0;
	// indx.i1 = 0;
	// while (indx.i1 < size_y  && indx.split_nl[indx.i])
	// {
	// 	indx.j = 0;
	// 	indx.j1 = 0;
	// 	while (indx.j1 < size_x && indx.split_nl[indx.i][indx.j])
	// 	{
	// 		while (indx.split_nl[indx.i][indx.j] != ' ' && indx.split_nl[indx.i][indx.j] != 'x')
	// 			indx.j++;
	// 		if (indx.split_nl[indx.i][indx.j] == ' ')
	// 			col_arr[indx.i1][indx.j1] = 0;
	// 		if (indx.split_nl[indx.i][indx.j] == 'x')
	// 			col_arr[indx.i1][indx.j1] = ft_atoi_base(&indx.split_nl[indx.i][indx.j + 1], base);
	// 		indx.j++;
	// 		indx.j1++;
	// 	}
	// 	indx.i++;
	// 	indx.i1++;
	// }
	return (col_arr);
}
	
int			**get_coord_array(char *line, int size_x, int size_y)
{
	int		**coord_arr;
	char	**temp_arr;
	char	**split_nl;
	int		i;
	int		j;

	if (!(coord_arr = arr_memalloc(size_x, size_y)))
		return (NULL);
	split_nl = ft_strsplit(line, '\n');
	i = 0;
	while (i < size_y)
	{
		temp_arr = ft_strsplit(split_nl[i], ' ');
		j = 0;
		while (j < size_x)
		{
			coord_arr[i][j] = ft_atoi_base(temp_arr[j], 10);
			j++;
		}
		i++;
	}
	return (coord_arr);
}

void			print_arr(int **arr, int size_x, int size_y)
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
