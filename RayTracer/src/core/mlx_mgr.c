/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mgr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:30:39 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/27 19:08:45 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <OpenGL/gl.h>
#include "mlx_mgr.h"
#include "mlx_int.h"
#include "color.h"
#include "string.h"
#include "scene.h"
#include "scene_list.h"
#include "global.h"
#include "raytrace.h"
#include "mlx_defines.h"

extern t_global g_global;

char	mlx_mgr_new_window(t_mlx_mgr *const mlx_mgr,
		const unsigned int width,
		const unsigned int height)
{
	if (!(mlx_mgr->mlx_datas.win = mlx_new_window(mlx_mgr->mlx_datas.mlx,
					width, height, "rt")))
		return (0);
	if (!(init_img_datas(&mlx_mgr->img_datas, mlx_mgr->mlx_datas.mlx,
					width, height)))
		return (0);
	return (1);
}

char	init_img_datas(t_img_datas *const img_datas,
		mlx_ptr_t *const mlx_ptr,
		const unsigned int width,
		const unsigned int height)
{
	if (!(img_datas->img = mlx_new_image(mlx_ptr, width, height)))
		return (0);
	if (!(img_datas->data = mlx_get_data_addr(img_datas->img, &img_datas->bpp,
					&img_datas->size_line, &img_datas->endian)))
		return (0);
	return (1);
}

int		key_hook(int key)
{
	t_scene_list	*curr;

	if (key == 53)
	{
		free_scene_list(&SCENE_LIST, MLX_MGR.mlx_datas.mlx);
		destroy_mlx_mgr(&MLX_MGR);
		exit(EXIT_SUCCESS);
	}
	if (key < 123 || key > 124)
		return (1);
	update_current_scene(key - 123);
	curr = get_current_scene_list_member(&SCENE_LIST);
	if ((curr->flag & SCENE_LIST_FLAGS_IMG_READY) == SCENE_LIST_FLAGS_IMG_READY)
		MLX_MGR.img_datas = curr->img;
	else
	{
		mlx_clear_window(MLX_MGR.mlx_datas.mlx, MLX_MGR.mlx_datas.win);
		raytrace();
	}
	print(&MLX_MGR, &MLX_MGR.img_datas);
	mlx_key_hook(MLX_MGR.mlx_datas.win, key_hook, 0);
	return (1);
}

char	init_mlx_mgr(t_mlx_mgr *const mlx_mgr,
		const unsigned int width,
		const unsigned int height)
{
	ft_bzero(mlx_mgr, sizeof(*mlx_mgr));
	if (!(mlx_mgr->mlx_datas.mlx = mlx_init()))
		return (0);
	if (!(mlx_mgr_new_window(mlx_mgr, width, height)))
		return (0);
	mlx_key_hook(mlx_mgr->mlx_datas.win, key_hook, 0);
	return (1);
}

void	set_pixel_value(t_mlx_mgr *const mlx_mgr,
		const unsigned int xy[2],
		const t_color *const pixel_value,
		const double max)
{
	mlx_mgr->img_datas.data[(xy[0] * mlx_mgr->img_datas.bpp) /
		(8 * sizeof(*mlx_mgr->img_datas.data)) +
		(xy[1] * mlx_mgr->img_datas.size_line /
		sizeof(*mlx_mgr->img_datas.data))] =
		(((int)(pixel_value->lum * 0)) << 24) +
		(((int)(255 * (pixel_value->b / max)))
			<< 0) + (((int)(255 * (pixel_value->g / max))) << 8) +
		((int)(255 * (pixel_value->r / max)) << 16);
}
