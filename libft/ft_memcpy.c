/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:46:00 by tsudarov          #+#    #+#             */
/*   Updated: 2016/10/05 18:31:08 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;
	int		i;

	i = -1;
	if (n == 0 || dst == src)
		return (dst);
	s = (char*)src;
	d = (char*)dst;
	while (++i < (int)n)
		d[i] = s[i];
	return (dst);
}
