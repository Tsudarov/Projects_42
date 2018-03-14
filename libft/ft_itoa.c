/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2018/02/27 14:28:42 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	int		i;

	i = n;
	size = ft_numlen(n);
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	if (i == 0)
		return (strcpy(str, "0"));
	str[--size] = i % 10 + '0';
	while (i /= 10)
		str[--size] = i % 10 + '0';
	return (str);
}
