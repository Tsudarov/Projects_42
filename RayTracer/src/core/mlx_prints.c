/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_prints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 07:03:05 by tsudarov          #+#    #+#             */
/*   Updated: 2018/02/14 07:11:56 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_mgr.h"
#include "mlx_defines.h"
#include "global.h"

extern t_global g_global;

void	mlx_close_window(t_mlx_mgr *const mlx_mgr)
{
	mlx_destroy_window(mlx_mgr->mlx_datas.mlx, mlx_mgr->mlx_datas.win);
}

void	destroy_mlx_mgr(t_mlx_mgr *const mlx_mgr)
{
	if (mlx_mgr->mlx_datas.win)
		mlx_destroy_window(mlx_mgr->mlx_datas.mlx, mlx_mgr->mlx_datas.win);
}

void	print(t_mlx_mgr *const mlx_mgr, t_img_datas *const img_datas)
{
	t_scene_list	*const curr = get_current_scene_list_member(&SCENE_LIST);

	mlx_put_image_to_window(mlx_mgr->mlx_datas.mlx, mlx_mgr->mlx_datas.win,
			img_datas->img, 0, 0);
	curr->img = *img_datas;
	curr->flag |= SCENE_LIST_FLAGS_IMG_READY;
}
