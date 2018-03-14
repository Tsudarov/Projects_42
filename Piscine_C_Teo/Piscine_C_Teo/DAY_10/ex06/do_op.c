/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 19:03:58 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/13 03:06:01 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	ft_plusmoinsdivise(char *str1, char *str2, char *str3)
{
	if (ft_strcmp(str2, "+") == 0)
		ft_putnbr(ft_atoi(str1) + ft_atoi(str3));
	if (ft_strcmp(str2, "-") == 0)
		ft_putnbr(ft_atoi(str1) - ft_atoi(str3));
	if (ft_strcmp(str2, "/") == 0)
	{
		if (ft_atoi(str3) == 0)
			ft_putstr("Stop : division by zero");
		else
			ft_putnbr(ft_atoi(str1) / ft_atoi(str3));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (ft_strcmp(argv[2], "-") != 0 && ft_strcmp(argv[2], "/") != 0 &&
			ft_strcmp(argv[2], "*") != 0 && ft_strcmp(argv[2], "%") != 0
			&& ft_strcmp(argv[2], "+") != 0)
		ft_putnbr(0);
	ft_plusmoinsdivise(argv[1], argv[2], argv[3]);
	if (ft_strcmp(argv[2], "%") == 0)
	{
		if (ft_atoi(argv[3]) == 0)
			ft_putstr("Stop : modulo by zero");
		else
			ft_putnbr(ft_atoi(argv[1]) % ft_atoi(argv[3]));
	}
	if (ft_strcmp(argv[2], "*") == 0)
	{
		ft_putnbr(ft_atoi(argv[1]) * ft_atoi(argv[3]));
	}
	ft_putstr("\n");
	return (0);
}
