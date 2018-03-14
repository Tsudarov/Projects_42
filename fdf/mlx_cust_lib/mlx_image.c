/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2017/10/07 18:47:16 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_cust.h"
#define X ft_abso(s->x - e->x)
#define Y ft_abso(s->y - e->y)

void			mlx_img_drwpoint(const t_pos *xy, const t_mlx_pic *mp,
		t_col *col)
{
	if (xy->x < WINDOW_WIDTH_H && xy->x > 0 && xy->y < WINDOW_HEIGHT_H &&
			xy->y > 0)
	{
		if (xy->x >= 0 && xy->x < mp->mlx->width &&
				xy->y >= 0 && xy->y < mp->mlx->height)
			mp->pic->data[(xy->x * mp->pic->bpp) /
				(8 * sizeof(*mp->pic->data)) +
				(xy->y * mp->pic->size_line) / sizeof(*mp->pic->data)] =
				mlx_get_color_value(mp->mlx->mlx, col->innt);
	}
}

void			mlx_img_drwline(t_pos *s, t_pos *e, const t_mlx_pic *mp,
		t_col *col)
{
	int			i;
	t_pos		xy;
	int const	max = X < Y ? Y : X;

	i = -1;
	while (i++ < max)
	{
		xy.x = s->x + (i * (e->x - s->x) / (max + 1));
		xy.y = s->y + (i * (e->y - s->y) / (max + 1));
		mlx_img_drwpoint(&xy, mp, col);
	}
}
