/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <tsudarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 06:29:09 by tsudarov          #+#    #+#             */
/*   Updated: 2015/10/25 12:52:44 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	techniqueninja(void)
{
	ft_putchar('-');
	ft_putchar('2');
	ft_putchar('1');
	ft_putchar('4');
	ft_putchar('7');
	ft_putchar('4');
	ft_putchar('8');
	ft_putchar('3');
	ft_putchar('6');
	ft_putchar('4');
	ft_putchar('8');
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		techniqueninja();
	if (nb < 0 && nb != -2147483648)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb != -2147483648)
		ft_putchar(nb + '0');
}


void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void putstr(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
        ft_putchar(str[i++])
}
void    ft_putnbr(int nbr)
{
    if (nbr < -2147483648)
        ft_putstr("-2147483648");
    if (nbr > 2147483648)
        ft_putstr("2147483648")
        if (nbr < 0)
        {
            ft_putchar('-');
    nbr = -nbr;
        }
}
