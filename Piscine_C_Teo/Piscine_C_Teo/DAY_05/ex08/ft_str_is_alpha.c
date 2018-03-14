/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:26:30 by tsudarov          #+#    #+#             */
/*   Updated: 2015/11/01 22:16:38 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int index;

	index = 0;
	if (str[0] == '\0')
		return (1);
	while (str[index] != '\0')
	{
		if ((str[index] >= 65 && str[index] <= 90)
				|| (str[index] >= 97 && str[index] <= 122))
		{
			index++;
		}
		else
			return (0);
	}
	return (1);
}
