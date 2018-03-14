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

NAME = libcustmlx.a

SRC = mlx_image.c mlx_struct_init.c mlx_struct_init2.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -Werror

INCLUDE = -I minilibx_macos

all: $(NAME)

$(NAME): $(OBJ)
	make -C minilibx_macos
	@echo "\033[34;02;33mMlx_cust Compilation processing ...\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[34;04;32mMlx_cust Compilation completed !\033[0m"

$(OBJ):
	@gcc $(CFLAGS) $(INCLUDE) -c $*.c -o $@

clean:
	@echo "\033[34;02;33mMlx_cust obj_clean processing ...\033[0m"
	@rm -rf $(OBJ)
	@echo "\033[33;04;32mMlx_cust obj_clean completed !\033[0m"

fclean: clean
	@echo "\033[34;02;33mMlx_cust Fclean processing ...\033[0m"
	@rm -f $(NAME)
	@echo "\033[33;04;32mMlx_cust Fclean completed !\033[0m"

ext_fclean:
	@echo "\033[34;02;33mMlx_cust Full_clean processing ...\033[0m"
	@rm -rf $(OBJ)
	@rm -f $(NAME)
	@rm -f $(NAME)
	@echo "\033[33;04;32mMlx_cust Full_clean completed !\033[0m"


re: fclean all

.PHONY: all clean fclean re
