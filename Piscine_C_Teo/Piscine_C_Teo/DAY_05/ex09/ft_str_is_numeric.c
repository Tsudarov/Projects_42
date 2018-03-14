/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 21:13:39 by tsudarov          #+#    #+#             */
/*   Updated: 2015/11/01 22:16:56 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	int index;

	index = 0;
	if (str[0] == '\0')
		return (1);
	while (str[index] != '\0')
	{
		if ((str[index] >= 48 && str[index] <= 57))
		{
			index++;
		}
		else
			return (0);
	}
	return (1);
}
