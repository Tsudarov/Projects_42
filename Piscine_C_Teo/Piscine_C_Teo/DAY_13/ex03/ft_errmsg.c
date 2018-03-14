/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errmsg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 23:26:38 by tsudarov          #+#    #+#             */
/*   Updated: 2016/05/07 00:26:02 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_errmsg(char *argv, int errtyp)
{
	if (errtyp == 1)
	{
		ft_putstr("hexdump: ");
		ft_putstr(argv);
		ft_putstr(": No such file or directory\n");
	}
	if (errtyp == 2)
	{
		ft_putstr("hexdump: ");
		ft_putstr(argv);
		ft_putstr(": Bad file descriptor\n");
	}
}
