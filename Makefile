# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 17:21:49 by cvirgin           #+#    #+#              #
#    Updated: 2021/07/26 23:52:41 by cvirgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

SRC = main.c ft_bnew.c utils.c commands.c counter.c

OBJ = main.o ft_bnew.o utils.o commands.o counter.o

SRC_B = checker.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		ft_bnew.c utils.c commands.c counter.c

OBJ_B = checker.o get_next_line/get_next_line.o get_next_line/get_next_line_utils.o \
		ft_bnew.o utils.o commands.o counter.o

INCLUDE = push.h

FLAGS = -Wall -Wextra -Werror

OS	:= $(shell uname)

all: $(NAME)

$(NAME): $(INCLUDE) $(SRC)
	make bonus -C libft
	gcc $(FLAGS) $(SRC) -g -Llibft -lft -o $(NAME) 

bonus:
	make bonus -C libft
	gcc $(FLAGS) $(SRC_B) -g -Llibft -lft -o $(NAME_B) 
	
clean:
	make clean -C libft
	rm -f $(OBJ) $(OBJ_B)

fclean:	clean
	make fclean -C libft
	rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re