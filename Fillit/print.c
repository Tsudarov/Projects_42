/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:55:50 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 14:55:52 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit_print(char **tab, t_tetra *tetra)
{
	int			i;
	t_tetra		*tmp;

	while (tetra && tetra->parent)
		tetra = tetra->parent;
	while (tetra)
	{
		tmp = tetra;
		tetra = tetra->next;
		free(tmp);
	}
	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		free(tab[i]);
		ft_putstr("\n");
		i++;
	}
	free(tab);
}
