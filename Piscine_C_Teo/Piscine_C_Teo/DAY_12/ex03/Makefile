# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/27 23:26:25 by tsudarov          #+#    #+#              #
#    Updated: 2016/05/07 04:52:09 by tsudarov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_hexdump

SRC = ft_hexdump.c ft_putstr.c main.c ft_errmsg.c ft_strcmp.c \
	  ft_dectohex.c ft_strlen.c ft_strcat.c ft_fct.c ft_fct2.c ft_atoi.c ft_putnbr.c

OBJ = ft_hexdump.o ft_putstr.o main.o ft_errmsg.o ft_strcmp.o \
	  ft_dectohex.o ft_strlen.o ft_strcat.o ft_fct.o ft_fct2.o ft_atoi.o ft_putnbr.o

all: $(NAME)

$(NAME):
	gcc -g -Wall -Wextra -Werror -c $(SRC)
	gcc -g -Wall -Wextra -Werror -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all clean
