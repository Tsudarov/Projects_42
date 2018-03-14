/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_flower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:02:01 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 15:02:02 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void			fractol_flower_math(t_env *e, int i, t_c z)
{
	double		oldr;
	double		oldi;
	double		tmp;

	ft_init_z(e, z.cr, z.ci);
	i = -1;
	tmp = 2.0;
	while (tmp > 0.000001 && ++i < e->maxiter)
	{
		oldr = e->z.zr;
		oldi = e->z.zi;
		tmp = (e->z.zr * e->z.zr + e->z.zi * e->z.zi) *
			(e->z.zr * e->z.zr + e->z.zi * e->z.zi);
		ft_init_z(e,
				(2 * e->z.zr * -tmp + e->z.zr * e->z.zr - e->z.zi * e->z.zi)
				/ (3.0 * tmp), (2 * e->z.zi * (tmp - oldr)) / (3.0 * tmp));
		tmp = (e->z.zr - oldr) * (e->z.zr - oldr) + (e->z.zi - oldi) *
			(e->z.zi - oldi);
	}
	e->col.innt = ((i >= e->maxiter) ? 0 + (0 << 8) + (0 << 16) :
			e->r + i * 250 + ((e->v + i * 25) << 16) + ((e->b + i * 25) << 16));
	mlx_img_drwpoint(&e->pos, &e->mp, &e->col);
}

int				fractol_flower_launcher(t_env *e)
{
	int			i;
	t_c			z;

	e->pos.x = -1;
	i = -1;
	e->code = 7;
	z.cr = e->center.cr - W_FRACTOL_WIDTH / 2 * e->zoom.x;
	z.ci = e->center.ci - W_FRACTOL_HEIGHT / 2 * e->zoom.x;
	while (++e->pos.x < W_FRACTOL_WIDTH)
	{
		z.ci = e->center.ci - W_FRACTOL_HEIGHT / 2 * e->zoom.x;
		e->pos.y = -1;
		while (++e->pos.y < W_FRACTOL_HEIGHT)
		{
			fractol_flower_math(e, i, z);
			z.ci += e->zoom.x;
		}
		z.cr += e->zoom.x;
	}
	return (0);
}
