/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 14:31:35 by tsudarov          #+#    #+#             */
/*   Updated: 2015/10/31 19:20:08 by tsudarov         ###   ########.fr       */
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
