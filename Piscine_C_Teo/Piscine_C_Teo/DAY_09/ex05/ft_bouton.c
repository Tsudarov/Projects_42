/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antidote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 21:55:42 by tsudarov          #+#    #+#             */
/*   Updated: 2015/10/22 22:58:12 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_bouton(int i, int j, int k)
{
	if (j < i && i < k || k < i && i < j)
		return (i);
	else if (k < j && j < i || i < j && j < k)
		return (j);
	else if (i < k && k < j || j < k && k < i)
		return (k);
	else 
		return (0);
}
