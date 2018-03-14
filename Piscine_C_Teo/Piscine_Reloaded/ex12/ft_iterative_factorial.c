/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:51:32 by tsudarov          #+#    #+#             */
/*   Updated: 2016/11/07 17:03:40 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
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
