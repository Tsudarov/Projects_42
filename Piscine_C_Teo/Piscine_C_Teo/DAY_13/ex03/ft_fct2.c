/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 21:28:46 by tsudarov          #+#    #+#             */
/*   Updated: 2016/05/09 22:25:00 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_offset	ft_fct2(t_offset offset, char *buf)
{
	if (offset.offset / 16 == offset.j)
	{
		if (offset.j != 0)
			ft_putchar('\n');
		ft_dectohex(offset.offset, 1, offset);
		if (offset.c == 1)
			ft_putstr("  ");
		if (offset.c == 0)
			ft_putstr(" ");
		offset.j++;
	}
	ft_dectohex(*buf, 0, offset);
	if (offset.i != 16 || offset.c == 1)
		ft_putstr(" ");
	offset.offset++;
	return (offset);
}
