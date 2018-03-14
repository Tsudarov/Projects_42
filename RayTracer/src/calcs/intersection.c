/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 23:36:00 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 14:17:28 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "intersection.h"

void		free_list(t_intersection_list *const list)
{
	if (!list)
		return ;
	if (list->next)
		free_list(list->next);
	if (list->data)
		free(list->data);
	free(list);
}

size_t		list_len(const t_intersection_list *const list)
{
	if (!list)
		return (0);
	return (1 + list_len(list->next));
}

static void	list_init_first(
	t_intersection_list **const list,
	const t_intersection *const intersection)
{
	if ((*list = malloc(sizeof(**list))))
	{
		(*list)->next = 0;
		if (((*list)->data = malloc(sizeof(*((*list)->data)))))
			*((*list)->data) = *intersection;
	}
}

void		intersection_list_push_new_back(
	t_intersection_list **const list,
	const t_intersection *const intersection)
{
	t_intersection_list	*list_ptr;

	if (!(*list))
	{
		list_init_first(list, intersection);
		return ;
	}
	list_ptr = *list;
	while (list_ptr->next && list_ptr->data)
		list_ptr = list_ptr->next;
	if (!list_ptr->data)
	{
		if (!(list_ptr->data = malloc(sizeof(*(list_ptr->data)))))
			return ;
		*(list_ptr->data) = *intersection;
		return ;
	}
	if (!(list_ptr->next = malloc(sizeof(*(list_ptr->next)))))
		return ;
	list_ptr = list_ptr->next;
	list_ptr->next = 0;
	if (!(list_ptr->data = malloc(sizeof(*(list_ptr->data)))))
		return ;
	*list_ptr->data = *intersection;
}
