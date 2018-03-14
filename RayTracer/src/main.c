/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 02:34:42 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/27 19:08:26 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "string.h"
#include "read.h"
#include "objects_mgr.h"
#include "mlx_mgr.h"
#include "global.h"
#include "raytrace.h"
#include "scene.h"
#include "loadbar.h"
#include "extra_defines.h"

t_global			g_global;

static void			get_scene(const char *const arg)
{
	t_string		file;
	t_scene			*scene;
	t_objects_mgr	objects_mgr;

	if (!(read_scene_file(arg, &file)))
		return ;
	if (!(init_objects_mgr(&objects_mgr, &file)))
	{
		free((char*)file.data_ptr);
		return ;
	}
	if (!(scene = malloc(sizeof(*scene))))
		return ;
	init_scene(scene, &file);
	if (!(scene_list_add(&SCENE_LIST, scene, &objects_mgr)))
		return ;
	free((char*)file.data_ptr);
}

int					main(const int ac, const char *const av[])
{
	unsigned int	counter;

	counter = 0;
	SCENE_LIST = (t_scene_list)
		{0, &SCENE_LIST, &SCENE_LIST, SCENE_LIST_FLAGS_ACTIVE,
		{0, 0, 0, 0, 0}, {0, 0, 0, 0}};
	while (++counter < (unsigned)ac)
		get_scene(av[counter]);
	if (!(get_current_scene(&SCENE_LIST)))
		return ((ac == 1) ? EXIT_SUCCESS : EXIT_FAILURE);
	if (!(init_mlx_mgr(
			&MLX_MGR, get_current_scene(&SCENE_LIST)->width,
			get_current_scene(&SCENE_LIST)->height)))
	{
		free_scene_list(&SCENE_LIST, MLX_MGR.mlx_datas.mlx);
		free(SCENE_LIST.scene);
		return (EXIT_FAILURE);
	}
	raytrace();
	print(&MLX_MGR, &MLX_MGR.img_datas);
	mlx_loop(MLX_MGR.mlx_datas.mlx);
	free_scene_list(&SCENE_LIST, MLX_MGR.mlx_datas.mlx);
	destroy_mlx_mgr(&MLX_MGR);
	clear_loadbar(&LOADBAR);
	return (EXIT_SUCCESS);
}
