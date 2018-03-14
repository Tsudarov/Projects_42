/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 21:28:46 by tsudarov          #+#    #+#             */
/*   Updated: 2016/05/09 10:21:10 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void		ft_print_c(char *str, int j)
{
	int i;

	i = 0;
	ft_putstr(" |");
	while (str[i] != '\0')
	{
		if (str[i] > 31 && str[i] < 127)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
		if (i < j && str[i] == '\0')
		{
			ft_putchar('.');
			i++;
		}
	}
	ft_putchar('|');
}

char		*ft_str_clr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		str[i++] = '\0';
	return (str);
}

t_offset	ft_read_hex(int fd, t_offset offset)
{
	char	buf[BUF_SIZE + 1];
	int		ret;

	if (fd > 0)
	{
		while ((ret = read(fd, &buf, BUF_SIZE)) >= 1)
		{
			if (offset.offset / 16 == offset.j)
			{
				if (offset.c == 1 && offset.j != 0)
					ft_print_c(offset.optionc, offset.i);
				offset.i = 0;
				ft_str_clr(offset.optionc);
			}
			if (offset.i == 8 && offset.c == 1)
				ft_putchar(' ');
			offset.optionc[offset.i++] = *buf;
			offset = ft_fct2(offset, buf);
		}
	}
	return (offset);
}

int			ft_hexdump(char **argv, t_offset offset)
{
	int			fd;
	int			i;

	i = 1;
	while (argv[i])
	{
		if (offset.c == 1 && argv[i + 1])
			fd = open(argv[i + 1], O_RDONLY);
		if (offset.c == 0)
			fd = open(argv[i], O_RDONLY);
		offset = ft_read_hex(fd, offset);
		i++;
	}
	ft_fct(offset, argv, fd, i);
	free(offset.optionc);
	return (0);
}
