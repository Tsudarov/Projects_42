/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 21:34:10 by tsudarov          #+#    #+#             */
/*   Updated: 2015/11/01 22:07:59 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt] != 0)
		cpt++;
	return (cpt);
}

char	*ft_strcat(char *dest, char *src)
{
	int cpt;
	int size_dest;
	int size_src;

	cpt = 0;
	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	while (cpt < size_src)
	{
		dest[size_dest + cpt] = src[cpt];
		cpt++;
	}
	dest[size_dest + cpt] = '\0';
	return (dest);
}
