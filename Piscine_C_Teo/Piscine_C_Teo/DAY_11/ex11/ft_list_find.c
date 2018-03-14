/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 12:07:45 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/22 09:55:55 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *liste;

	if (begin_list)
	{
		liste = begin_list;
		while (liste)
		{
			if (cmp(liste->data, data_ref) == 0)
				return (liste);
			else
				liste = liste->next;
		}
	}
	return (NULL);
}
