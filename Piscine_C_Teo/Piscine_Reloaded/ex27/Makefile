# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 18:06:54 by tsudarov          #+#    #+#              #
#    Updated: 2016/11/07 18:07:09 by tsudarov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC =  ft_display_file.c ft_putstr.c main.c

OBJ = ft_display_file.o ft_putstr.o main.o

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -c $(SRC)
		gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all clean
