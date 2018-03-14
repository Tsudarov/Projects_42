/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:07:13 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/22 08:51:58 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list *liste;

	if (begin_list)
	{
		liste = begin_list;
		while (liste->next != NULL)
		{
			liste = liste->next;
		}
		return (liste);
	}
	return (NULL);
}
