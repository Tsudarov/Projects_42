# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 19:54:17 by tsudarov          #+#    #+#              #
#    Updated: 2017/12/27 14:54:12 by tsudarov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = backtracking.c main.c pgpxy.c print.c identif_tetra.c tableau.c\
	  error.c tetra.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -Werror

LIB = -L libft -lft

INCLUDE = -I libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

$(OBJ):
	@echo "\033[34;02;33mFillit compilation processing ...\033[0m"
	@gcc $(CFLAGS) $(INCLUDE) -c $(SRC)
	@echo "\033[34;04;32mFillit compilation completed !\033[0m"

clean:
	@make -C libft clean
	@echo "\033[34;02;33mFillit obj_clean processing ...\033[0m"
	@rm -rf $(OBJ)
	@echo "\033[34;04;32mFillit obj_clean completed !\033[0m"

fclean: clean
	@make -C libft ext_fclean
	@echo "\033[34;02;33mFillit Fclean processing ...\033[0m"
	@rm -f $(NAME)
	@echo "\033[34;04;32mFillit Fclean completed !\033[0m"

re: fclean all

.PHONY:  all clean fclean re
