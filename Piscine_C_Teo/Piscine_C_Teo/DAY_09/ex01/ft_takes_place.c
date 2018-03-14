/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 18:05:50 by tsudarov          #+#    #+#             */
/*   Updated: 2015/10/22 19:48:07 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	if (hour >= 12 && hour <= 23)
	{
		hour = hour - 12;
		printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 P.M", hour);
		hour++;
		if (hour > 11)
		{
			hour = 0;
			printf(". AND %d.00 A.M. \n", hour);
		}
		else
			printf(". AND %d.00 P.M. \n", hour);
	}
	else
	{
		printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 A.M", hour);
		hour++;
		if (hour > 11)
		{
			hour = 0;
			printf(". AND %d.00 P.M. \n", hour);
		}
		else
			printf(". AND %d.00 A.M. \n", hour);
	}
}
