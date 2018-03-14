/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 23:19:20 by tsudarov          #+#    #+#             */
/*   Updated: 2015/10/27 23:19:22 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int res;
	int a;

	a = 1;
	res = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (a < power)
	{
		nb = nb * res;
		a++;
	}
	return (nb);
}
