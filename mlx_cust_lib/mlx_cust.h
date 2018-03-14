/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cust.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2017/10/07 18:47:16 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CUST_H
# define MLX_CUST_H
# define WINDOW_WIDTH_H 1900
# define WINDOW_HEIGHT_H 1200

# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef union	u_col
{
	int			innt;
	char		tab[4];
}				t_col;

typedef struct	s_pic
{
	int			*data;
	void		*image;
	int			bpp;
	int			endian;
	int			size_line;
}				t_pic;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
}				t_mlx;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_mlx_pic
{
	t_mlx		mlx;
	t_pic		pic;
}				t_mlx_pic;

void			mlx_endian_color(t_pic *image, t_mlx *mlx);
void			mlx_img_drwpoint(const t_pos *xy, const t_mlx_pic *mp,
		t_col *col);
void			mlx_img_drwline(t_pos *s, t_pos *e, const t_mlx_pic *mp,
		t_col *col);
int				mlx_init_win(t_mlx *mlx, int width, int height, char *title);
char			mlx_init_pic(void *mlx, int x, int y, t_pic *image);
void			mlx_destroy_win(t_mlx **mlx);
void			mlx_destroy_pic(t_pic **pic, void *mlx);
t_col			*mlx_init_col(char r, char v, char b, char t);
int				ft_abso(int i);

#endif
