# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/17 15:21:44 by mmoullec          #+#    #+#              #
#    Updated: 2016/08/17 15:27:31 by mmoullec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc #-Wall -Werror -Wextra#
MLX = -lmlx -framework openGL -framework AppKit
LIB = -lft -L./libft
LIBI = -I./libft
INC = -I./includes
SRCS = ./srcs/*.c

all:
	$(CC) -o $(NAME) $(SRCS) $(MLX) $(LIB) $(LIBI) $(INC)

run: all
	./fractol julia
