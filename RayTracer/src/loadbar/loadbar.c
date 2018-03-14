/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadbar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:58:41 by tsudarov          #+#    #+#             */
/*   Updated: 2018/02/27 19:08:06 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenGL/gl.h>
#include <stdlib.h>
#include "loadbar.h"
#include "scene_list.h"
#include "mlx_mgr.h"
#include "mlx_int.h"
#include "scene.h"
#include "mlx_defines.h"
#include "global.h"

extern t_global g_global;

void			clear_loadbar(t_loadbar *loadbar)
{
	mlx_destroy_image(MLX_MGR.mlx_datas.mlx, loadbar->imgl.img);
}

void			resize_loadbar(unsigned int height, unsigned int width)
{
	LOADBAR.window_h = height / 5;
	LOADBAR.window_w = width / 2;
}

int				init_loading(const t_scene *const scene)
{
	resize_loadbar(scene->height, scene->width);
	init_img_datas(&LOADBAR.imgl, MLX_MGR.mlx_datas.mlx, LOADBAR.window_w,
			LOADBAR.window_h);
	return (1);
}

void			mlx_img_drwpoint(unsigned int x, unsigned int y,
		t_loadbar *loadbar, int couleur)
{
	loadbar->imgl.data[(x * loadbar->imgl.bpp) /
		(8 * sizeof(loadbar->imgl.data)) +
		(y * loadbar->imgl.size_line) / sizeof(loadbar->imgl.data)] = couleur;
}

int				loadbar(char value, const t_scene *const scene)
{
	t_pos			i;
	int				couleur;
	unsigned char	*str;

	str = (unsigned char *)ft_itoa(value);
	i.x = -1;
	couleur = 50 + (200 << 8) + (50 << 16);
	while (++i.x < LOADBAR.window_w * value / 100)
	{
		i.y = -1;
		while (++i.y < LOADBAR.window_h)
			mlx_img_drwpoint(i.x, i.y, &LOADBAR, couleur);
	}
	mlx_put_image_to_window(MLX_MGR.mlx_datas.mlx, MLX_MGR.mlx_datas.win,
			LOADBAR.imgl.img, 5 * scene->width / 100, 10 * scene->height / 100);
	mlx_string_put(MLX_MGR.mlx_datas.mlx, MLX_MGR.mlx_datas.win,
			LOADBAR.window_w / 2, LOADBAR.window_h, 0x888800, str);
	free(str);
	mlx_do_sync(MLX_MGR.mlx_datas.mlx);
	return (1);
}
