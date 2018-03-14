/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgpxy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:55:27 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 14:55:29 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_uniquetest(t_tetra *tetra)
{
	while (tetra)
	{
		if (ft_reco_1_12(tetra) == 0 && ft_reco_12_19(tetra) == 0)
			return (-1);
		tetra = tetra->next;
	}
	return (0);
}

int			fillit_pgpx(t_tetra *tetra)
{
	int i;
	int j;
	int stop;

	i = 1;
	j = 0;
	stop = 0;
	while (stop < 4)
	{
		if (tetra->point[i] > j)
			j = tetra->point[i];
		i += 2;
		stop++;
	}
	return (j);
}

int			fillit_pgpy(t_tetra *tetra)
{
	int i;
	int j;
	int stop;

	i = 0;
	j = 0;
	stop = 0;
	while (stop < 4)
	{
		if (tetra->point[i] > j)
			j = tetra->point[i];
		i += 2;
		stop++;
	}
	return (j);
}
