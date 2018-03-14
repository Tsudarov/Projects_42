/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 15:10:45 by tsudarov          #+#    #+#             */
/*   Updated: 2015/10/31 19:20:52 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0')
	{
		ft_putchar(str[a]);
		a++;
	}
}

int		main(int argc, char *argv[])
{
	int rep;

	rep = argc - 1;
	while (rep > 0)
	{
		ft_putstr(argv[rep]);
		ft_putchar('\n');
		rep--;
	}
	return (0);
}
