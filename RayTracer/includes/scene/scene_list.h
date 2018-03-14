/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 20:40:53 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:25:48 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_LIST_H
# define SCENE_LIST_H

# include "mlx_mgr.h"
# include "objects_mgr.h"

struct s_scene;
struct mlx_ptr_s;

typedef enum			e_scene_list_flags
{
	SCENE_LIST_FLAGS_NULL = 0,
	SCENE_LIST_FLAGS_ACTIVE = 1,
	SCENE_LIST_FLAGS_IMG_READY = SCENE_LIST_FLAGS_ACTIVE << 1
}						t_scene_list_flags;

typedef struct			s_scene_list
{
	struct s_scene		*scene;
	struct s_scene_list	*prev;
	struct s_scene_list	*next;
	t_scene_list_flags	flag;
	t_img_datas			img;
	t_objects_mgr		objects_mgr;
}						t_scene_list;

char					scene_list_add(t_scene_list *const scene_list,
									const struct s_scene *scene,
									const t_objects_mgr *const objects_mgr);
const struct s_scene	*get_current_scene(
	const t_scene_list *const scene_list);
struct s_scene_list		*get_current_scene_list_member(
	t_scene_list *const scene_list);
void					free_scene_list(t_scene_list *const scene_list,
										struct mlx_ptr_s *const mlx);
void					update_current_scene(const char next);

#endif
