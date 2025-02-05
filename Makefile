# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 17:04:44 by shimi-be          #+#    #+#              #
#    Updated: 2025/02/05 19:52:28 by shimi-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBS = libs/libmlx42.a libs/gnl.a libs/libft.a libs/libftprintf.a 
INCLUDE = MLX42/MLX42.h fdf.h
RM = rm -rf
CC = cc
LDFLAGS = -g -ldl -lglfw -lm -pthread -Ofast -fsanitize=address
FLAGS = -Wall -Werror -Wunreachable-code
SRC = src/main.c src/get_and_draw.c src/input.c src/draw.c src/drawlines.c src/freeing.c src/input_helper.c src/draw_helper.c 
OBJ = $(SRC:.c=.o)
BUILD = MLX42/build
MLX_DIR = MLX42

all: $(NAME)

$(NAME): $(OBJ) Makefile | $(LIBS) 
	$(CC) -g $(OBJ) $(LIBS) $(LDFLAGS) -o $(NAME)
	@echo "Created your executable!"

%.o: %.c $(INCLUDE) 
	$(CC) -g $(FLAGS) -c $< -o $@

$(LIBS): | $(BUILD) 
	@$(MAKE) -C srclibs/get_next_line
	@$(MAKE) -C srclibs/libft
	@$(MAKE) -C srclibs/ft_printf
	@$(MAKE) -C MLX42/build/
	@mv srclibs/get_next_line/gnl.a libs/
	@mv srclibs/libft/libft.a libs/
	@mv srclibs/ft_printf/libftprintf.a libs/
	@mv MLX42/build/libmlx42.a libs/

$(BUILD):
	@if [ ! -d "$(MLX_DIR)/build" ]; then \
        	cmake $(MLX_DIR) -B $(MLX_DIR)/build > /dev/null 2>&1 && \
        	make -C $(MLX_DIR)/build -j4 > /dev/null 2>&1; \
	fi	

clean:
	@echo "Deleting .o"
	@$(RM) $(OBJ)
	@$(MAKE) -s -C srclibs/get_next_line clean
	@$(MAKE) -s -C srclibs/libft clean
	@$(MAKE) -s -C srclibs/ft_printf clean

fclean: clean
	@echo "Deleting everything"
	@$(RM) $(NAME)
	@$(MAKE) -s -C srclibs/get_next_line fclean
	@$(MAKE) -s -C srclibs/libft fclean
	@$(MAKE) -s -C srclibs/ft_printf fclean
	@$(RM) $(MLX_DIR)/build
	@$(RM) libs/gnl.a libs/libft.a libs/libftprintf.a libs/libmlx42.a

re: fclean all

.PHONY: all clean fclean re
