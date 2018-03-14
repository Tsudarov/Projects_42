/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 01:22:37 by tsudarov          #+#    #+#             */
/*   Updated: 2017/10/31 00:59:09 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	move_forward(t_env *en)
{
	double speed;

	speed = en->time.move_spd * (en->player.sprint == 1 ? 2 : 1);
	if (map_at(en->map,
			(int)(en->player.pos.x + en->player.dir.x * speed),
			(int)(en->player.pos.y)) == 0)
		en->player.pos.x += en->player.dir.x * speed;
	if (map_at(en->map,
			(int)(en->player.pos.x),
			(int)(en->player.pos.y + en->player.dir.y * speed)) == 0)
		en->player.pos.y += en->player.dir.y * speed;
}

static void	move_backward(t_env *en)
{
	double speed;

	speed = en->time.move_spd * (en->player.sprint == 1 ? 2 : 1);
	if (map_at(en->map,
			(int)(en->player.pos.x - en->player.dir.x * speed),
			(int)(en->player.pos.y)) == 0)
		en->player.pos.x -= en->player.dir.x * speed;
	if (map_at(en->map,
			(int)(en->player.pos.x),
			(int)(en->player.pos.y - en->player.dir.y * speed)) == 0)
		en->player.pos.y -= en->player.dir.y * speed;
}

static void	move_left(t_env *en)
{
	double old_dir;
	double old_plane;
	double cos_sp;
	double sin_sp;

	old_dir = en->player.dir.x;
	old_plane = en->player.cplane.x;
	cos_sp = cos(1 * en->time.rot_spd);
	sin_sp = sin(1 * en->time.rot_spd);
	en->player.dir.x = en->player.dir.x * cos_sp - en->player.dir.y * sin_sp;
	en->player.dir.y = old_dir * sin_sp + en->player.dir.y * cos_sp;
	en->player.cplane.x = en->player.cplane.x * cos_sp -
			en->player.cplane.y * sin_sp;
	en->player.cplane.y = old_plane * sin_sp + en->player.cplane.y * cos_sp;
}

static void	move_right(t_env *en)
{
	double old_dir;
	double old_plane;
	double cos_sp;
	double sin_sp;

	old_dir = en->player.dir.x;
	old_plane = en->player.cplane.x;
	cos_sp = cos(-1 * en->time.rot_spd);
	sin_sp = sin(-1 * en->time.rot_spd);
	en->player.dir.x = en->player.dir.x * cos_sp - en->player.dir.y * sin_sp;
	en->player.dir.y = old_dir * sin_sp + en->player.dir.y * cos_sp;
	en->player.cplane.x = en->player.cplane.x * cos_sp -
			en->player.cplane.y * sin_sp;
	en->player.cplane.y = old_plane * sin_sp + en->player.cplane.y * cos_sp;
}

void		move(t_env *en)
{
	if (en->player.move_up == 1)
		move_forward(en);
	if (en->player.move_left == 1)
		move_left(en);
	if (en->player.move_right == 1)
		move_right(en);
	if (en->player.move_down == 1)
		move_backward(en);
}
