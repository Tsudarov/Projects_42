/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 23:26:30 by tsudarov          #+#    #+#             */
/*   Updated: 2016/05/02 04:44:36 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_cat(char *argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("cat: ");
		ft_putstr(argv);
		ft_putstr(": No such file or directory\n");
		return (-1);
	}
	while ((ret = read(fd, &buf, BUF_SIZE)) >= 1)
		ft_putstr(buf);
	return (0);
}
