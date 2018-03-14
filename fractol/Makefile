# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 19:54:17 by tsudarov          #+#    #+#              #
#    Updated: 2017/12/27 15:01:17 by tsudarov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol


SRC = main.c init.c init_2.c maths_fractoil.c maths_mandelbrot.c \
      maths_tricorne.c maths_newton.c maths_flux.c maths_julia.c \
      maths_flower.c events.c maths_xxx.c tool.c tool_2.c

OBJ = $(SRC:.c=.o)

LIB = -L libft -lft -L mlx_cust_lib/minilibx_macos -lmlx -L mlx_cust_lib -lcustmlx

CFLAGS += -Wall -Wextra -Werror -g

INCLUDE = -I mlx_cust_lib -I libft -I minilibx_macos -Ofast

FRAMEWORK = -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OBJ) fractol.h Makefile
	@make -C libft
	@make -C mlx_cust_lib
	@echo "\033[01;35;05mFract'ol compilation  processing ...\033[0m"
	@gcc $(CFLAGS) $(LIB) $(FRAMEWORK) -o $(NAME) $(OBJ)
	@echo "\033[01;34;05mFract'ol compilation completed !\033[0m"

$(OBJ): $(SRC) 
	@gcc $(CFLAGS) $(INCLUDE) -c $*.c -o $@

clean:
	@make -C libft clean
	@make -C mlx_cust_lib clean
	@echo "\033[34;02;33mFractol obj_clean processing ...\033[0m"
	@rm -rf $(OBJ)
	@echo "\033[34;04;32mFractol obj_clean completed !\033[0m"

fclean: clean
	@make -C libft ext_fclean
	@make -C mlx_cust_lib ext_fclean
	@echo "\033[34;02;33mFractol Fclean processing ...\033[0m"
	@rm -f $(NAME)
	@echo "\033[34;04;32mFractol Fclean completed !\033[0m"

re: fclean all

.PHONY: all clean fclean re
