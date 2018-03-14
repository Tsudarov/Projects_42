/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 12:08:34 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/25 04:02:58 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*liste1;
	void	*tmp;

	if ((*begin_list) && cmp)
	{
		liste1 = *begin_list;
		while (liste1->next)
		{
			if (cmp(liste1->data, liste1->next->data) > 0)
			{
				tmp = liste1->data;
				liste1->data = liste1->next->data;
				liste1->next->data = tmp;
				liste1 = *begin_list;
			}
			else
				liste1 = liste1->next;
		}
	}
}
