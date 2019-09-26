# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damerica <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 18:18:48 by damerica          #+#    #+#              #
#    Updated: 2019/09/03 18:40:30 by damerica         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJ = $(SRC)ft_putchar.c $(SRC)ft_putstr.c $(SRC)ft_strcmp.c $(SRC)ft_strlen.c $(SRC)ft_swap.c
SRC = ./srcs/
OBJ0 = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
HEADER = ./includes/

all: $ (NAME)

$ (NAME) :
	gcc -Wall -Wextra -Werror -c $(OBJ) -I $(HEADER)
	ar rc $(NAME) $(OBJ0)
	ranlib $(NAME)
clean :
	/bin/rm -f $(OBJ0)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
