/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 01:23:10 by tsudarov          #+#    #+#             */
/*   Updated: 2017/10/31 00:54:29 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	raytracer_setup(t_env *en, int x)
{
	en->player.cam_x = 2 * x / (double)WIN_W - 1;
	en->ray.pos.x = en->player.pos.x;
	en->ray.pos.y = en->player.pos.y;
	en->ray.map_pos.x = (int)en->player.pos.x;
	en->ray.map_pos.y = (int)en->player.pos.y;
	en->ray.dir.x = en->player.dir.x + en->player.cplane.x * en->player.cam_x;
	en->ray.dir.y = en->player.dir.y + en->player.cplane.y * en->player.cam_x;
	en->ray.delta_dst.x = sqrt(1 + (en->ray.dir.y * en->ray.dir.y) /
							(en->ray.dir.x * en->ray.dir.x));
	en->ray.delta_dst.y = sqrt(1 + (en->ray.dir.x * en->ray.dir.x) /
							(en->ray.dir.y * en->ray.dir.y));
	en->player.hit = 0;
}

static void	raytracer_direction(t_env *en)
{
	if (en->ray.dir.x < 0)
	{
		en->player.step.x = -1;
		en->ray.side_dst.x =
			(en->ray.pos.x - en->ray.map_pos.x) * en->ray.delta_dst.x;
	}
	else
	{
		en->player.step.x = 1;
		en->ray.side_dst.x =
			(en->ray.map_pos.x + 1.0 - en->ray.pos.x) * en->ray.delta_dst.x;
	}
	if (en->ray.dir.y < 0)
	{
		en->player.step.y = -1;
		en->ray.side_dst.y =
			(en->ray.pos.y - en->ray.map_pos.y) * en->ray.delta_dst.y;
	}
	else
	{
		en->player.step.y = 1;
		en->ray.side_dst.y =
			(en->ray.map_pos.y + 1.0 - en->ray.pos.y) * en->ray.delta_dst.y;
	}
}

static void	raytracer_detect(t_env *en)
{
	while (en->player.hit == 0)
	{
		if (en->ray.side_dst.x < en->ray.side_dst.y)
		{
			en->ray.side_dst.x += en->ray.delta_dst.x;
			en->ray.map_pos.x += en->player.step.x;
			en->player.wall_side = 0;
		}
		else
		{
			en->ray.side_dst.y += en->ray.delta_dst.y;
			en->ray.map_pos.y += en->player.step.y;
			en->player.wall_side = 1;
		}
		if (map_at(en->map, en->ray.map_pos.x, en->ray.map_pos.y) != 0)
			en->player.hit = 1;
	}
}

static void	raytracer_calc(t_env *en)
{
	if (en->player.wall_side == 0)
		en->ray.wall_dst = fabs((en->ray.map_pos.x - en->ray.pos.x +
								(1 - en->player.step.x) / 2) / en->ray.dir.x);
	else
		en->ray.wall_dst = fabs((en->ray.map_pos.y - en->ray.pos.y +
								(1 - en->player.step.y) / 2) / en->ray.dir.y);
	en->ray.draw_hgt = (int)(WIN_H / en->ray.wall_dst);
	en->ray.draw_hgt = en->ray.draw_hgt < 0 ?
								-en->ray.draw_hgt : en->ray.draw_hgt;
	en->ray.draw_st = (-1 * (en->ray.draw_hgt)) / 2 + WIN_H / 2;
	en->ray.draw_nd = en->ray.draw_hgt / 2 + WIN_H / 2;
	en->ray.draw_st = en->ray.draw_st < 0 ? 0 : en->ray.draw_st;
	en->ray.draw_nd = en->ray.draw_nd >= WIN_H ? WIN_H - 1 : en->ray.draw_nd;
	if (en->player.wall_side == 0)
		en->ray.color = en->player.step.x < 0 ? COLOR_WALL1 : COLOR_WALL2;
	else
		en->ray.color = en->player.step.y < 0 ? COLOR_WALL3 : COLOR_WALL4;
}

void		raytracer_main(t_env *en)
{
	t_pointi	coord;
	int			x;

	x = -1;
	if (en->next_img.img || img_make(en) == 0)
		return ;
	while (++x < WIN_W)
	{
		raytracer_setup(en, x);
		raytracer_direction(en);
		raytracer_detect(en);
		raytracer_calc(en);
		coord.x = en->ray.draw_st;
		coord.y = en->ray.draw_nd;
		img_draw_linev(&en->next_img, coord, x, en->ray.color);
	}
}
