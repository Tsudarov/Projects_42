/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 21:34:57 by tsudarov          #+#    #+#             */
/*   Updated: 2016/10/07 18:52:36 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int size;
	int i;

	size = 0;
	i = -1;
	while (dest[size])
		size++;
	while (src[++i] && i < nb)
		dest[size + i] = src[i];
	dest[size + i] = '\0';
	return (dest);
}
