/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 19:26:30 by tsudarov          #+#    #+#             */
/*   Updated: 2016/10/05 18:33:50 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = -1;
	dest = (char*)malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	if (dest)
	{
		while (src[++i] != '\0')
			dest[i] = src[i];
		dest[i] = '\0';
	}
	return (dest);
}
