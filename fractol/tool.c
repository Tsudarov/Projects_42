/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:02:52 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 15:02:53 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fractol.h"

int			ft_usage(int i)
{
	if (i == 0)
	{
		ft_putstr("Fractol usage: ./fractol[mandelbrotjulia");
		ft_exit("/fractoil/tricorne/xxx/flux/newton/flower]");
		return (0);
	}
	else
		ft_putstr("Fractol usage: ./fractol[mandelbrotjulia");
	ft_putendl("/fractoil/tricorne/xxx/flux/newton/flower]");
	ft_exit("Unknown Fractal !");
	return (0);
}

int			fractol_mouse_hook(int x, int y, t_env *e)
{
	if (e->stop)
	{
		e->c.ci += (y - e->mouse.y) / W_FRACTOL_HEIGHT * e->zoom.x * 100;
		e->c.cr += (x - e->mouse.x) / W_FRACTOL_WIDTH * e->zoom.x * 100;
	}
	e->mouse.x = x;
	e->mouse.y = y;
	fractol_redraw(e);
	return (0);
}

int			ft_exit(char *str)
{
	if (str)
		ft_putendl(str);
	exit(1);
	return (0);
}

int			fractol_event_expose(t_env *e)
{
	mlx_put_image_to_window(e->mp.mlx.mlx, e->mp.mlx.win,
			e->mp.pic.image, 0, 0);
	mlx_help_display(e);
	return (0);
}

int			fractol_mlx_put_loop(t_env *e)
{
	mlx_put_image_to_window(e->mp.mlx.mlx, e->mp.mlx.win,
			e->mp.pic.image, 0, 0);
	mlx_help_display(e);
	mlx_expose_hook(e->mp.mlx.win, &fractol_event_expose, e);
	return (0);
}
