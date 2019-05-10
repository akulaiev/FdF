# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 15:25:37 by ybohusev          #+#    #+#              #
#    Updated: 2018/01/15 15:25:38 by ybohusev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft/

MLX = ./libmlx.a

SOURCE = main.c draw_a_line.c event_handle.c get_data.c check_data.c \
create_array.c img_transform.c img_transform_help.c
O_FILES = main.o draw_a_line.o event_handle.o get_data.o check_data.o \
create_array.o img_transform.o img_transform_help.o

HEADER = -I ./fdf.h

all: LIBS $(NAME) 

$(NAME): $(O_FILES)
	$(CC) -framework OpenGL -framework AppKit $(CFLAGS) -o $(NAME) $(O_FILES) $(LIBFT) $(MLX)

LIBS:
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(HEADER) $(CFLAGS) $(SOURCE) -c $<

exe:
	./$(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(O_FILES)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	clear

norm:
	norminette $(SOURCE)

re: fclean all