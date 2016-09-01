# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/17 15:21:44 by mmoullec          #+#    #+#              #
#    Updated: 2016/09/01 13:39:01 by mmoullec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc -Wall -Werror -Wextra
MLX = -lmlx -framework openGL -framework AppKit -L./minilibx_macos -I./minilibx_macos
LIB = -lft -L./libft
LIBI = -I./libft
INC = -I./includes
SRC_DIR = ./srcs/
SRCS = ./mandelbrot3.c\
	   ./mouse_hook.c\
	   ./main.c\
	   ./prepa_draw.c\
	   ./make_colors.c\
	   ./zoom_hook.c\
	   ./redraw.c\
	   ./mandelbrot2.c\
	   ./math.c\
	   ./motion_hook.c\
	   ./put_color_to_pixel.c\
	   ./boat.c\
	   ./calcs.c\
	   ./key_hook.c\
	   ./initialize_mlx.c\
	   ./julia.c\
	   ./mandelbrot4.c\
	   ./color.c\
	   ./do_it.c\
	   ./tab_fractales.c\
	   ./do_fork.c\
	   ./redraw_key_position.c\

OBJ_FILES = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "make libft"
	@make -C libft
	@echo "make minilibx_macos"
	@make -C minilibx_macos
	@$(CC) -o $(NAME) $^ $(OBJ) $(INC) $(LIB) $(MLX)
	@echo "file Created"

%.o: $(SRC_DIR)%.c
	@$(CC) $(INC) -o $@ -c $< $(LIBI)

clean:
	@make clean -C libft
	@rm $(OBJ_FILES)
	@echo "clean ok"

fclean: clean
	@make fclean -C libft
	@rm $(NAME)
	@echo "fclean ok"

re: fclean all

.PHONY: all clean fclean re
