# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 17:21:49 by cvirgin           #+#    #+#              #
#    Updated: 2021/04/13 22:39:46 by cvirgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c ft_bnew.c utils.c commands.c counter.c

OBJ = main.o ft_bnew.o utils.o commands.o counter.o

INCLUDE = push.h

FLAGS = -Wall -Wextra -Werror

OS	:= $(shell uname)

all: $(NAME)

$(NAME): $(INCLUDE) $(SRC)
	make bonus -C libft
	gcc $(SRC) -g -Llibft -lft -o $(NAME) 


clean:
	make clean -C libft
	rm -f $(OBJ)

fclean:	clean
	make fclean -C libft
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re