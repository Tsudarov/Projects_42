# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/15 01:21:16 by tsudarov          #+#    #+#              #
#    Updated: 2017/10/31 01:00:03 by tsudarov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	wolf3d

SRC =	src/main.c \
        src/key_event.c \
        src/map_render.c \
        src/key_hook.c \
        src/raycast.c

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = -Wall -Werror -Wextra -g

FWORK = -Wextra -framework OpenGL -framework AppKit

LIB =	-lmlx

INC =   -I /usr/X11/include/X11

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $^ $(INC)

$(NAME): $(SRC:.c=.o)
	@echo "\033[1;33m--- STARTING COMPILATION ---\033[0m"
	@echo "\033[0;32m> compile the whole shit\033[0m"
	@$(CC) -o $(NAME) $(OBJ) $(INC) $(LIB) $(FWORK)

clean:
	@echo "\033[1;33m------ CLEANING FILES ------\033[0m"
	@echo "\033[1;31mCleaning object files\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[1;33m------- CLEANING ALL -------\033[0m"
	@echo "\033[1;31mCleaning executable files\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
