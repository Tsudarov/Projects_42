/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 23:26:51 by tsudarov          #+#    #+#             */
/*   Updated: 2016/05/09 06:51:16 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	main(int argc, char **argv)
{
	char		buf[BUF_SIZE + 1];
	t_offset	offset;

	offset.optionc = (char *)malloc(sizeof(char *) * 75);
	offset.offset = 0;
	offset.j = 0;
	offset.i = 0;
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "-C") == 0 && argc >= 3)
		{
			offset.c = 1;
			ft_hexdump(argv, offset);
		}
		if (ft_strcmp(argv[1], "-C") != 0 && argc >= 2)
		{
			offset.c = 0;
			ft_hexdump(argv, offset);
		}
	}
	else
		while (read(1, &buf, BUF_SIZE) == 1)
			;
	return (0);
}
