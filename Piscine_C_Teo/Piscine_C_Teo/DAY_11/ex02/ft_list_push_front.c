/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:42:56 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/23 02:57:30 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *nvelem;

	nvelem = ft_create_elem(data);
	if (*begin_list)
	{
		nvelem->next = *begin_list;
		*begin_list = nvelem;
	}
	else
		*begin_list = nvelem;
}
