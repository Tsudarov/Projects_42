# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalexand <dalexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/01 11:35:33 by dalexand          #+#    #+#              #
#    Updated: 2015/11/01 18:01:15 by dalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =

FLG = -Wall -Wextra -Werror

SRC_PATH = ./src/

all:
	gcc -o colle-00 $(SRC_PATH)colle00.c $(SRC_PATH)common.c $(SRC_PATH)commonbis.c $(SRC_PATH)main00.c $(FLG)
	gcc -o colle-01 $(SRC_PATH)colle01.c $(SRC_PATH)common.c $(SRC_PATH)commonbis.c $(SRC_PATH)main01.c $(FLG)
	gcc -o colle-02 $(SRC_PATH)colle02.c $(SRC_PATH)common.c $(SRC_PATH)commonbis.c $(SRC_PATH)main02.c $(FLG)
	gcc -o colle-03 $(SRC_PATH)colle03.c $(SRC_PATH)common.c $(SRC_PATH)commonbis.c $(SRC_PATH)main03.c $(FLG)
	gcc -o colle-04 $(SRC_PATH)colle04.c $(SRC_PATH)common.c $(SRC_PATH)commonbis.c $(SRC_PATH)main04.c $(FLG)
	gcc -o colle-2 $(SRC_PATH)common.c $(SRC_PATH)commonbis.c $(SRC_PATH)colle2.c $(SRC_PATH)colle2bis.c $(SRC_PATH)colle00.c \
		$(SRC_PATH)colle01.c $(SRC_PATH)colle02.c $(SRC_PATH)colle03.c $(SRC_PATH)colle04.c

fclean:
	rm -f colle*

re: fclean all


