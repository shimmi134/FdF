# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 12:27:08 by shimi-be          #+#    #+#              #
#    Updated: 2025/02/05 16:53:35 by shimi-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
INCLUDE = get_next_line.h
LIB = ar rcs
SRC = get_next_line.c get_next_line_utils.c
FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@$(LIB) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE) Makefile
	cc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
