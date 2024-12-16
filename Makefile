# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 15:49:53 by shimi-be          #+#    #+#              #
#    Updated: 2024/12/16 15:50:14 by shimi-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	fdf
LIB = libmlx42.a
OTHER = -Iinclude -ldl -lglfw -pthread -lm
INCLUDE = MLX42/MLX42.h
RM = rm -f
CC = cc
SRC = prog.c
FLAGS = -Wall -Werror

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) $(LIB) $(OTHER) -g -fsanitize=address
