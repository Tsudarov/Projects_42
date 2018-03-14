/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 00:41:58 by tsudarov          #+#    #+#             */
/*   Updated: 2016/10/07 18:52:10 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	size_t	nb;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	nb = i + ft_strlen(src);
	if ((int)size >= i)
	{
		while (i < (int)size - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
		return (nb);
	}
	return (size + ft_strlen(src));
}
