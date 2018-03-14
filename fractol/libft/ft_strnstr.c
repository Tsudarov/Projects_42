/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2016/10/03 21:51:04 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	i = -1;
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[++i] && i < (int)n)
	{
		if (s1[i] == s2[j])
		{
			k = i;
			while (s2[j] == s1[k] && s2[j] != '\0' && k++ < (int)n)
				j++;
			if (s2[j] == '\0')
				return ((char*)&s1[i]);
			else
				j = 0;
		}
	}
	return (NULL);
}
