/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identif_tetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:55:03 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 14:55:12 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_reco_1_12(t_tetra *tmp)
{
	if (ft_memcmp(tmp->point, "\0\0\1\0\1\1\1\2", 8) == 0)
		return (1);
	if (ft_memcmp(tmp->point, "\0\0\0\1\0\2\1\0", 8) == 0)
		return (2);
	if (ft_memcmp(tmp->point, "\0\0\0\1\0\2\1\2", 8) == 0)
		return (3);
	if (ft_memcmp(tmp->point, "\0\0\1\0\2\0\2\1", 8) == 0)
		return (4);
	if (ft_memcmp(tmp->point, "\0\0\0\1\1\0\2\0", 8) == 0)
		return (5);
	if (ft_memcmp(tmp->point, "\0\0\0\1\1\1\2\1", 8) == 0)
		return (6);
	if (ft_memcmp(tmp->point, "\0\1\1\1\2\0\2\1", 8) == 0)
		return (7);
	if (ft_memcmp(tmp->point, "\0\2\1\0\1\1\1\2", 8) == 0)
		return (8);
	if (ft_memcmp(tmp->point, "\0\0\0\1\0\2\0\3", 8) == 0)
		return (9);
	if (ft_memcmp(tmp->point, "\0\0\1\0\2\0\3\0", 8) == 0)
		return (10);
	if (ft_memcmp(tmp->point, "\0\1\1\0\1\1\1\2", 8) == 0)
		return (11);
	if (ft_memcmp(tmp->point, "\0\0\1\0\1\1\2\0", 8) == 0)
		return (12);
	return (0);
}

int			ft_reco_12_19(t_tetra *tmp)
{
	if (ft_memcmp(tmp->point, "\0\1\1\0\1\1\2\1", 8) == 0)
		return (13);
	if (ft_memcmp(tmp->point, "\0\0\0\1\0\2\1\1", 8) == 0)
		return (14);
	if (ft_memcmp(tmp->point, "\0\0\0\1\1\1\1\2", 8) == 0)
		return (15);
	if (ft_memcmp(tmp->point, "\0\1\1\0\1\1\2\0", 8) == 0)
		return (16);
	if (ft_memcmp(tmp->point, "\0\1\0\2\1\0\1\1", 8) == 0)
		return (17);
	if (ft_memcmp(tmp->point, "\0\0\1\0\1\1\2\1", 8) == 0)
		return (18);
	if (ft_memcmp(tmp->point, "\0\0\0\1\1\0\1\1", 8) == 0)
		return (19);
	return (0);
}
