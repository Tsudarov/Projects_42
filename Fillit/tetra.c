/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:56:03 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 14:56:04 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetra		*tetra_optimise(t_tetra *tetra)
{
	while (tetra->point[0] > 0 && tetra->point[2] > 0 && tetra->point[4] > 0
			&& tetra->point[6] > 0)
	{
		tetra->point[0]--;
		tetra->point[2]--;
		tetra->point[4]--;
		tetra->point[6]--;
	}
	while (tetra->point[1] > 0 && tetra->point[3] > 0 && tetra->point[5] > 0
			&& tetra->point[7] > 0)
	{
		tetra->point[1]--;
		tetra->point[3]--;
		tetra->point[5]--;
		tetra->point[7]--;
	}
	return (tetra);
}

static t_tetra		*tetra_points(t_tetra *tetra, char si, int j, int *k)
{
	if (si == '#' && *k == 0)
	{
		tetra->point[0] = j / 5 + 1;
		tetra->point[1] = j % 5;
	}
	else if (si == '#' && *k == 1)
	{
		tetra->point[2] = j / 5 + 1;
		tetra->point[3] = j % 5;
	}
	else if (si == '#' && *k == 2)
	{
		tetra->point[4] = j / 5 + 1;
		tetra->point[5] = j % 5;
	}
	else if (si == '#' && *k == 3)
	{
		tetra->point[6] = j / 5 + 1;
		tetra->point[7] = j % 5;
	}
	else if (si == '#' && *k == 4)
		return (NULL);
	if (si == '#')
		*k = *k + 1;
	return (tetra);
}

static t_tetra		*fillit_struct(char *str, int i, int name)
{
	int			j;
	t_tetra		*tetra;
	int			k;

	j = 0;
	k = 0;
	if (!(tetra = malloc(sizeof(t_tetra))))
		return (NULL);
	tetra->name = name;
	tetra->position[0] = 0;
	tetra->position[1] = 0;
	tetra->position[2] = 0;
	tetra->parent = NULL;
	tetra->next = NULL;
	while (j < 20 && str[i + j])
	{
		if (!(tetra = tetra_points(tetra, str[i + j], j + 1, &k)))
			return (NULL);
		tetra->point[8] = 0;
		j++;
	}
	if (!(tetra = tetra_optimise(tetra)))
		return (NULL);
	return (tetra);
}

static t_tetra		*push_tetra(t_tetra *tetra, t_tetra *tetra_begin)
{
	t_tetra		*voyage;

	voyage = tetra_begin;
	while (voyage->next)
		voyage = voyage->next;
	voyage->next = tetra;
	tetra->parent = voyage;
	return (tetra_begin);
}

int					fillit_tetra(char *string)
{
	int			i;
	int			name;
	t_tetra		*tetra;
	t_tetra		*tetra_begin;

	i = 0;
	name = 'A';
	tetra_begin = NULL;
	while (string[i])
	{
		if (!(tetra = fillit_struct(string, i, name)) || name > 'Z')
			return (-1);
		i = i + 21;
		name++;
		if (tetra_begin == NULL)
			tetra_begin = tetra;
		else
			tetra_begin = push_tetra(tetra, tetra_begin);
		if (!string[i - 1])
			break ;
	}
	if (ft_uniquetest(tetra_begin) == -1)
		return (-1);
	i = fillit_backtracking_start(tetra_begin, tetra->name - 'A' + 1);
	return (i);
}
