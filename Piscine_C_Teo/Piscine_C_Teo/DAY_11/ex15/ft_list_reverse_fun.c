/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:40:09 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/25 07:34:00 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

static void		ft_swap(t_list **elem1, t_list **elem2)
{
	void			*tmp_data;

	tmp_data = (*elem1)->data;
	(*elem1)->data = (*elem2)->data;
	(*elem2)->data = tmp_data;
}

t_list			*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list				*index;
	unsigned int		i;

	index = begin_list;
	i = 0;
	while (i < nbr)
	{
		if (!index)
			return (NULL);
		index = index->next;
		i++;
	}
	return (index);
}

int				ft_list_size(t_list *begin_list)
{
	t_list		*liste;
	int			i;

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

void			ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;
	int		j;

	i = 0;
	j = ft_list_size(begin_list) - 1;
	while (i <= j && j >= ft_list_size(begin_list) / 2)
	{
		tmp1 = ft_list_at(begin_list, i);
		tmp2 = ft_list_at(begin_list, j);
		ft_swap(&tmp1, &tmp2);
		i++;
		j--;
	}
}
