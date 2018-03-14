/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 12:06:41 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/22 08:52:19 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*index;
	unsigned int	i;

	index = begin_list;
	i = 0;
	while (i < nbr)
	{
		if (!index)
			return (NULL);
		index = index->next;
		i++;
	}
	return (index);
}
