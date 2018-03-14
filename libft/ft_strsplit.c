/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2017/06/30 00:40:39 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ct_w(char const *s, char c)
{
	int		i;
	int		nb;

	i = -1;
	nb = 0;
	while (s[++i])
		nb += s[i] == c && s[i + 1] != c;
	return (nb);
}

static int		ct_l(char const *s, char c, int i)
{
	int		len;

	len = 0;
	while (s[i] != c && s[i++])
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	if (s == NULL || !(tab = (char**)malloc(sizeof(char*) * (ct_w(s, c) + 3))))
		return (NULL);
	while (s[i])
	{
		j = 0;
		if (s[i] != c)
		{
			if (!(tab[k] = (char*)malloc(sizeof(char) * (ct_l(s, c, i) + 1))))
				return (NULL);
			while (s[i] != c && s[i])
				tab[k][j++] = s[i++];
			tab[k++][j] = '\0';
		}
		if (s[i] != '\0')
			i++;
	}
	tab[k] = 0;
	return (tab);
}
