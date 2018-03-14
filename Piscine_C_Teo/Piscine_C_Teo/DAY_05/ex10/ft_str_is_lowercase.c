/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 21:21:07 by tsudarov          #+#    #+#             */
/*   Updated: 2015/11/01 22:17:07 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int index;

	index = 0;
	if (str[0] == '\0')
		return (1);
	while (str[index] != '\0')
	{
		if ((str[index] >= 97 && str[index] <= 122))
		{
			index++;
		}
		else
			return (0);
	}
	return (1);
}
