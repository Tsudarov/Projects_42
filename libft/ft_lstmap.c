/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2016/10/03 20:48:58 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *liste;
	t_list *nw;

	if (lst != NULL)
	{
		liste = ft_lstnew(lst->content, lst->content_size);
		liste = f(liste);
		nw = liste;
		while (lst->next)
		{
			lst = lst->next;
			nw->next = ft_lstnew(lst->content, lst->content_size);
			nw->next = f(nw->next);
			nw = nw->next;
		}
		return (liste);
	}
	return (NULL);
}
