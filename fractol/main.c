/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:11:12 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 15:42:45 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

int				ft_fractal_launcher_2(t_env *e, char **argv)
{
	if (ft_strcmp(argv[1], "xxx") == 0)
	{
		e->c.cr = 0.283158;
		e->c.ci = 0.475833;
		fractol_xxx_launcher(e);
	}
	else if (ft_strcmp(argv[1], "flux") == 0)
		fractol_flux_launcher(e);
	else if (ft_strcmp(argv[1], "newton") == 0)
		fractol_newton_launcher(e);
	else if (ft_strcmp(argv[1], "flower") == 0)
		fractol_flower_launcher(e);
	else
		return (0);
	return (1);
}

int				ft_fractal_launcher(t_env *e, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		fractol_mandelbrot_launcher(e);
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		e->c.ci = -0.65186;
		e->c.cr = -0.0986;
		fractol_julia_launcher(e);
	}
	else if (ft_strcmp(argv[1], "fractoil") == 0)
	{
		e->c.ci = 0.75;
		e->c.cr = -0.00;
		fractol_fractoil_launcher(e);
	}
	else if (ft_strcmp(argv[1], "tricorne") == 0)
		fractol_tricorne_launcher(e);
	else
		return (0);
	return (1);
}

int				main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
		ft_usage(0);
	if (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1], "tricorne")
			!= 0 && ft_strcmp(argv[1], "julia") != 0 && ft_strcmp(argv[1],
				"fractoil") != 0 && ft_strcmp(argv[1], "flux") != 0 &&
			ft_strcmp(argv[1], "newton") != 0 && ft_strcmp(argv[1], "flower")
			!= 0 && ft_strcmp(argv[1], "xxx"))
	{
		ft_usage(1);
		return (0);
	}
	init_env(&e);
	ft_init_mouse(&e, 0, 0);
	ft_init_zoom(&e);
	ft_fractal_launcher(&e, argv);
	ft_fractal_launcher_2(&e, argv);
	mlx_hook(e.mp.mlx.win, 2, (1L << 0), fractol_evnt_kbd, &e);
	mlx_hook(e.mp.mlx.win, 6, (1L << 6), fractol_mouse_hook, &e);
	mlx_hook(e.mp.mlx.win, 4, (1L << 2), mouse_scroll, &e);
	fractol_mlx_put_loop(&e);
	mlx_loop(e.mp.mlx.mlx);
	return (0);
}
