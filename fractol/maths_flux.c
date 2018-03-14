/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_flux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:02:06 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 15:02:10 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void			fractol_flux_math(t_env *e, int i, t_c z)
{
	double		tmp;

	ft_init_z(e, 1, 1);
	ft_init_c(e, z.cr, z.ci);
	i = -1;
	while ((e->z.zr * e->z.zr) + (e->z.zi * e->z.zi) < 4 && ++i < e->maxiter)
	{
		tmp = e->z.zr / 2;
		ft_init_z(e, ((e->z.zr * e->z.zr - 2) + (2 - e->z.zi * e->z.zi) -
					e->c.cr), 1 - (2 * e->z.zi * tmp + e->c.ci));
		ft_init_c(e, e->mouse.x / W_FRACTOL_WIDTH, e->mouse.y /
				W_FRACTOL_HEIGHT);
	}
	e->col.innt = ((i >= e->maxiter) ? 15 + (20 << 8) + (20 << 16) :
			e->r + i * 15 + ((e->v + i * 15) << 8) + ((e->b + i * 5) << 16));
	mlx_img_drwpoint(&e->pos, &e->mp, &e->col);
}

int				fractol_flux_launcher(t_env *e)
{
	int			i;
	t_c			z;

	e->pos.x = -1;
	e->code = 5;
	i = -1;
	z.cr = e->center.cr - W_FRACTOL_WIDTH / 2 * e->zoom.x;
	z.ci = e->center.ci - W_FRACTOL_HEIGHT / 2 * e->zoom.x;
	while (++e->pos.x < W_FRACTOL_WIDTH)
	{
		z.ci = e->center.ci - W_FRACTOL_HEIGHT / 2 * e->zoom.x;
		e->pos.y = -1;
		while (++e->pos.y < W_FRACTOL_HEIGHT)
		{
			fractol_flux_math(e, i, z);
			z.ci += e->zoom.x;
		}
		z.cr += e->zoom.x;
	}
	return (0);
}
