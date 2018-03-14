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
	int		error;
	char	*read_line;
	char	*all_line;
	char	*no_col;
	char	**coord_line;
}				t_data;

typedef	struct	s_chk_sp
{
	char	**line_split;
	int		count_sp;
	int		count_sp_temp;
}				t_chk_sp;

typedef	struct	s_chk_num
{
	int		i;
	char	**temp_str;
	int		count_num_first;
	int		count_num_temp;
}				t_chk_num;

typedef	struct	s_iter
{
	int			i;
	int			j;
	int			i1;
	int			j1;
	char		**split_nl;
}				t_iter;

typedef	struct	s_coords
{
	int		**coord_arr;
	int		**col_arr;
}				t_coords;

void			set_coord(void *mlx_p, void *mlx_nw);
void			draw_a_line(void *mlx_p, void *mlx_nw, t_minlx line);
int				key_react(int keycode, void *param);
t_data			read_the_map(int fd);
t_chk_num		get_array_size(char *no_col_line);
void			print_arr(int **arr, int size_x, int size_y);
int				**get_coord_array(char *line, int size_x, int size_y, int base);
int				**get_col_array(char *line, int size_x, int size_y, int base);

#endif
