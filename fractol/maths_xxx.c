/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_xxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:02:44 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 15:02:45 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void			fractol_xxx_math(t_env *e, int i, t_c z)
{
	double		tmp;

	ft_init_z(e, z.cr, z.ci);
	ft_init_c(e, 0.283158, 0.475833);
	i = 0;
	while ((e->z.zr * e->z.zr) + (e->z.zi * e->z.zi) < 4 &&
			i < e->maxiter)
	{
		tmp = e->z.zr;
		ft_init_z(e, ((e->z.zr * e->z.zr) - (e->z.zi * e->z.zi) +
					e->c.cr), 2 * e->z.zi * tmp + e->c.ci);
		i++;
	}
	e->col.innt = ((i >= e->maxiter) ? 45 + (45 << 8) + (35 << 16) :
			e->r + i * 15 + ((e->v + i * 50) << 8) + ((e->b + i * 8) << 16));
	mlx_img_drwpoint(&e->pos, &e->mp, &e->col);
}

int				fractol_xxx_launcher(t_env *e)
{
	int			i;
	t_c			z;

	i = -1;
	e->pos.x = -1;
	e->code = 8;
	z.cr = e->center.cr - W_FRACTOL_WIDTH / 2 * e->zoom.x;
	z.ci = e->center.ci - W_FRACTOL_HEIGHT / 2 * e->zoom.x;
	while (++e->pos.x < W_FRACTOL_WIDTH)
	{
		e->pos.y = -1;
		z.ci = e->center.ci - W_FRACTOL_HEIGHT / 2 * e->zoom.x;
		while (++e->pos.y < W_FRACTOL_HEIGHT)
		{
			fractol_xxx_math(e, i, z);
			z.ci += e->zoom.x;
		}
		z.cr += e->zoom.x;
	}
	return (0);
}
