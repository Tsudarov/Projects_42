/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 23:26:38 by tsudarov          #+#    #+#             */
/*   Updated: 2016/05/09 22:32:55 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	ft_foretdeif(int buf)
{
	if (buf == 10)
		return ('a');
	else if (buf == 11)
		return ('b');
	else if (buf == 12)
		return ('c');
	else if (buf == 13)
		return ('d');
	else if (buf == 14)
		return ('e');
	else if (buf == 15)
		return ('f');
	else
		return (buf + '0');
}

void	ft_fonction(int num)
{
	if (num <= 15 && num >= 0)
		ft_putchar('0');
	if (num == 0)
		ft_putchar('0');
}

void	ft_gaindeligne(t_offset offset, int j)
{
	if (offset.c == 1)
		while (j++ <= 7)
			ft_putchar('0');
	if (offset.c == 0)
		while (j++ <= 6)
			ft_putchar('0');
}

void	ft_dectohex(int num, int k, t_offset offset)
{
	int		*buf;
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	buf = (int*)malloc(sizeof(int) * 75);
	str = (char*)malloc(sizeof(char) * 75);
	if (k != 1)
		ft_fonction(num);
	while (num > 0)
	{
		buf[i++] = num % 16;
		num = num / 16;
	}
	i = i - 1;
	while (i >= 0)
		if (ft_foretdeif(buf[i--]))
			str[j++] = ft_foretdeif(buf[i + 1]);
	if (k == 1)
		ft_gaindeligne(offset, j);
	ft_putstr(str);
}
