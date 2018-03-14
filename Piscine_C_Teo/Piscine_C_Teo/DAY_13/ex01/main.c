/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 23:26:51 by tsudarov          #+#    #+#             */
/*   Updated: 2016/05/02 04:46:29 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	main(int argc, char **argv)
{
	int		i;
	char	buf[BUF_SIZE + 1];

	i = 1;
	if (argc == 1)
	{
		while (read(1, &buf, BUF_SIZE) >= 1)
		{
			ft_putstr(buf);
		}
	}
	while (i < argc)
	{
		ft_cat(argv[i]);
		i++;
	}
	return (0);
}
