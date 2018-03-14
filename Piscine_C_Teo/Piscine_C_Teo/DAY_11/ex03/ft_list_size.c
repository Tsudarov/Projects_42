/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:05:11 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/22 08:50:19 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int		ft_list_size(t_list *begin_list)
{
	t_list	*liste;
	int		i;

	i = 0;
	if (begin_list)
	{
		liste = begin_list;
		while (liste != NULL)
		{
			liste = liste->next;
			i++;
		}
		return (i);
	}
	else
		return (0);
}
