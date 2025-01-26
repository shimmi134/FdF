# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 15:49:53 by shimi-be          #+#    #+#              #
#    Updated: 2025/01/26 14:43:13 by shimi-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	fdf
LIB = libs/libmlx42.a libs/gnl.a libs/libft.a libs/libftprintf.a 
INCLUDE = MLX42/MLX42.h fdf.h
RM = rm -f
CC = cc
SRC = src/main.c src/get_and_draw.c src/input.c src/draw.c src/drawlines.c src/freeing.c src/input_helper.c src/draw_helper.c 
OBJ = $(SRC:.c=.o)
LDFLAGS = -ldl -lglfw -lm -pthread -fsanitize=address -Ofast
FLAGS = -Wall -Werror -Wall -Werror -Wunreachable-code

all: $(NAME)

$(NAME): libs $(OBJ)
	@$(CC) $(OBJ) $(LIB) $(LDFLAGS) -o $(NAME)
	@printf "Created your executable!\n"

libs: 
	@$(MAKE) -C srclibs/get_next_line
	@$(MAKE) -C srclibs/libft
	@$(MAKE) -C srclibs/ft_printf
	@$(MAKE) -C MLX42/build/
	@mv srclibs/get_next_line/gnl.a libs/
	@mv srclibs/libft/libft.a libs/
	@mv srclibs/ft_printf/libftprintf.a libs/
	@mv MLX42/build/libmlx42.a libs/

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "Deleting .o\n"
	@$(RM) $(OBJ)
	@$(MAKE) -s -C srclibs/get_next_line clean
	@$(MAKE) -s -C srclibs/libft clean
	@$(MAKE) -s -C srclibs/ft_printf clean

fclean: clean
	@printf "Deleting everything\n"
	@$(RM) $(NAME)
	@$(MAKE) -s -C srclibs/get_next_line fclean
	@$(MAKE) -s -C srclibs/libft fclean
	@$(MAKE) -s -C srclibs/ft_printf fclean
	@$(RM) libs/gnl.a libs/libft.a libs/libftprintf.a libs/libmlx42.a

re: fclean all

.PHONY: all clean fclean re libs
