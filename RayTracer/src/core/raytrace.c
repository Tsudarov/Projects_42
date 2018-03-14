/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 05:58:23 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/27 18:43:48 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "raytrace.h"
#include "objects_mgr.h"
#include "object.h"
#include "object_wrapper.h"
#include "color.h"
#include "light.h"
#include "vector.h"
#include "intersection.h"
#include "optics.h"
#include "mlx_mgr.h"
#include "string.h"
#include "calcs.h"
#include "loadbar.h"
#include "global.h"
#include "scene.h"

#define SCENE_ALIAS get_current_scene(&SCENE_LIST)->antialias

extern t_global g_global;

static void	maximize(const t_color *const pixel, double *const max)
{
	if (pixel->r > *max)
		*max = pixel->r;
	if (pixel->g > *max)
		*max = pixel->g;
	if (pixel->b > *max)
		*max = pixel->b;
}

static void	iterate_pixels(
	const size_t dims[2],
	double *const max,
	t_color *pix_map,
	const double large_zoom)
{
	unsigned int	xy[2];
	const t_color	full_intensity = {1.0, 1.0, 1.0, 1.0};
	t_vector		direction;

	xy[0] = -1;
	direction = (t_vector){0.0, 0.0, -1.0};
	init_loading(get_current_scene(&SCENE_LIST));
	while (++xy[0] < dims[0])
	{
		if (!(xy[0] % (dims[0] / 10)))
			loadbar((xy[0] * 100) / dims[0], get_current_scene(&SCENE_LIST));
		direction.x = (xy[0] - dims[0] / 2.0) / large_zoom;
		xy[1] = -1;
		while (++xy[1] < dims[1])
		{
			direction.y = (dims[1] / 2.0 - xy[1]) / large_zoom;
			pix_map[xy[0] + xy[1] * dims[0]] =
				get_current_scene(&SCENE_LIST)->background_color;
			trace_ray(&OBJ_MGR.camera->base_object.coords, (t_reflection_vars)
	{ &direction, (t_color*)&full_intensity, get_current_scene(&SCENE_LIST)->
	ambiant_refraction, 0}, &pix_map[xy[0] + xy[1] * dims[0]]);
			maximize(&pix_map[xy[0] + xy[1] * dims[0]], max);
		}
	}
}

static void	antialiaze(const size_t large_pixels_wide,
				const t_color *const pix_map,
				const double max)
{
	double			patch_size;
	unsigned int	xy[2];
	t_color			sum;
	size_t			dx;
	size_t			dy;

	patch_size = SCENE_ALIAS * SCENE_ALIAS;
	xy[0] = -1;
	while (++xy[0] < get_current_scene(&SCENE_LIST)->width)
	{
		xy[1] = -1;
		while (++xy[1] < get_current_scene(&SCENE_LIST)->height)
		{
			sum = (t_color){0.0, 0.0, 0.0, 1.0};
			dx = -1;
			while (++dx < SCENE_ALIAS && (dy = -1))
				while (++dy < SCENE_ALIAS)
					color_operator_addeq(&sum,
	&pix_map[(SCENE_ALIAS * xy[1] + dy) * large_pixels_wide +
	SCENE_ALIAS * xy[0] + dx]);
			color_operator_diveq(&sum, patch_size);
			set_pixel_value(&MLX_MGR, xy, &sum, max);
		}
	}
}

static void	raytrace_step2(const size_t large_pixels_wide,
					const size_t large_pixels_high,
					const double large_zoom)
{
	t_color			*pix_map;
	double			max;

	max = 0.0;
	if (!(pix_map =
		malloc(sizeof(*pix_map) * large_pixels_wide * large_pixels_high)))
		return ;
	vector_unit_vector(
		&OBJ_MGR.camera->direction,
		(t_vector *const)&OBJ_MGR.camera->direction);
	iterate_pixels(
		(size_t[2]){large_pixels_wide, large_pixels_high},
		&max, pix_map, large_zoom);
	if (max == 0.0)
		max = 1.0;
	antialiaze(large_pixels_wide, pix_map, max);
	free(pix_map);
}

void		raytrace(void)
{
	size_t	large_pixels_wide;
	size_t	large_pixels_high;
	size_t	smaller_dim;
	double	large_zoom;

	large_pixels_wide =
		SCENE_ALIAS * get_current_scene(&SCENE_LIST)->width;
	large_pixels_high =
		SCENE_ALIAS * get_current_scene(&SCENE_LIST)->height;
	smaller_dim =
		((get_current_scene(&SCENE_LIST)->width
		< get_current_scene(&SCENE_LIST)->height)
		? get_current_scene(&SCENE_LIST)->width
		: get_current_scene(&SCENE_LIST)->height);
	large_zoom =
		SCENE_ALIAS * get_current_scene(&SCENE_LIST)->zoom * smaller_dim;
	raytrace_step2(
		large_pixels_wide, large_pixels_high, large_zoom);
}
