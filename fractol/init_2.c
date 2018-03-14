/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:11:06 by tsudarov          #+#    #+#             */
/*   Updated: 2017/09/16 16:11:08 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_init_mouse(t_env *e, double x, double y)
{
	e->mouse.x = x;
	e->mouse.y = y;
}

int			ft_init_c(t_env *e, double r, double i)
{
	e->c.cr = r;
	e->c.ci = i;
	return (0);
}

int			ft_init_z(t_env *e, double r, double i)
{
	e->z.zr = r;
	e->z.zi = i;
	return (0);
}

int			ft_init_pos(t_env *e, int x, int y)
{
	e->pos.x = x;
	e->pos.y = y;
	return (0);
}

int			ft_init_zoom(t_env *e)
{
	e->zoom.x = 0.007;
	return (0);
}
