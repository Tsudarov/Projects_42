/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:10:58 by tsudarov          #+#    #+#             */
/*   Updated: 2017/09/16 16:31:07 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			init_env(t_env *e)
{
	e->keycode = 0;
	e->code = -1;
	e->r = 1;
	e->v = 1;
	e->b = 1;
	e->stop = 1;
	e->center.cr = 0;
	e->center.ci = 0;
	e->movepoint = 15;
	e->maxiter = 50;
	ft_init_pos(e, 0, 0);
	ft_init_zoom(e);
	mlx_init_win(&e->mp.mlx, W_FRACTOL_WIDTH, W_FRACTOL_HEIGHT, "fractol");
	mlx_init_pic(e->mp.mlx.mlx, W_FRACTOL_WIDTH, W_FRACTOL_HEIGHT, &e->mp.pic);
	e->col.innt = 0 + (0 << 8) + (0 << 16);
	return (0);
}

void		mlx_help_display(t_env *e)
{
	mlx_string_put(e->mp.mlx.mlx, e->mp.mlx.win, 95, 50, 0x99FF88,
			"HELP");
	mlx_string_put(e->mp.mlx.mlx, e->mp.mlx.win, 40, 80, 0x0000FF,
			"pav num 1,2,3 : Put some r,g,b");
	mlx_string_put(e->mp.mlx.mlx, e->mp.mlx.win, 40, 100, 0x0000FF,
			"1,2,3,4,5,6,7,8,9 : Change fractal");
	mlx_string_put(e->mp.mlx.mlx, e->mp.mlx.win, 40, 120, 0x0000FF,
			"+/- and scroll : Zoom in and out");
	mlx_string_put(e->mp.mlx.mlx, e->mp.mlx.win, 40, 140, 0x0000FF,
			"* and / : Iter more and less");
	mlx_string_put(e->mp.mlx.mlx, e->mp.mlx.win, 40, 160, 0x0000FF,
			"< > ^ v : Movement");
	mlx_string_put(e->mp.mlx.mlx, e->mp.mlx.win, 40, 180, 0x0000FF,
			"space : Stop");
	mlx_string_put(e->mp.mlx.mlx, e->mp.mlx.win, 40, 200, 0x0000FF,
			"ESC : Exit");
}
