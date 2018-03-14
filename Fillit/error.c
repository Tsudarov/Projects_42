/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:54:32 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 14:54:34 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		file_valide(char *chaine, int i)
{
	int		j;
	int		k;
	int		l;

	j = i;
	k = 0;
	l = 0;
	while (chaine[j] && j < (i + 20))
	{
		(chaine[j] == '#') ? k++ : k;
		(chaine[j] == '.') ? l++ : l;
		if ((j - i) > 0 && (j - i + 1) % 5 == 0 && chaine[j] != '\n')
			return (-1);
		j++;
	}
	if (k != 4 || l != 12)
		return (-1);
	if (chaine[j] == '\n')
		return (j + 1);
	if (chaine[j] == 0)
		return (0);
	return (-1);
}

int				fillit_test(char *chaine)
{
	int		i;

	i = 0;
	i = file_valide(chaine, i);
	if (i == -1)
		return (-1);
	while (i > 0)
	{
		i = file_valide(chaine, i);
		if (i == -1)
			return (-1);
	}
	return (0);
}
