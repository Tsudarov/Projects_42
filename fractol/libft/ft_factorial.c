/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 23:18:21 by tsudarov          #+#    #+#             */
/*   Updated: 2016/10/07 18:47:58 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_factorial(int nb)
{
	int cpt;

	if (nb >= 13 || nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	cpt = nb + 1;
	while (--cpt > 1)
		nb *= (cpt - 1);
	return (nb);
}