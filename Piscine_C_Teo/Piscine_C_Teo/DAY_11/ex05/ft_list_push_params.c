/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:07:23 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/25 07:35:16 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *nvelem;

	nvelem = ft_create_elem(data);
	if (*begin_list)
	{
		nvelem->next = *begin_list;
		*begin_list = nvelem;
	}
	else
		*begin_list = nvelem;
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*liste;
	int		i;

	i = 1;
	if (ac <= 0)
		return (NULL);
	liste = ft_create_elem(av[0]);
	while (i < ac)
	{
		ft_list_push_front(&liste, av[i]);
		i++;
	}
	return (liste);
}
