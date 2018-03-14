/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:03:06 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 15:03:09 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				fractol_color(t_env *e)
{
	if (e->keycode == 83 && e->b <= 250)
	{
		if (e->b > 250)
			e->b = 1;
		e->b += 5;
	}
	else if (e->keycode == 84 && e->v <= 250)
	{
		if (e->v > 250)
			e->v = 1;
		e->v += 5;
	}
	else if (e->keycode == 85 && e->r <= 250)
	{
		if (e->r > 250)
			e->r = 1;
		e->r += 5;
	}
}

void				ft_reset(t_env *e)
{
	e->r = 1;
	e->v = 1;
	e->b = 1;
	e->center.cr = 0;
	e->center.ci = 0;
	ft_init_zoom(e);
	e->maxiter = 50;
}

int					mouse_scroll(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == 4 || button == 5)
	{
		e->center.ci += (e->mouse.y - W_FRACTOL_HEIGHT / 2) / 5 * e->zoom.x;
		e->center.cr += (e->mouse.x - W_FRACTOL_WIDTH / 2) / 5 * e->zoom.x;
		if (button == 5)
			e->zoom.x *= 0.85;
		else
			e->zoom.x *= 1.15;
		fractol_redraw(e);
	}
	return (0);
}
