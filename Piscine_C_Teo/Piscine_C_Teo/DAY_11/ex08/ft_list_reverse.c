/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:40:09 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/22 08:52:37 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *templist;
	t_list *prev;
	t_list *liste;

	prev = NULL;
	liste = *begin_list;
	while (liste != NULL)
	{
		templist = liste->next;
		liste->next = prev;
		prev = liste;
		liste = templist;
	}
	*begin_list = prev;
}
