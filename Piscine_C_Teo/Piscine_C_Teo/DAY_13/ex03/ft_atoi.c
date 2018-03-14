/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 23:26:38 by tsudarov          #+#    #+#             */
/*   Updated: 2016/05/02 04:50:25 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_atoi(char *str)
{
	int	resultat;
	int negatif;

	negatif = 1;
	resultat = 0;
	if (str == NULL || str[0] == '\0')
		return (resultat);
	while (str[0] == '\n' || str[0] == ' ' || str[0] == '\t')
		str++;
	if (*str == '-')
		negatif = -1;
	while (*str && *str >= 48 && *str <= 57)
	{
		resultat = resultat * 10 + (*str - '0');
		str++;
	}
	return (resultat * negatif);
}
