# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 15:49:53 by shimi-be          #+#    #+#              #
#    Updated: 2025/01/22 14:21:47 by shimi-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	fdf
LIB = libmlx42.a libs/gnl.a libs/libft.a libs/libftprintf.a -ldl -lglfw -pthread -lm
OTHER = -Wall -Werror -Wunreachable-code #-Ofast -fsanitize=address
INCLUDE = MLX42/MLX42.h
RM = rm -f
CC = cc
SRC = tests3.c tests2.c
FLAGS = -Wall -Werror

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -g $(SRC) $(LIB) $(OTHER)
