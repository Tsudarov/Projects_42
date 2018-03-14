/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 21:43:23 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/09 02:04:20 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *tabr;

	i = 0;
	tabr = (int *)malloc(sizeof(int) * length);
	while (i <= length)
	{
		tabr[i] = f(tab[i]);
		i++;
	}
	return (tabr);
}
