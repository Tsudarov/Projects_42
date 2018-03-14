/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2016/10/03 20:44:34 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*strtmp;

	strtmp = (char*)s;
	i = -1;
	while (++i < (int)n)
	{
		if ((unsigned char)strtmp[i] == (unsigned char)c)
			return ((void*)&strtmp[i]);
	}
	return (NULL);
}
