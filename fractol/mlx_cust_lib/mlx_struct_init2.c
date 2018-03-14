/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_struct_init2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2017/10/07 18:47:16 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_cust.h"

t_col			*mlx_init_col(char r, char v, char b, char t)
{
	t_col		*col;

	if (!(col = malloc(sizeof(*col))))
		return (0);
	col->tab[0] = b;
	col->tab[1] = v;
	col->tab[2] = r;
	col->tab[3] = t;
	return (col);
}
