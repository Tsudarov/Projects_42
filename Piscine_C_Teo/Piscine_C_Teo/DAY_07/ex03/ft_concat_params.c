/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 00:30:48 by tsudarov          #+#    #+#             */
/*   Updated: 2015/11/06 05:49:45 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(int argc, char **argv)
{
	int i;
	int j;
	int len;

	len = 0;
	i = 0;
	j = 0;
	while (i < argc - 1)
	{
		i++;
		j = 0;
		while (argv[i][j] != '\0')
		{
			len++;
			j++;
		}
	}
	return (len);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*tab;

	i = 0;
	j = 1;
	k = 0;
	len = ft_len(argc, argv);
	tab = (char *)malloc(sizeof(char) * (len + argc));
	if (argc == 0)
		return (0);
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
			tab[k++] = argv[j][i++];
		j++;
		tab[k++] = (j < argc - 1) ? '\n' : '\0';
	}
	return (tab);
}
