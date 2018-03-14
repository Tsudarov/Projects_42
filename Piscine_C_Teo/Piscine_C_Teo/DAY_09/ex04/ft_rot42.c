/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 21:39:34 by tsudarov          #+#    #+#             */
/*   Updated: 2015/10/22 21:44:50 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ReverseStr(char *machaine)
{
	char *c = machaine + strlen(machaine) - 1;
	char tmp;

	while (machaine < c)
	{
		tmp = *machaine;
		*machaine++ = *c;
		*c-- = tmp;
	}
}
