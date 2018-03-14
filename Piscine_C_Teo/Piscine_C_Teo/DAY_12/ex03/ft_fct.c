/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 21:28:46 by tsudarov          #+#    #+#             */
/*   Updated: 2016/05/09 23:07:51 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_offset	ft_fct(t_offset offset, char **argv, int fd, int i)
{
	int j;

	if (fd == -1)
	{
		ft_errmsg(argv[i - 1], 1);
		ft_errmsg(argv[i - 1], 2);
	}
	else
	{
		j = (17 - offset.i) * 3;
		j -= (offset.i <= 8 ? 2 : 3);
		if (offset.c == 0)
			j -= (offset.i <= 8 ? 2 : 1);
		while (j-- != 0)
			ft_putchar(' ');
		if (offset.c == 1)
			ft_print_c(offset.optionc, offset.i);
		ft_putchar('\n');
		ft_dectohex(offset.offset, 1, offset);
		ft_putchar('\n');
	}
	return (offset);
}
