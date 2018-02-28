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

int		ft_atoi_base(const char *str, int base)
{
	int 	i;
	int		diff;
	int 	temp;
	int 	check;

	i = 0;
	temp = 0;
	check = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
	|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			check = 1;
		i++;
	}
	while (((str[i] >= '0' && str[i] <= '9' && (diff = '0')) || (str[i] >= 'A' && 
	str[i] <= 'F' && (diff = '7')) || (str[i] >= 'a' && str[i] <= 'f' && (diff = 'W'))) && str[i])
	{
		temp *= base;
		temp += str[i] - diff;
		i++;
	}
	check == 1 ? (temp = -temp) : (temp = temp);
	return (temp);
}

static char		*ft_realloc(char *line, size_t old, size_t new)
{
	char *temp;

	if ((new == 0 || new <= old) && line)
		return (line);
	if (!line)
		return (ft_memalloc(new + 1));
	temp = (char*)malloc(new + old + 1);
	ft_strcpy(temp, line);
	free(line);
	return (temp);
}

int			**read_the_map(int fd)
{
	t_data	data;
	int		**coord_arr;
	int		i;
	int		j;
	int		base;
	// int		res;

	data.size = 0;
	i = 0;
	data.all_line = NULL;
	data.read_line = NULL;
	while (get_next_line(fd, &data.read_line))
	{
		if (!(data.all_line = ft_realloc(data.all_line, ft_strlen(data.all_line), (ft_strlen(data.read_line) + 1 + ft_strlen(data.all_line)))))
			return (NULL);
		ft_strcat(data.all_line, data.read_line);
		ft_strcat(data.all_line, "\n");
	}
	data.coord_line = ft_strsplit(data.all_line, '\n');
	while (data.coord_line[i])
	{
		j = 0;
		while (data.coord_line[j])
		{
			
			j++;
		}
		i++;
	}
	while (data.coord_line[data.size])
	{
		printf("%s∆\n", data.coord_line[data.size]);
		data.size++;
	}
	// if ((!(coord_arr = (int**)malloc(sizeof(int*)))) || (!(*coord_arr = (int*)malloc(sizeof(int) * data.size))))
	// 	return (NULL);
	// while (data.coord_line[i])
	// {
	// 	res = ft_atoi_base(data.coord_line[i]);
	// 	printf("%i\n", res);
	// 	i++;
	// }
	return (NULL);
}
