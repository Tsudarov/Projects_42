/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 19:11:20 by tsudarov          #+#    #+#             */
/*   Updated: 2015/11/06 05:47:05 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		index++;
		return (index);
	}
}

char	*ft_strdup(char *src)
{
	int		index;
	char	*str;

	index = 0;
	str = (char*)malloc(sizeof(src) * (ft_strlen(src) + 1));
	while (str[index])
	{
		str[index] = src[index];
		index++;
	}
	free(str);
	return (str);
}
