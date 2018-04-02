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
# include <math.h>
# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"

typedef struct s_dot
{
	int 	x;
	int 	y;
	int		z;
}				t_dot;

typedef struct	s_breth
{
	int		dx;
	int		dy;
	int		dz;
	int		dx2;
	int		dy2;
	int		dz2;
	int		lengthX;
	int		lengthY;
	int		lengthZ;
	int		length;
	int		x_inc;
	int		y_inc;
	int		z_inc;
	int		x;
	int		y;
	int		z;
	int		d1;
	int		d2;
}				t_breth;

typedef	struct	s_minlx
{
	void	*mlx_p;
	void	*mlx_nw;
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
	char	**tc;
	int		count_num_first;
	int		count_num_temp;
	int		er;
}				t_chk_num;

typedef	struct	s_coords
{
	int		**coord_arr;
	int		**col_arr;
	int		size_x;
	int		size_y;
}				t_coords;

typedef	struct	s_col
{
	int		j;
	int		j1;
}				t_col;

void			set_coord(t_coords src, t_minlx win, int i, int j);
void			draw_a_line(t_minlx line, t_dot start, t_dot end);
int				absolute(int i);
int				key_react(int keycode, void *param);
t_chk_num		read_the_map(int fd);
t_chk_num		get_array_size(char *no_col_line, char *all_line);
int				**get_coord(char **split_nl, int size_x, int size_y);
int				**get_col(t_chk_num sz, int i, int i1);

void			put_line_right(t_minlx win, int i, int j, t_coords src);
void			put_line_down(t_minlx win, int i, int j, t_coords src);
void			put_line(t_minlx win, t_dot start, t_dot end);

void		print_arr(int **arr, int size_x, int size_y);

#endif
