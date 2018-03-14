/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 13:06:52 by yewen             #+#    #+#             */
/*   Updated: 2015/10/25 16:07:49 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "solver.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_print_error(void)
{
	write(1, "Erreur\n", 7);
	return (0);
}

int		ft_check_error(char *tab[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		if (ft_strlen(tab[i]) != 9)
			return (0);
		while (j < 9)
		{
			if (((tab[i][j] < '0') || (tab[i][j] > '9')) && (tab[i][j] != '.'))
				return (0);
			if ((tab[i][j] != '.') && (!ft_check_row(tab, i, j, tab[i][j])))
				return (0);
			if ((tab[i][j] != '.') && (!ft_check_col(tab, i, j, tab[i][j])))
				return (0);
			if ((tab[i][j] != '.') && (!ft_check_square(tab, i, j, tab[i][j])))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}
