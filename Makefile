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

fclean:
	@echo "\033[01;35;05mINFINIT CLEAN PROCESSING...\033[0m"
	@make -C Fillit fclean
	@make -C fdf fclean
	@make -C fractol fclean
	@make -C libft ext_fclean
	@make -C mlx_cust_lib ext_fclean
	@make -C fdf/mlx_cust_lib/minilibx_macos clean
	@echo "\033[01;34;05mINFINIT CLEAN COMPLETED !\033[0m"

