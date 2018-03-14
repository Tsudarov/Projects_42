/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 00:23:38 by tsudarov          #+#    #+#             */
/*   Updated: 2017/10/31 00:34:25 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define WIN_W 1000
# define WIN_H 800
# define MAP_W 25
# define MAP_H 25
# define MAP_MAX 625
# define POS_START_X	5
# define POS_START_Y	19
# define COLOR_SKY		0x8CC6D7
# define COLOR_FLOOR	0x8FCF3C
# define COLOR_WALL1	0xFF9300
# define COLOR_WALL2	0xFF5900
# define COLOR_WALL3	0xFF0000
# define COLOR_WALL4	0x7D0000

# include <mlx.h>
# include <stdlib.h>
# include <sys/time.h>
# include <math.h>

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bbp;
	int			lsize;
	int			end;
}				t_img;

typedef struct	s_pointd
{
	double		x;
	double		y;
}				t_pointd;

typedef struct	s_pointi
{
	int			x;
	int			y;
}				t_pointi;

typedef struct	s_times
{
	double		old;
	double		curr;
	double		frame;
	double		move_spd;
	double		rot_spd;
}				t_times;

typedef struct	s_raytracer
{
	double		wall_dst;
	t_pointd	pos;
	t_pointd	ray;
	t_pointd	dir;
	t_pointd	side_dst;
	t_pointd	delta_dst;
	t_pointi	map_pos;
	int			draw_hgt;
	int			draw_st;
	int			draw_nd;
	int			color;
}				t_raytracer;

typedef struct	s_player
{
	double		cam_x;
	t_pointd	pos;
	t_pointd	dir;
	t_pointd	cplane;
	t_pointi	step;
	int			hit;
	int			wall_side;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			sprint;
}				t_player;

typedef struct	s_env
{
	void		*mlx;
	void		*mlx_win;
	t_img		mlx_img;
	t_img		next_img;
	int			*map;
	t_player	player;
	t_raytracer	ray;
	t_times		time;
}				t_env;

int				hook_key_press(int keycode, t_env *en);
int				hook_key_release(int keycode, t_env *en);
int				hook_loop(t_env *en);
int				hook_close(void *null);
void			hud_display(t_env *en);
int				img_make(t_env *en);
void			display_next_img(t_env *en);
void			img_draw_linev(t_img *img, t_pointi coord, int x, int color);
int				map_at(int *map, int x, int y);
void			move(t_env *en);
void			raytracer_main(t_env *en);

#endif
