/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadbar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:10:33 by tsudarov          #+#    #+#             */
/*   Updated: 2018/02/27 19:35:56 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADBAR_H
# define LOADBAR_H

# include "mlx_mgr.h"

struct s_scene;

typedef struct		s_loadbar
{
	t_img_datas		imgl;
	unsigned int	window_h;
	unsigned int	window_w;
}					t_loadbar;

typedef struct		s_pos
{
	unsigned int	y;
	unsigned int	x;
}					t_pos;

void				mlx_img_drwpoint(unsigned int x, unsigned int y,
					t_loadbar *loadbar, int vert);
int					init_loading(const struct s_scene *const scene);
char				*ft_itoa(int n);
void				print_loadbar(struct s_mlx_mgr *const mlx_mgr,
					struct s_img_datas *const img_datas);
int					loadbar(char value, const struct s_scene *const scene);
void				clear_loadbar(t_loadbar *loadbar);

#endif
