/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 23:13:24 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/25 17:39:22 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "read.h"
#include "string.h"

static void			free_read(t_read *const readed)
{
	if (readed)
		free_read(readed->next);
	free(readed);
}

static char			fill_tab(t_read *const chained_read,
							t_string *const dst)
{
	const t_read	*read_ptr = chained_read;
	char			*tmp;
	size_t			counter;

	if (!(tmp = malloc(sizeof(*tmp) * dst->size)))
		return (0);
	dst->size = 0;
	while (read_ptr)
	{
		counter = -1;
		while (++counter < read_ptr->ret)
			if (read_ptr->buff[counter] != '\t'
				&& read_ptr->buff[counter] != '\n')
				tmp[dst->size++] = read_ptr->buff[counter];
		read_ptr = read_ptr->next;
	}
	dst->data_ptr = tmp;
	free_read(chained_read->next);
	return (1);
}

static char			convert_chain_to_tab(t_read *const chained_read,
										t_string *const dst)
{
	const t_read	*read_ptr = chained_read;
	size_t			counter;

	dst->size = 1;
	while (read_ptr)
	{
		counter = -1;
		while (++counter < read_ptr->ret)
			dst->size +=
				(read_ptr->buff[counter] != '\t'
				&& read_ptr->buff[counter] != '\n');
		read_ptr = read_ptr->next;
	}
	return (fill_tab(chained_read, dst));
}

char				read_scene_file(const char *const filename,
									t_string *const dst)
{
	t_read			chained_read;
	t_read			*read_ptr;
	const int		fd = open(filename, O_RDONLY);

	if (fd < 0)
		return (0);
	read_ptr = &chained_read;
	while ((read_ptr->ret = read(fd, read_ptr->buff, BUFF_SIZE)) == BUFF_SIZE)
	{
		if (!(read_ptr->next = malloc(sizeof(*read_ptr->next))))
			return (0);
		read_ptr = read_ptr->next;
	}
	read_ptr->next = 0;
	if ((signed)chained_read.ret == -1)
		return (0);
	return (convert_chain_to_tab(&chained_read, dst));
}
