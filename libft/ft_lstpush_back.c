/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:42:56 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/25 04:37:37 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **begin_list, void *content)
{
	t_list *liste;

	liste = *begin_list;
	if (liste)
	{
		while (liste->next)
			liste = liste->next;
		liste->next = ft_lstnew(content, sizeof(content));
	}
	else
		*begin_list = ft_lstnew(content, sizeof(content));
}
