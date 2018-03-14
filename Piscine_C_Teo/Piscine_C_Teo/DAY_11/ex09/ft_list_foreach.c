/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 12:07:11 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/22 08:37:25 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_foreach(t_list *begin_list, void (*f)(char *))
{
	t_list *liste;

	if (begin_list)
	{
		liste = begin_list;
		while (liste)
		{
			f(liste->data);
			liste = liste->next;
		}
	}
}
