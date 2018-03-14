/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:55:56 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 14:55:57 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fillit_r_carre(int i)
{
	int j;

	j = 0;
	if (i < 1)
		return (-1);
	while (j * j < i * 4)
		j++;
	return (j);
}

char		**hydrate_tab(char **tab, int c, int colone, int charac)
{
	int		k;

	k = 0;
	while (k < c)
	{
		tab[colone][k] = charac;
		k++;
	}
	tab[colone][k] = 0;
	return (tab);
}

char		**fillit_tableau(int i, int plus, char **oldtab)
{
	int		c;
	int		j;
	char	**tab;

	j = 0;
	if (oldtab)
		free(oldtab);
	if ((c = fillit_r_carre(i)) == -1)
		return (NULL);
	c = c + plus;
	if (!(tab = ft_memalloc(sizeof(char *) * (c * 10 + 1))))
		return (NULL);
	tab[c + 1] = 0;
	while (j < c)
	{
		if (!(tab[j] = ft_memalloc(sizeof(char) * (c * 10 + 1))))
			return (NULL);
		tab = hydrate_tab(tab, c, j, '.');
		j++;
	}
	return (tab);
}
