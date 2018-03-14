/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 19:45:47 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:07:11 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include "scene_list.h"
# include "mlx_mgr.h"
# include "loadbar.h"

# define SCENE_LIST g_global.scene_list
# define MLX_MGR g_global.mlx_mgr
# define OBJ_MGR get_current_scene_list_member(&SCENE_LIST)->objects_mgr
# define LOADBAR g_global.loadbar

typedef struct		s_global
{
	t_scene_list	scene_list;
	t_mlx_mgr		mlx_mgr;
	t_loadbar		loadbar;
}					t_global;

#endif
