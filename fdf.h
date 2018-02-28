/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:26:33 by akulaiev          #+#    #+#             */
/*   Updated: 2018/02/26 14:26:36 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"

typedef	struct	s_minlx
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		col;
}				t_minlx;

typedef	struct	s_data
{
	char	*read_line;
	char	*all_line;
	char	**coord_line;
	int		size;
}				t_data;

void			set_coord(void *mlx_p, void *mlx_nw);
void			draw_a_line(void *mlx_p, void *mlx_nw, t_minlx line);
int				key_react(int keycode, void *param);
int				**read_the_map(int fd);

#endif
