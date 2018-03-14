/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 21:23:50 by tsudarov          #+#    #+#             */
/*   Updated: 2015/11/05 22:22:52 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int index;

	index = 0;
	if (str[index] == '\0')
		return (1);
	else
	{
		while (str[index])
		{
			if (str[index] < 32 || str[index] == 127)
				return (0);
			index++;
		}
		return (1);
	}
}
