/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 05:22:46 by tsudarov          #+#    #+#             */
/*   Updated: 2017/10/31 00:32:58 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			hook_key_press(int keycode, t_env *en)
{
	if (keycode == 126 || keycode == 13)
		en->player.move_up = 1;
	if (keycode == 125 || keycode == 1)
		en->player.move_down = 1;
	if (keycode == 123 || keycode == 0)
		en->player.move_left = 1;
	if (keycode == 124 || keycode == 2)
		en->player.move_right = 1;
	if (keycode == 257)
		en->player.sprint = 1;
	return (0);
}

int			hook_key_release(int keycode, t_env *en)
{
	if (keycode == 126 || keycode == 13)
		en->player.move_up = 0;
	if (keycode == 125 || keycode == 1)
		en->player.move_down = 0;
	if (keycode == 123 || keycode == 0)
		en->player.move_left = 0;
	if (keycode == 124 || keycode == 2)
		en->player.move_right = 0;
	if (keycode == 257)
		en->player.sprint = 0;
	if (keycode == 53)
		hook_close(NULL);
	return (0);
}

int			hook_loop(t_env *en)
{
	struct timeval time;

	raytracer_main(en);
	display_next_img(en);
	hud_display(en);
	en->time.old = en->time.curr;
	gettimeofday(&time, NULL);
	en->time.curr = time.tv_sec * 1000 + time.tv_usec / 1000;
	en->time.frame = en->time.curr - en->time.old;
	en->time.move_spd = en->time.frame * 0.003;
	en->time.rot_spd = en->time.frame * 0.005;
	move(en);
	mlx_do_sync(en->mlx);
	return (0);
}

static void	ft_itoa(char *str, int i)
{
	if (i > 9)
	{
		str[0] = '0' + (i / 10);
		i -= ((i / 10) * 10);
		str[1] = '0' + i;
		str[2] = '\0';
	}
	else
	{
		str[0] = '0' + i;
		str[1] = '\0';
	}
}

void		hud_display(t_env *en)
{
	char x[3];
	char y[3];

	ft_itoa(x, (int)en->player.pos.x);
	ft_itoa(y, (int)en->player.pos.y);
	mlx_string_put(en->mlx, en->mlx_win, 10, 0, 0x000000, "x");
	mlx_string_put(en->mlx, en->mlx_win, 20, 0, 0xFF358B, x);
	mlx_string_put(en->mlx, en->mlx_win, 40, 0, 0x000000, ", y");
	mlx_string_put(en->mlx, en->mlx_win, 70, 0, 0xFF358B, y);
	mlx_string_put(en->mlx, en->mlx_win, WIN_W - WIN_W / 2 - 140
				, WIN_H - 70, 0x000000,
				"Move with arrow keys or WASD");
	mlx_string_put(en->mlx, en->mlx_win, WIN_W - WIN_W / 2 - 108
				, WIN_H - 50, 0x000000,
				"hold shift to sprint.");
	mlx_string_put(en->mlx, en->mlx_win, WIN_W - WIN_W / 2 - 124
				, WIN_H - 30, 0x000000,
				"Escape this shit with ESC");
}
