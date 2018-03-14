/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 12:07:57 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/22 08:38:18 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*liste;
	t_list	*tmp;

	tmp = NULL;
	liste = *begin_list;
	while (liste)
	{
		if ((cmp)(liste->data, data_ref) == 0)
		{
			if (tmp == NULL)
				*begin_list = liste->next;
			else
				tmp->next = liste->next;
			free(liste);
		}
		tmp = liste;
		liste = liste->next;
	}
}
