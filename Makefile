# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 15:49:53 by shimi-be          #+#    #+#              #
#    Updated: 2025/01/07 16:03:56 by shimi-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	fdf
LIB = libmlx42.a -ldl -lglfw -pthread -lm
OTHER = -Wall -Werror -Wunreachable-code -Ofast
INCLUDE = MLX42/MLX42.h
RM = rm -f
CC = cc
SRC = main.c
FLAGS = -Wall -Werror

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) $(LIB) $(OTHER) -g -D DEBUG=1 -fsanitize=address
