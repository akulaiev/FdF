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

MLX = ./minilibx_macos/libmlx.a
MLX_PATH = ./minilibx_macos/

SOURCE = main.c
O_FILES = main.o

HEADER = -I ./fdf.h

all: LIBS $(NAME) 

$(NAME): $(O_FILES)
	$(CC) $(MLX) -framework OpenGL -framework AppKit $(CC_FLAGS) -o $(NAME) $(O_FILES) $(LIBFT) 

LIBS:
	make -C $(MLX_PATH)
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(HEADER) $(CC_FLAGS) $(SOURCE) -c $<

exe:
	./$(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(O_FILES)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	clear

re: fclean all