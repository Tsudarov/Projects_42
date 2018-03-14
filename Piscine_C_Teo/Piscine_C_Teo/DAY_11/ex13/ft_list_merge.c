/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 12:08:11 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/25 01:09:07 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *liste1;

	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	liste1 = *begin_list1;
	while (liste1->next)
		liste1 = liste1->next;
	liste1->next = begin_list2;
}
