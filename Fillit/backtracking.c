/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:54:17 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 14:54:21 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fillit_tetra_pose(char **tab, t_tetra *tetra, int nbr_tetra, int j)
{
	if (tab[fillit_pgpy(tetra) + TPX] == 0)
		return (3);
	if ((fillit_pgpx(tetra) + TPY) > fillit_r_carre(nbr_tetra) + j)
		return (2);
	if (tab[TTX1 + TPX][TTY1 + TPY] && tab[TTX2 + TPX][TTY2 + TPY] && tab[TTX3 +
			TPX][TTY3 + TPY] && tab[TTX4 + TPX][TTY4 + TPY] && tab[TTX1 +
			TPX][TTY1 + TPY] == '.' && tab[TTX2 + TPX][TTY2 + TPY] == '.' &&
			tab[TTX3 + TPX][TTY3 + TPY] == '.' && tab[TTX4 + TPX][TTY4 + TPY]
			== '.' && fillit_pgpx(tetra) != -1 && fillit_pgpy(tetra) != -1)
	{
		tab[TTX1 + TPX][TTY1 + TPY] = tetra->name;
		tab[TTX2 + TPX][TTY2 + TPY] = tetra->name;
		tab[TTX3 + TPX][TTY3 + TPY] = tetra->name;
		tab[TTX4 + TPX][TTY4 + TPY] = tetra->name;
		tetra = tetra->next;
		return (1);
	}
	if ((tab[TTX1 + TPX][TTY1 + TPY] != '.') || (tab[TTX2 + TPX][TTY2 + TPY]
				!= '.') || (tab[TTX3 + TPX][TTY3 + TPY] != '.') || (tab[TTX4 +
					TPX][TTY4 + TPY] != '.'))
		return (-1);
	return (0);
}

int			fillit_clean_tetra(t_tetra *tetra, char **tab)
{
	tab[TTX1 + TPX][TTY1 + TPY] = '.';
	tab[TTX2 + TPX][TTY2 + TPY] = '.';
	tab[TTX3 + TPX][TTY3 + TPY] = '.';
	tab[TTX4 + TPX][TTY4 + TPY] = '.';
	return (1);
	return (0);
}

t_tetra		*fillit_backtracking(char **tab, t_tetra *tetra, int i)
{
	while (i != 0)
	{
		if (i == 2)
		{
			TPY = 0;
			TPX = TPX + 1;
			return (tetra);
		}
		if (i == -1)
		{
			TPY = TPY + 1;
			return (tetra);
		}
		if (i == 3)
		{
			TPX = 0;
			TPY = 0;
			tetra = tetra->parent;
			fillit_clean_tetra(tetra, tab);
			TPY = TPY + 1;
			return (tetra);
		}
	}
	return (0);
	fillit_print(tab, tetra);
}

int			fillit_backtracking_start(t_tetra *begin_tetra, int nbr_tetra)
{
	int		i;
	int		j;
	char	**tab;

	j = 0;
	tab = fillit_tableau(nbr_tetra, 0, NULL);
	while (begin_tetra)
	{
		i = fillit_tetra_pose(tab, begin_tetra, nbr_tetra, j);
		if (i == 3 && begin_tetra->name == 'A')
		{
			begin_tetra->position[0] = 0;
			begin_tetra->position[1] = 0;
			tab = fillit_tableau(nbr_tetra, ++j, tab);
		}
		else if (i == 2 || i == -1 || i == 3)
			begin_tetra = fillit_backtracking(tab, begin_tetra, i);
		else if (i == 1)
			begin_tetra = begin_tetra->next;
	}
	fillit_print(tab, begin_tetra);
	return (0);
}
