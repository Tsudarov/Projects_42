/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:42:56 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/23 02:57:30 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpush_front(t_list **begin_list, void *content)
{
	t_list *nvelem;

	nvelem = ft_lstnew(content, sizeof(content));
	if (*begin_list)
	{
		nvelem->next = *begin_list;
		*begin_list = nvelem;
	}
	else
		*begin_list = nvelem;
}
