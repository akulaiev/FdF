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
	char	*aln;
	char	*no_c;
}				t_data;

typedef	struct	s_chk_sp
{
	int		count_sp;
	int		count_sp_temp;
}				t_chk_sp;

typedef	struct	s_chk_num
{
	int		i;
	char	**temp_str;
	char	**temp_col;
	int		count_num_first;
	int		count_num_temp;
	int		er;
}				t_chk_num;

typedef	struct	s_coords
{
	int		**coord_arr;
	int		**col_arr;
}				t_coords;

typedef	struct	s_col
{
	char	**split_nl;
	int		j;
	int		j1;
}				t_col;

void			set_coord(void *mlx_p, void *mlx_nw);
void			draw_a_line(void *mlx_p, void *mlx_nw, t_minlx line);
int				key_react(int keycode, void *param);
t_chk_num		read_the_map(int fd);
t_chk_num		get_array_size(char *no_col_line, char *all_line);
void			print_arr(int **arr, int size_x, int size_y);
int				**get_coord(char **split_nl, int size_x, int size_y);
int				**get_col(t_chk_num sz, int i, int i1);

#endif
