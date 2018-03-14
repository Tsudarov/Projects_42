/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 21:34:22 by tsudarov          #+#    #+#             */
/*   Updated: 2015/11/06 05:47:18 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tableau;
	int index;

	index = 0;
	if (min >= max)
		return (NULL);
	if (!(tableau = (int*)malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (index < max - min)
	{
		tableau[index] = min + index;
		index++;
	}
	return (tableau);
}
