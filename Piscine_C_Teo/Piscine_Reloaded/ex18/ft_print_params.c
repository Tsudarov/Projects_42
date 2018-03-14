/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:42:04 by tsudarov          #+#    #+#             */
/*   Updated: 2016/11/07 17:15:16 by tsudarov         ###   ########.fr       */
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

	rep = 1;
	(void)argc;
	while (argv[rep] != '\0')
	{
		ft_putstr(argv[rep]);
		ft_putchar('\n');
		rep++;
	}
	return (0);
}
