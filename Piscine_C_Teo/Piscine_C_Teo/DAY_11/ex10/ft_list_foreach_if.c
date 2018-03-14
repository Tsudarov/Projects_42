/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 12:07:26 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/22 08:14:21 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	t_list *liste;

	if (begin_list)
	{
		liste = begin_list;
		while (liste)
		{
			if (cmp(liste->data, data_ref) == 0)
				f(liste->data);
			liste = liste->next;
		}
	}
}
