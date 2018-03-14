/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 15:01:35 by yewen             #+#    #+#             */
/*   Updated: 2015/10/25 15:51:07 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtab.h"
#include "libft.h"

int		ft_tabcmp(char *tab1[], char *tab2[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			if (tab1[i][j] != tab2[i][j])
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int		ft_tabcpy(char *tab1[], char *tab2[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			tab1[i][j] = tab2[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		ft_print_tab(char *tab[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			ft_putchar(tab[i][j]);
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
	return (0);
}
