/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 23:23:51 by tsudarov          #+#    #+#             */
/*   Updated: 2016/03/18 23:57:31 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

struct s_stock_par		*ft_param_to_tab(int ac, char **av)
{
	int			i;
	t_stock_par *tab;

	i = 0;
	tab = (t_stock_par*)malloc(sizeof(t_stock_par) * ac);
	while (i < ac)
	{
		tab[i].size_param = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		tab[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}

char					*ft_strdup(char *src)
{
	int		cpt;
	char	*str;

	cpt = 0;
	while (src[cpt])
		cpt++;
	str = (char*)malloc(sizeof(*src) * (cpt + 1));
	cpt = 0;
	while (src[cpt] != 0)
	{
		str[cpt] = src[cpt];
		cpt++;
	}
	str[cpt] = 0;
	return (str);
}

int						ft_strlen(char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt] != 0)
		cpt++;
	return (cpt);
}
