# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 15:49:53 by shimi-be          #+#    #+#              #
#    Updated: 2025/01/25 17:14:28 by shimi-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	fdf
LIB = libs/libmlx42.a libs/gnl.a libs/libft.a libs/libftprintf.a 
INCLUDE = MLX42/MLX42.h
RM = rm -f
CC = cc
SRC = src/main.c src/aa.c src/input.c src/draw.c src/drawlines.c src/freeing.c src/input_helper.c src/draw_helper.c 
FLAGS = -Wall -Werror -ldl -lglfw -pthread -lm -Wall -Werror -Wunreachable-code -fsanitize=address #-Ofast  

all: $(NAME)

$(NAME): $(SRC) $(INCLUDE) Makefile
	$(CC) $(FLAGS) -g $(SRC) $(LIB) $(OTHER) -o fdf
