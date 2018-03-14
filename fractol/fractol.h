/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dagnear <Dagnear@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2017/09/16 16:31:40 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define W_FRACTOL_WIDTH 900
# define W_FRACTOL_HEIGHT 700

# include "mlx_cust_lib/mlx_cust.h"

typedef struct		s_c
{
	double			ci;
	double			cr;
}					t_c;

typedef struct		s_z
{
	double			tmp;
	double			zi;
	double			zr;
}					t_z;

typedef struct		s_zoom
{
	double			x;
}					t_zoom;

typedef struct		s_mouse
{
	double			x;
	double			y;
}					t_mouse;

typedef struct		s_env
{
	double			maxiter;
	int				keycode;
	int				code;
	int				r;
	int				v;
	int				b;
	int				movepoint;
	int				stop;
	t_mlx_pic		mp;
	t_zoom			zoom;
	t_mouse			mouse;
	t_pos			pos;
	t_col			col;
	t_z				z;
	t_c				c;
	t_c				center;
}					t_env;

int					ft_init_zoom(t_env *e);
int					init_env(t_env *e);
int					ft_init_c(t_env *e, double r, double i);
int					ft_init_z(t_env *e, double r, double i);
int					ft_init_pos(t_env *e, int x, int y);
void				ft_init_mouse(t_env *e, double x, double y);
void				mlx_help_display(t_env *e);
int					ft_usage(int i);
int					mouse_scroll(int button, int x, int y, t_env *e);
void				ft_reset(t_env *e);
int					ft_exit(char *str);
int					fractol_evnt_kbd(int keycode, t_env *e);
int					fractol_mlx_put_loop(t_env *e);
int					fractol_redraw(t_env *e);
int					fractol_mouse_hook(int x, int y, t_env *e);
void				fractol_color(t_env *e);
int					fractol_julia_launcher(t_env *e);
int					fractol_xxx_launcher(t_env *e);
int					fractol_fractoil_launcher(t_env *e);
int					fractol_flower_launcher(t_env *e);
int					fractol_flux_launcher(t_env *e);
int					fractol_newton_launcher(t_env *e);
int					fractol_tricorne_launcher(t_env *e);
int					fractol_mandelbrot_launcher(t_env *e);
int					fractol_reverse_mandelbrot_launcher(t_env *e);
int					mouse_scroll(int button, int x, int y, t_env *e);

#endif
