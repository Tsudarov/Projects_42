/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:46:00 by tsudarov          #+#    #+#             */
/*   Updated: 2016/10/07 18:35:12 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char*c1;
	char*c2;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (dst > src)
	{
		if (len == 0)
			return (dst);
		c1 = (char *)dst;
		c2 = (char *)src;
		while (len--)
			c1[len] = c2[len];
	}
	return (dst);
}
