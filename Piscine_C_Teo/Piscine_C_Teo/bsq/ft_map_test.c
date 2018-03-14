/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:50:18 by mulzega           #+#    #+#             */
/*   Updated: 2016/05/27 14:36:12 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_error_message(int a)
{
	if (a == 0)
	{
		ft_putstr("map error");
		return (0);
	}

}

int		ft_check_tab(char **v)
{
	int 	i;
	int		m;

	i = 1;
	m = ft_strlen(v[0]);
	while (v[i])
	{
		if (ft_strlen(v[i]) != m)
			return (0);
		i++;
	}
	return (1);
}

int		ft_map_test_2(char *str, int i)
{
	int		j;
	int 	k;

	j = 0;
	k = 0;
	while (str[j])
	{
		if (str[j] == '\n')
			k++;
		j++;
	}
	if (i != k + 1)
		return (0);
	if (ft_check_tab(ft_split_backslash(str)) == 0)
		return (0);
	return (1);
}

int		ft_map_test(char *str)
{
	int		ijk[3];
	char	*nbr;

	ijk[0] = 0;
	while (str[ijk[0]] >= 48 && str[ijk[0]] <= 57)
		ijk[0]++;
	if ((nbr = (char*)malloc(sizeof(*nbr) * ijk[0])) == NULL)
		return (NULL);
	ijk[1] = ft_atoi(nbr);
	ijk[2] = ijk[0];
	while (str[i++])
	{
		if (str[ijk[0]] != str[ijk[2] + 1] || str[ijk[0]] != str[ijk[2] + 2] ||	
				str[ijk[0]] != '\n' || str[ijk[0]] != '\0')
			return (ft_error_message(0));
	}
	if (ft_map_test_2(*str, ijk[0]) != 1)
		return (ft_error_message(0));
	return (1);
}
