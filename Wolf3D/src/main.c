/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 05:23:29 by tsudarov          #+#    #+#             */
/*   Updated: 2017/10/31 00:33:58 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				hook_close(void *null)
{
	if (null)
		null = NULL;
	system("killall afplay &");
	exit(0);
	return (0);
}

static void		map_fill_line(char *line, int n, int *map)
{
	int i;

	i = 0;
	while (*line != ';')
	{
		if (*line == ',')
		{
			line++;
			continue ;
		}
		map[(n * MAP_W) + i++] = (*line++ == '0' ? 0 : 1);
	}
}

int				map_at(int *map, int x, int y)
{
	int pos;

	pos = (x * MAP_W) + y;
	if (pos < 0 || pos > MAP_MAX)
		return (-1);
	return (map[pos]);
}

void			map_fill(int *m)
{
	map_fill_line("1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1;", 0, m);
	map_fill_line("1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1;", 1, m);
	map_fill_line("1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1;", 2, m);
	map_fill_line("1,0,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1;", 3, m);
	map_fill_line("1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1;", 4, m);
	map_fill_line("1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1;", 5, m);
	map_fill_line("1,0,0,1,1,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1;", 6, m);
	map_fill_line("1,0,0,0,0,0,1,0,0,0,1,1,0,0,1,1,1,0,0,0,1,1,1,1;", 7, m);
	map_fill_line("1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1;", 8, m);
	map_fill_line("1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1;", 9, m);
	map_fill_line("1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1;", 10, m);
	map_fill_line("1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1;", 11, m);
	map_fill_line("1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1;", 12, m);
	map_fill_line("1,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1;", 13, m);
	map_fill_line("1,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1;", 14, m);
	map_fill_line("1,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1;", 15, m);
	map_fill_line("1,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,1;", 16, m);
	map_fill_line("1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1;", 17, m);
	map_fill_line("1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1;", 18, m);
	map_fill_line("1,0,0,1,1,1,1,0,0,1,0,0,1,1,1,1,1,0,0,1,1,0,0,1;", 19, m);
	map_fill_line("1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,1,1,0,0,1;", 20, m);
	map_fill_line("1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1;", 21, m);
	map_fill_line("1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1;", 22, m);
	map_fill_line("1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1;", 23, m);
}

int				main(void)
{
	t_env	en;
	int		map[WIN_W * WIN_H];

	if (!(en.mlx = mlx_init()))
		return (0);
	en.player.pos.x = POS_START_X;
	en.player.pos.y = POS_START_Y;
	en.player.dir.x = -1;
	en.player.dir.y = 0;
	en.player.cplane.x = 0.0;
	en.player.cplane.y = 0.80;
	map_fill(map);
	en.map = map;
	if (!(en.mlx_win =
		mlx_new_window(en.mlx, WIN_W, WIN_H, "Wolf3D Bitchiz")))
		return (0);
	system("afplay music.mp3 &");
	mlx_loop_hook(en.mlx, &hook_loop, &en);
	mlx_hook(en.mlx_win, 2, (1L << 0), &hook_key_press, &en);
	mlx_hook(en.mlx_win, 3, (1L << 1), &hook_key_release, &en);
	mlx_hook(en.mlx_win, 17, 0, &hook_close, 0);
	mlx_do_sync(en.mlx);
	mlx_loop(en.mlx);
	return (0);
}
