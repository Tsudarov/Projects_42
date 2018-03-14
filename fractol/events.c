/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dagnear <Dagnear@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2017/09/16 16:28:55 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void				fractal_loader(t_env *e, int keycode)
{
	ft_reset(e);
	if (keycode == 18)
		fractol_mandelbrot_launcher(e);
	else if (keycode == 19)
		fractol_tricorne_launcher(e);
	else if (keycode == 20)
	{
		e->c.ci = -0.65186;
		e->c.cr = -0.0986;
		fractol_julia_launcher(e);
	}
	else if (keycode == 21)
	{
		e->c.ci = 0.75;
		e->c.cr = -0.00;
		fractol_fractoil_launcher(e);
	}
	else if (keycode == 23)
		fractol_flux_launcher(e);
	else if (keycode == 22)
		fractol_newton_launcher(e);
	else if (keycode == 26)
		fractol_flower_launcher(e);
	else if (keycode == 28)
		fractol_xxx_launcher(e);
}

int					fractol_redraw(t_env *e)
{
	ft_bzero(e->mp.pic.data, W_FRACTOL_WIDTH * W_FRACTOL_HEIGHT *
			e->mp.pic.bpp / 8);
	mlx_clear_window(e->mp.mlx.mlx, e->mp.mlx.win);
	mlx_init_pic(e->mp.mlx.mlx, W_FRACTOL_WIDTH, W_FRACTOL_HEIGHT,
			&e->mp.pic);
	if (e->code == 0)
		fractol_mandelbrot_launcher(e);
	else if (e->code == 2)
		fractol_julia_launcher(e);
	else if (e->code == 3)
		fractol_fractoil_launcher(e);
	else if (e->code == 4)
		fractol_tricorne_launcher(e);
	else if (e->code == 5)
		fractol_flux_launcher(e);
	else if (e->code == 6)
		fractol_newton_launcher(e);
	else if (e->code == 7)
		fractol_flower_launcher(e);
	else if (e->code == 8)
		fractol_xxx_launcher(e);
	fractol_mlx_put_loop(e);
	return (0);
}

void				fractol_event_move(t_env *e)
{
	if (e->keycode == 126)
		e->center.ci -= e->zoom.x * (W_FRACTOL_HEIGHT / 10);
	if (e->keycode == 125)
		e->center.ci += e->zoom.x * (W_FRACTOL_HEIGHT / 10);
	if (e->keycode == 123)
		e->center.cr -= e->zoom.x * (W_FRACTOL_WIDTH / 10);
	if (e->keycode == 124)
		e->center.cr += e->zoom.x * (W_FRACTOL_WIDTH / 10);
}

void				fractol_event_zoom(t_env *e)
{
	if (e->keycode == 78 || e->keycode == 69)
	{
		e->center.ci += (e->mouse.y - W_FRACTOL_HEIGHT / 2) / 5 * e->zoom.x;
		e->center.cr += (e->mouse.x - W_FRACTOL_WIDTH / 2) / 5 * e->zoom.x;
		if (e->keycode == 69)
			e->zoom.x *= 0.85;
		else
			e->zoom.x *= 1.15;
	}
}

int					fractol_evnt_kbd(int keycode, t_env *e)
{
	e->keycode = keycode;
	if (e->keycode == 53)
		ft_exit("What a clean exit");
	else if (e->keycode == 69 || e->keycode == 78)
		fractol_event_zoom(e);
	else if (e->keycode == 75)
		e->maxiter *= 0.85;
	else if (e->keycode == 67)
		e->maxiter *= 1.15;
	else if ((e->keycode >= 18 && e->keycode <= 23) || e->keycode == 26 ||
			e->keycode == 28 || e->keycode == 25)
		fractal_loader(e, keycode);
	else if (e->keycode == 49)
		e->stop = ((e->stop == 1) ? 0 : 1);
	fractol_color(e);
	fractol_event_move(e);
	fractol_redraw(e);
	return (0);
}
