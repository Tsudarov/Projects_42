/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2017/10/07 18:47:16 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			**fdf_check_map_gdp(char *map, int **mapconv, int ijk[2],
		int sizeline)
{
	ijk[1] = -1;
	if (!(mapconv[ijk[2]] = malloc(sizeof(**mapconv) * (sizeline + 1))))
		return (0);
	while (++ijk[1] < sizeline)
	{
		while (map[++(ijk[0])] && map[ijk[0]] != '-' &&
				!ft_isdigit(map[ijk[0]]))
			if (map[ijk[0]] == '\n')
				return (ft_error(ijk[2]));
		mapconv[ijk[2]][ijk[1]] = ft_atoi(&map[ijk[0]]);
		while (ft_isdigit(map[++(ijk[0])]))
			;
	}
	while (map[ijk[0]] == ' ' || map[ijk[0]] == '\t')
		ijk[0]++;
	if (map[ijk[0]] && map[ijk[0]] != '\n')
		return (ft_error(ijk[2]));
	return (mapconv);
}

int			**fdf_check_map(char *map, int *const sizeline, int *const nbline)
{
	int		**mapconv;
	int		ijk[3];

	ijk[0] = 0;
	ijk[2] = -1;
	while (map[ijk[0]] && map[ijk[0]] != '\n')
		*sizeline += ft_isdigit(map[ijk[0]++]) && !ft_isdigit(map[ijk[0]]);
	while (map[ijk[0]])
		*nbline += map[ijk[0]++] == '\n';
	ijk[0] = -1;
	if (!(mapconv = malloc(sizeof(*mapconv) * (*nbline))))
		return (0);
	while (++ijk[2] < *nbline - 1)
		if (!(mapconv = fdf_check_map_gdp(map, mapconv, ijk, *sizeline)))
			return (0);
	free(map);
	mapconv[ijk[2]] = NULL;
	return (mapconv);
}

char		*fdf_read_2(char *argv, t_read *ptr, int i)
{
	int		fd;
	t_read	*list;

	list = ptr;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	while ((list->len = read(fd, list->line, BUFFER_SIZE)) == BUFFER_SIZE)
	{
		if (!(list->next = malloc(sizeof(*list->next))))
			return (0);
		list = list->next;
	}
	if (list->len <= -1)
		return (0);
	list->next = NULL;
	list = ptr;
	while (list)
	{
		i += list->len;
		list = list->next;
	}
	return (malloc(sizeof(char) * (i + 1)));
}

int			**fdf_read(char *argv, int *const sizeline, int *const nbline)
{
	t_read	list;
	t_read	*ptr;
	char	*map;
	size_t	i;
	size_t	j;

	i = 0;
	*nbline = 1;
	*sizeline = 0;
	ptr = &list;
	if ((map = fdf_read_2(argv, ptr, i)) == 0)
		return (0);
	while (ptr)
	{
		j = 0;
		while (j < (unsigned)ptr->len)
			map[i++] = ptr->line[j++];
		ptr = ptr->next;
	}
	map[i] = '\0';
	destroy_list(list.next);
	return (fdf_check_map(map, sizeline, nbline));
}
