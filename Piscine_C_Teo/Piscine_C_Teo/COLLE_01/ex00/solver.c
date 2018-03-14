/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 14:05:17 by yewen             #+#    #+#             */
/*   Updated: 2015/10/25 18:42:18 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

int		ft_check_row(char *tab[], int i, int j, int n)
{
	int	j_check;

	j_check = 0;
	while (j_check < 9)
	{
		if (tab[i][j_check] == n)
			if (j != j_check)
				return (0);
		j_check++;
	}
	return (1);
}

int		ft_check_col(char *tab[], int i, int j, int n)
{
	int	i_check;

	i_check = 0;
	while (i_check < 9)
	{
		if (tab[i_check][j] == n)
			if (i != i_check)
				return (0);
		i_check++;
	}
	return (1);
}

int		ft_check_square(char *tab[], int i, int j, int n)
{
	int	i_check;
	int	j_check;
	int	i2;
	int	j2;

	i2 = i - (i % 3);
	j2 = j - (j % 3);
	i_check = i2;
	j_check = j2;
	while (i_check < i2 + 3)
	{
		while (j_check < j2 + 3)
		{
			if (tab[i_check][j_check] == n)
				if ((i != i_check) || (j != j_check))
					return (0);
			j_check++;
		}
		j_check = j2;
		i_check++;
	}
	return (1);
}

int		ft_solve(char *tab[], int pos)
{
	int	i;
	int	j;
	int	n;

	i = pos / 9;
	j = pos % 9;
	n = 1 + '0';
	if (pos == 81)
		return (1);
	if (tab[i][j] != '.')
		return (ft_solve(tab, pos + 1));
	while (n < 10 + '0')
	{
		if ((ft_check_row(tab, i, j, n)) && (ft_check_col(tab, i, j, n)) \
			&& (ft_check_square(tab, i, j, n)))
		{
			tab[i][j] = n;
			if (ft_solve(tab, pos + 1))
				return (1);
		}
		n++;
	}
	tab[i][j] = '.';
	return (0);
}

int		ft_solve_reverse(char *tab[], int pos)
{
	int	i;
	int	j;
	int	n;

	i = pos / 9;
	j = pos % 9;
	n = 9 + '0';
	if (pos == 81)
		return (1);
	if (tab[i][j] != '.')
		return (ft_solve_reverse(tab, pos + 1));
	while (n > '0')
	{
		if ((ft_check_row(tab, i, j, n)) && (ft_check_col(tab, i, j, n)) \
			&& (ft_check_square(tab, i, j, n)))
		{
			tab[i][j] = n;
			if (ft_solve_reverse(tab, pos + 1))
				return (1);
		}
		n--;
	}
	tab[i][j] = '.';
	return (0);
}
