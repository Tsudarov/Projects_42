/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2016/10/05 18:37:06 by tsudarov         ###   ########.fr       */
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
	if (n < 0)
	{
		size++;
		i = -n;
	}
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[size] = '\0';
	if (i == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (i == 0)
		return (ft_strcpy(str, "0"));
	str[--size] = i % 10 + '0';
	while (i /= 10)
		str[--size] = i % 10 + '0';
	return (str);
}
