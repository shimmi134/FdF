# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shimi-be <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 11:53:14 by shimi-be          #+#    #+#              #
#    Updated: 2025/02/05 16:53:46 by shimi-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDE = libprintft.h
RM = rm -f
LIB = ar rcs
SRC = ft_printf.c ft_printf_helper.c ft_printf_helper2.c 
FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@$(LIB) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)  Makefile
	cc $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
