/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 01:56:59 by tsudarov          #+#    #+#             */
/*   Updated: 2015/11/05 22:22:26 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_alpha(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int		ft_is_upper(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	return (0);
}

int		ft_is_lower(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	se;

	i = 0;
	se = 0;
	while (str[i])
	{
		if (ft_is_lower(str[i]) && se == 0)
			str[i] = str[i] - 32;
		else if (ft_is_upper(str[i]) && se == 1)
			str[i] = str[i] + 32;
		if (!(ft_is_alpha(str[i])))
			se = 0;
		else
			se = 1;
		i++;
	}
	return (str);
}
