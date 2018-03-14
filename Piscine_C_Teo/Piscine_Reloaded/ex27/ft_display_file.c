/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:23:40 by tsudarov          #+#    #+#             */
/*   Updated: 2016/11/07 18:25:32 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

#define BUF_SIZE 1

int		ft_display_file(int argc, char *argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(argv, O_RDONLY);
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (2);
	}
	if (argc <= 1)
	{
		ft_putstr("File name missing.\n");
		return (2);
	}
	if (fd == -1)
		return (2);
	while ((ret = read(fd, &buf, BUF_SIZE)) >= 1)
		ft_putstr(buf);
	if (close(fd) == -1 || ret == -1)
		return (2);
	return (0);
}
