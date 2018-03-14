/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:55:20 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 14:55:22 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		fillit_getline(const int fd, char **line)
{
	int				read_int;
	char			tab[BUFF_SIZE];
	char			*file;
	char			*swap;

	if (!(file = malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	file[0] = 0;
	read_int = BUFF_SIZE;
	while (read_int == BUFF_SIZE)
	{
		if (-1 == (read_int = read(fd, tab, BUFF_SIZE)))
			return (-1);
		if (!(swap = ft_memalloc(sizeof(char) * (read_int + ft_strlen(file)
							+ 1))))
			return (-1);
		ft_strncpy(swap, file, (ft_strlen(file) + read_int + 1));
		ft_strlcat(swap, tab, (ft_strlen(file) + read_int + 1));
		free(file);
		file = swap;
		swap = NULL;
	}
	*line = file;
	return (0);
}

static void		fillit_usage(void)
{
	ft_putstr("usage : fillit source_file\n");
}

static void		fillit_error(void)
{
	ft_putstr("error\n");
}

int				main(int argc, char **argv)
{
	int				file_id;
	char			*file;

	if (argc != 2)
	{
		fillit_usage();
		return (0);
	}
	file_id = open(argv[1], O_RDONLY);
	if (fillit_getline(file_id, &file) == -1)
		fillit_error();
	else if (fillit_test(file) == -1)
		fillit_error();
	else if (fillit_tetra(file) == -1)
		fillit_error();
	return (0);
}
