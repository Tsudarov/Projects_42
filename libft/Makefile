# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 19:54:17 by tsudarov          #+#    #+#              #
#    Updated: 2016/12/13 14:51:47 by tsudarov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_abso.c ft_atoi.c ft_bzero.c ft_factorial.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
ft_lstdelone.c ft_lstforeach_if.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
ft_lstpush_back.c ft_lstpush_front.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_power.c \
ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_square_root.c ft_strcat.c \
ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
ft_strtrim.c ft_swap.c ft_tolower.c ft_toupper.c \

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -Werror

INCLUDE = -I libft

all: $(NAME)

$(NAME): titillage $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[34;04;32mLibft Compilation completed !\033[0m"

$(OBJ):
	@gcc $(CFLAGS) $(INCLUDE) -c $*.c -o $@

clean:
	@echo "\033[34;02;33mLibft obj_clean processing ...\033[0m"
	@rm -rf $(OBJ)
	@echo "\033[34;04;32mLibft obj_clean completed !\033[0m"

fclean: clean
	@echo "\033[34;02;33mLibft Fclean processing ...\033[0m"
	@rm -f $(NAME)
	@echo "\033[34;04;32mLibft Fclean completed !\033[0m"

ext_fclean:
	@echo "\033[34;02;33mLibft Full_clean processing ...\033[0m"
	@rm -rf $(OBJ)
	@rm -f $(NAME)
	@echo "\033[34;04;32mLibft Full_clean completed !\033[0m"

titillage:
	@echo "\033[34;02;33mLibft Compilation processing ...\033[0m"

re: fclean all

.PHONY: all clean fclean re
