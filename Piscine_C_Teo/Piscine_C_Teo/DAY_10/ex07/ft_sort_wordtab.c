/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 18:56:31 by tsudarov          #+#    #+#             */
/*   Updated: 2016/04/13 02:27:43 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **tab, char **tab2)
{
	char *tab3;

	tab3 = *tab;
	*tab = *tab2;
	*tab2 = tab3;
}

int		ft_strcmp(char *s1, char *s2)
{
	int ix1;
	int ix2;

	ix1 = 0;
	ix2 = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[ix1] != '\0' && s2[ix2] != '\0' && s1[ix1] == s2[ix2])
	{
		ix1++;
		ix2++;
	}
	return (s1[ix1] - s2[ix2]);
}

void	ft_sort_wordtab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = -1;
		}
		i++;
	}
}
