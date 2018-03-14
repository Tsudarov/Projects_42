/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:13:09 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/19 10:32:25 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenGL/gl.h>
#include <stdlib.h>
#include "scene.h"
#include "scene_list.h"
#include "string.h"
#include "mlx_int.h"
#include "global.h"

extern t_global g_global;

char			scene_list_add(t_scene_list *const scene_list,
							const t_scene *const scene,
							const t_objects_mgr *const objects_mgr)
{
	t_scene_list	*rem;

	if (!scene_list->scene)
	{
		scene_list->scene = (t_scene*)scene;
		scene_list->objects_mgr = *objects_mgr;
		return (1);
	}
	rem = scene_list->prev;
	if (!(scene_list->prev = malloc(sizeof(*scene_list->prev))))
	{
		scene_list->prev = rem;
		return (0);
	}
	scene_list->prev->prev = rem;
	rem->next = scene_list->prev;
	scene_list->prev->next = scene_list;
	scene_list->prev->scene = (t_scene*)scene;
	scene_list->prev->objects_mgr = *objects_mgr;
	scene_list->prev->flag = SCENE_LIST_FLAGS_NULL;
	return (1);
}

t_scene_list	*get_current_scene_list_member(t_scene_list *const scene_list)
{
	t_scene_list	*itr;

	itr = scene_list;
	while ((itr->flag & SCENE_LIST_FLAGS_ACTIVE) != SCENE_LIST_FLAGS_ACTIVE)
		itr = itr->next;
	return (itr);
}

void			free_scene_list(t_scene_list *const scene_list,
								mlx_ptr_t *const mlx)
{
	t_scene_list	*itr;

	itr = scene_list->next;
	free(itr->prev->scene);
	destroy_objects_mgr(&itr->prev->objects_mgr);
	while (itr != scene_list)
	{
		itr = itr->next;
		free(itr->prev->scene);
		destroy_objects_mgr(&itr->prev->objects_mgr);
		if ((itr->prev->flag & SCENE_LIST_FLAGS_IMG_READY)
			== SCENE_LIST_FLAGS_IMG_READY)
			mlx_destroy_image(mlx, itr->prev->img.img);
		free(itr->prev);
	}
}

void			update_scene_list_member(
	t_scene_list *const target,
	const double old_x,
	const double old_y)
{
	if (old_x != target->scene->width
		|| old_y != target->scene->height)
	{
		mlx_close_window(&MLX_MGR);
		mlx_mgr_new_window(&MLX_MGR,
			target->scene->width,
			target->scene->height);
	}
	else
		init_img_datas(
			&MLX_MGR.img_datas, MLX_MGR.mlx_datas.mlx, old_x, old_y);
	target->flag |= SCENE_LIST_FLAGS_ACTIVE;
}

void			update_current_scene(const char next)
{
	t_scene_list	*curr;

	curr = get_current_scene_list_member(&SCENE_LIST);
	curr->flag -= SCENE_LIST_FLAGS_ACTIVE;
	update_scene_list_member(((next) ? curr->next : curr->prev),
		curr->scene->width, curr->scene->height);
}
