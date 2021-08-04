# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 17:21:49 by cvirgin           #+#    #+#              #
#    Updated: 2021/08/04 17:45:00 by cvirgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

SRC = main.c\
	ft_bnew.c utils.c commands.c counter.c checker2.c utils2.c commands2.c commands3.c\
	ft_bnew2.c utils3.c utils4.c utils5.c

OBJ = main.o\
	ft_bnew.o utils.o commands.o counter.o checker2.o utils2.o commands2.o commands3.o\
	ft_bnew2.o utils3.o utils4.o utils5.o

SRC_B = checker.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		ft_bnew.c utils.c commands.c counter.c checker2.c utils2.c commands2.c commands3.c\
		ft_bnew2.c utils3.c utils4.c utils5.c

OBJ_B = checker.o get_next_line/get_next_line.o get_next_line/get_next_line_utils.o \
		ft_bnew.o utils.o commands.o counter.o checker2.o utils2.o commands2.o commands3.o\
		ft_bnew2.o utils3.o utils4.o utils5.o

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