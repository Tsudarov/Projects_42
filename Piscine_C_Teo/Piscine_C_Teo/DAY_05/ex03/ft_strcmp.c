/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 00:41:58 by tsudarov          #+#    #+#             */
/*   Updated: 2015/11/01 21:46:03 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int index1;
	int index2;

	index1 = 0;
	index2 = 0;
	while (s1[index1] != '\0' && s2[index2] != '\0' && s1[index1] == s2[index2])
	{
		index1++;
		index2++;
	}
	return (s1[index1] - s2[index2]);
}
