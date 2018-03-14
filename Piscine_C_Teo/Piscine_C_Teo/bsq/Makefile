# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mulzega <mulzega@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/19 15:37:32 by mulzega           #+#    #+#              #
#    Updated: 2016/05/27 13:24:37 by mulzega          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
FLAG = -Wall -Wextra -Werror
FILES =	ft_atoi.c \
		ft_memcpy.c \
		ft_putchar.c \
		ft_strcat.c \
		ft_strcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strstr.c \
		ft_bzero.c \
		ft_memset.c \
		ft_putstr.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_strncat.c \
		ft_strncpy.c \
		ft_swap.c \
		ft_split_backslash.c \

OBJ = ft_atoi.o \
	  ft_memcpy.o \
	  ft_putchar.o \
	  ft_strcat.o \
	  ft_strcpy.o \
	  ft_strlen.o \
	  ft_strncmp.o \
	  ft_strstr.o \
	  ft_bzero.o \
	  ft_memset.o \
	  ft_putstr.o \
	  ft_strcmp.o \
	  ft_strdup.o \
	  ft_strncat.o \
	  ft_strncpy.o \
	  ft_swap.o \
		ft_split_backslash.o \

ALL: $(NAME)

$(NAME):
	@gcc $(FLAG) -o $(NAME) $(FILES)

clean:
	@/bin/rm -f $(OBJ)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean ALL
