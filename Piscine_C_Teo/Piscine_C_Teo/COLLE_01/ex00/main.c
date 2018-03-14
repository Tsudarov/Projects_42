/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 14:04:59 by yewen             #+#    #+#             */
/*   Updated: 2015/10/25 21:06:53 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libtab.h"
#include "solver.h"

int		main(int argc, char *argv[])
{
	int		i;
	char	**tab;

	if (argc != 10)
	{
		ft_print_error();
		return (0);
	}
	tab = malloc(72);
	i = 0;
	while (i < 9)
		tab[i++] = malloc(9);
	ft_tabcpy(tab, argv + 1);
	if (ft_check_error(argv + 1) && ft_solve(argv + 1, 0))
	{
		ft_solve_reverse(tab, 0);
		if (ft_tabcmp(tab, argv + 1))
		{
			ft_print_tab(tab);
			return (0);
		}
	}
	ft_print_error();
	return (0);
}
