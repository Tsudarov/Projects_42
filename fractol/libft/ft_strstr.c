/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 20:16:37 by tsudarov          #+#    #+#             */
/*   Updated: 2016/10/07 18:53:19 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[++i])
	{
		if (s1[i] == s2[j])
		{
			while (s2[j] == s1[i + j] && s2[j] != '\0')
				j++;
			if (s2[j] == '\0')
				return ((char*)&s1[i]);
			else
				j = 0;
		}
	}
	return (0);
}
