/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:28:10 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/22 05:48:35 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	if ((list = (t_list*)malloc(sizeof(t_list))))
	{
		if ((list->data = malloc(sizeof(data))))
			list->data = data;
		list->next = NULL;
	}
	return (list);
}
