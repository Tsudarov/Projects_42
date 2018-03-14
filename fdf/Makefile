# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 19:54:17 by tsudarov          #+#    #+#              #
#    Updated: 2017/12/27 15:08:27 by tsudarov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf_event.c  main.c fdf_parse.c fdf_init.c fdf_error.c

OBJ = $(SRC:.c=.o)

LIB = -L libft -lft -L mlx_cust_lib -lmlx

CFLAGS += -Wall -Wextra -Werror

INCLUDE = -I mlx_cust_lib -I libft

FRAMEWORK = -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OBJ) fdf.h Makefile
	@make -C libft
	@make -C mlx_cust_lib
	@echo "\033[34;02;33mFdf compilation processing ...\033[0m"
	@gcc $(CFLAGS) $(LIB) $(FRAMEWORK) -o $(NAME) $(OBJ)
	@echo "\033[34;04;32mFdf compilation completed !\033[0m"

$(OBJ):
	@gcc $(CFLAGS) $(INCLUDE) -c $*.c -o $@

clean:
	@make -C libft clean
	@make -C mlx_cust_lib clean
	@echo "\033[34;02;33mFdf obj_clean processing ...\033[0m"
	@rm -rf $(OBJ)
	@echo "\033[34;04;32mFdf obj_clean completed !\033[0m"

fclean: clean
	@make -C libft ext_fclean
	@make -C mlx_cust_lib ext_fclean
	@echo "\033[34;02;33mFdf Fclean processing ...\033[0m"
	@rm -f $(NAME)
	@echo "\033[34;04;32mFdf Fclean completed !\033[0m"

re: fclean all

.PHONY: all clean fclean re
