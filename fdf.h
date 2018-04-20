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

typedef	struct	s_data
{
	char	**aln;
	char	**no_c;
	int		num_lines;
	int		i;
	int		count_num_first;
	int		count_num_temp;
	int		er;
}				t_data;

typedef	struct	s_chk_sp
{
	int		count_sp;
	int		count_sp_temp;
}				t_chk_sp;

typedef	struct	s_coords
{
	int		**coord_arr;
	int		**col_arr;
	int		size_x;
	int		size_y;
	int		win_width;
	int		win_length;
	int		shift_right;
	int		shift_down;
	int		сoeff;
	void	*mlx_p;
	void	*mlx_nw;
	int		col;
	double	angle_x;
	double	angle_y;
	double	angle_z;
}				t_coords;

typedef	struct	s_col
{
	int		j;
	int		j1;
}				t_col;

void			set_coord(t_coords src, int i, int j);
void			draw_a_line(t_coords line, t_dot start, t_dot end);
int				key_react(int keycode, void *param);
t_data			read_the_map(int fd);
int				get_array_size(t_data *dt);
int				**get_coord(char **split_nl, int size_x, int size_y);
int				**get_col(t_data sz, int i, int i1);
void			put_line_right(int i, int j, t_coords src);
void			put_line_down(int i, int j, t_coords src);
void			put_line(t_coords src, t_dot start, t_dot end);
void			manipulate_window(t_coords *coords);
t_dot			turn_x(t_dot dot, double angle);
t_dot			turn_y(t_dot dot, double angle);
t_dot			turn_z(t_dot dot, double angle);
t_dot			enlarge(t_dot dot, int size);
t_dot			move(t_dot dot, int shift_right, int shift_down);
int				count_win_diagonal(t_coords *coords, int diagonal);
int				count_diagonal(t_coords *c);
void			pic_move(int keycode, void *param);
void			pic_scale(int keycode, void *param);
void			rotate(int keycode, void *param);

void		print_arr(int **arr, int size_x, int size_y);

#endif
