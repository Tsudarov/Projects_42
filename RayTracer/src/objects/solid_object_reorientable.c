/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_object_reorientable.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 10:37:52 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/25 16:36:17 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "intersection.h"
#include "solid_object_reorientable.h"
#include "object_wrapper.h"
#include "solid_object_wrapper.h"
#include "solid_object_reorientable_wrapper.h"
#include "string.h"

const char	*g_solid_reorientable_types[SOLID_OBJECT_REORIENTABLE_TYPE_MAX] =
{
	0,
	"Cuboid",
	"Cone",
	"Cylinder",
	"Spheroid",
	"ThinRing",
	"ChessBoard"
};

char		(*const g_solid_object_reorientables_specific_funcs
			[SOLID_OBJECT_REORIENTABLE_TYPE_MAX])
(t_solid_object_reorientable_wrapper *const, const t_string *const) =
{
	0,
	init_cuboid,
	init_cone,
	init_cylinder,
	init_spheroid,
	init_thinring,
	init_chessboard,
};

char	solid_object_reorientable_contains(
	const t_solid_object_wrapper *const solid_object,
	const t_vector *const point)
{
	t_vector	camera_point;

	object_point_from_camera_point(
		&solid_object->as_solid_object_reorientable, point, &camera_point);
	return (solid_object->as_solid_object_reorientable.
	contains(
	&solid_object->as_solid_object_reorientable_wrapper,
	&camera_point));
}

void	solid_object_reorientable_surface_optics(
	const union u_solid_object_wrapper *const wrapper,
	const struct s_vector *const surface_point,
	struct s_optics *const result)
{
	const t_solid_object_reorientable	*object;
	t_vector							object_surface_point;

	object = &wrapper->as_solid_object_reorientable;
	object_point_from_camera_point(
		object, surface_point, &object_surface_point);
	object->surface_optics(
		&wrapper->as_solid_object_reorientable_wrapper,
		&object_surface_point, result);
}

void	default_surface_optics(
	const union u_solid_object_reorientable_wrapper *const wrapper,
	const struct s_vector *const __attribute__((unused)) surface_point,
	struct s_optics *const result)
{
	const t_solid_object_reorientable	*object;

	object = &wrapper->as_solid_object_reorientable;
	*result = object->base_object.uniform_optics;
}

void	init_solid_object_reorientable_vars(
	t_solid_object_reorientable *const object)
{
	object->r_dir = (t_vector){1.0, 0.0, 0.0};
	object->s_dir = (t_vector){0.0, 1.0, 0.0};
	object->t_dir = (t_vector){0.0, 0.0, 1.0};
	object->x_dir = (t_vector){1.0, 0.0, 0.0};
	object->y_dir = (t_vector){0.0, 1.0, 0.0};
	object->z_dir = (t_vector){0.0, 0.0, 1.0};
	object->surface_optics = default_surface_optics;
	object->base_object.contains = solid_object_reorientable_contains;
	object->base_object.append_all_intersections =
		solid_object_reorientable_append_all_intersections;
	object->base_object.surface_optics =
		solid_object_reorientable_surface_optics;
	object->base_object.base_object.rotate_x = solid_object_rotate_x;
	object->base_object.base_object.rotate_y = solid_object_rotate_y;
	object->base_object.base_object.rotate_z = solid_object_rotate_z;
}

char	init_solid_object_reorientable(
	t_solid_object_wrapper *const solid_object_reorientable,
	const t_string *const file)
{
	t_solid_object_reorientable			*object;
	t_solid_object_reorientables_type	type;
	t_string							value;

	object = &solid_object_reorientable->as_solid_object_reorientable;
	type = SOLID_OBJECT_REORIENTABLE_TYPE_NOTHING;
	init_solid_object_reorientable_vars(object);
	while (++type < SOLID_OBJECT_REORIENTABLE_TYPE_MAX)
		if (extract_value_same_level(
				&value, g_solid_reorientable_types[type], file))
			return (
				g_solid_object_reorientables_specific_funcs[type](
					&solid_object_reorientable->
					as_solid_object_reorientable_wrapper,
					&value));
			return (0);
}
