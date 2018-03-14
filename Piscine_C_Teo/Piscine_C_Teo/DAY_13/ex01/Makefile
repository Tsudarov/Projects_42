# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/27 23:26:25 by tsudarov          #+#    #+#              #
#    Updated: 2016/05/03 19:00:26 by tsudarov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat

SRC =  ft_cat.c ft_putstr.c main.c

OBJ = ft_cat.o ft_putstr.o main.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all clean
