/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 15:23:03 by tsudarov          #+#    #+#             */
/*   Updated: 2017/10/31 00:33:46 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			img_make(t_env *en)
{
	if (!en->mlx)
		return (0);
	if (!(en->next_img.img = mlx_new_image(en->mlx, WIN_W, WIN_H)))
		return (0);
	en->next_img.data = mlx_get_data_addr(en->next_img.img, &en->next_img.bbp,
									&en->next_img.lsize, &en->next_img.end);
	en->next_img.bbp /= 8;
	return (1);
}

void		display_next_img(t_env *en)
{
	if (!en || !en->mlx)
		return ;
	if (en->mlx_img.img)
		mlx_destroy_image(en->mlx, en->mlx_img.img);
	if (!en->next_img.img)
		return ;
	en->mlx_img.img = en->next_img.img;
	en->next_img.img = 0;
	if (en->mlx_win)
		mlx_put_image_to_window(en->mlx, en->mlx_win, en->mlx_img.img, 0, 0);
}

static void	img_draw_point(t_img *img, int x, int y, int color)
{
	int pos;

	if (!img || x < 0 || y < 0 || x > WIN_W || y > WIN_H)
		return ;
	pos = (x * img->bbp) + (y * img->lsize);
	img->data[pos] = color;
	img->data[pos + 1] = color >> 8;
	img->data[pos + 2] = color >> 16;
}

void		img_draw_linev(t_img *img, t_pointi coord, int x, int color)
{
	int y;

	y = 0;
	while (y < coord.x)
		img_draw_point(img, x, y++, COLOR_SKY);
	while (y <= coord.y)
		img_draw_point(img, x, y++, color);
	while (y < WIN_H)
		img_draw_point(img, x, y++, COLOR_FLOOR);
}
