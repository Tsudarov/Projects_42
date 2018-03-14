/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 20:16:37 by tsudarov          #+#    #+#             */
/*   Updated: 2015/11/05 22:21:55 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*ret;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == to_find[j])
		{
			while (to_find[j] == str[i + j] && to_find[j] != '\0')
			{
				j++;
			}
			if (to_find[j] == '\0')
			{
				ret = &str[i];
				return (ret);
			}
			else
				j = 0;
		}
		i++;
	}
	return (0);
}
