/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 21:34:57 by tsudarov          #+#    #+#             */
/*   Updated: 2017/02/12 04:28:13 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		gnl_leaks_gdp(t_list **lst2, char *buf, int ret)
{
	char *tmp;

	buf[ret] = '\0';
	tmp = (*lst2)->content;
	(*lst2)->content = ft_strjoin((*lst2)->content, buf);
	ft_strdel(&tmp);
}

void		gnl_leaks_gdp2(t_list **lst2, char **line)
{
	char	*tmp;
	size_t	len;

	if (ft_strchr((*lst2)->content, '\n'))
	{
		len = ft_strchr((*lst2)->content, '\n') - (char*)(*lst2)->content;
		*line = ft_strsub((*lst2)->content, 0, len);
		tmp = (*lst2)->content;
		(*lst2)->content = ft_strdup(ft_strchr((*lst2)->content, '\n') + 1);
		ft_strdel(&tmp);
	}
	else
	{
		*line = ft_strdup((*lst2)->content);
		ft_strclr((*lst2)->content);
	}
}

t_list		*gnl_check_fd(int fd, t_list **lst1)
{
	t_list *lst2;

	lst2 = *lst1;
	while (lst2)
	{
		if (lst2->content_size == (size_t)fd)
			return (lst2);
		lst2 = lst2->next;
	}
	lst2 = ft_lstnew("", fd);
	ft_lstadd(lst1, lst2);
	return (lst2);
}

void		free_bitch(t_list **begin_list, t_list *to_free)
{
	t_list	*tmp;
	char	*str;

	tmp = *begin_list;
	if (tmp == to_free)
	{
		*begin_list = to_free->next;
		str = to_free->content;
		ft_strdel(&str);
		free(to_free);
		return ;
	}
	while (tmp->next)
	{
		if (tmp->next == to_free)
		{
			tmp->next = to_free->next;
			str = to_free->content;
			ft_strdel(&str);
			free(to_free);
			return ;
		}
	}
}

int			get_next_line(int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	static t_list		*lst1;
	t_list				*lst2;
	int					ret;

	if (fd < 0 || line == NULL)
		return (-1);
	lst2 = gnl_check_fd(fd, &lst1);
	ret = 0;
	while (!(ft_strchr(lst2->content, '\n'))
			&& (ret = read(fd, buf, BUFF_SIZE)) > 0)
		gnl_leaks_gdp(&lst2, buf, ret);
	if (ret == -1)
		return (-1);
	if (ret == 0 && ft_strcmp(lst2->content, "\0") == 0)
	{
		free_bitch(&lst1, lst2);
		return (0);
	}
	gnl_leaks_gdp2(&lst2, line);
	return (1);
}
