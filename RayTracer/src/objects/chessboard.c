/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chessboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:56:19 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 05:59:57 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "chessboard.h"
#include "solid_object_wrapper.h"
#include "solid_object_reorientable_wrapper.h"
#include "string.h"
#include "raytrace.h"
#include "intersection.h"

int			square_coordinate(const double xy, const double inner_size)
{
	const double s = floor(8.0 * (xy / inner_size + 0.5));

	if (s < 0.0)
		return (0);
	if (s > 7.0)
		return (7);
	return ((int)s);
}

void		chessboard_optics(
	const union u_solid_object_reorientable_wrapper *const wrapper,
	const struct s_vector *const surface_point,
	struct s_optics *const result)
{
	const t_chessboard	*object = &wrapper->as_chessboard;
	double				half;
	int					x;
	int					y;

	*result = object->base_object.base_object.base_object.uniform_optics;
	if (surface_point->z < object->thickness / 2.0 - EPSILON)
	{
		optics_set_matte_color(result, &object->border);
		return ;
	}
	half = object->inner_size / 2.0;
	if (fabs(surface_point->x) >= half || fabs(surface_point->y) >= half)
	{
		optics_set_matte_color(result, &object->border);
		return ;
	}
	x = square_coordinate(surface_point->x, object->inner_size);
	y = square_coordinate(surface_point->y, object->inner_size);
	if (!((x + y) & 1))
		optics_set_matte_color(result, &object->dark);
	else
		optics_set_matte_color(result, &object->light);
}

char		get_args(t_chessboard *const object, const t_string *const str)
{
	t_string		value;

	if (!extract_value_same_level(&value, "Thickness", str))
		return (0);
	object->thickness = atof(value.data_ptr);
	if (!extract_value_same_level(&value, "LightSquareColor", str))
		return (0);
	if (!init_color_float(&object->light, &value))
		return (0);
	if (!extract_value_same_level(&value, "DarkSquareColor", str))
		return (0);
	if (!init_color_float(&object->dark, &value))
		return (0);
	if (!extract_value_same_level(&value, "BorderColor", str))
		return (0);
	if (!init_color_float(&object->border, &value))
		return (0);
	return (1);
}

char		init_chessboard(
	t_solid_object_reorientable_wrapper *const object_wrapper,
	const t_string *const str)
{
	t_chessboard	*object;
	t_string		value;
	double			border_x;
	double			border_y;

	object = &object_wrapper->as_chessboard;
	if (!get_args(object, str))
		return (0);
	if (!extract_value_same_level(&value, "InnerSize", str))
		return (0);
	object->inner_size = atof(value.data_ptr);
	if (!extract_value_same_level(&value, "BorderX", str))
		return (0);
	border_x = atof(value.data_ptr);
	if (!extract_value_same_level(&value, "BorderY", str))
		return (0);
	border_y = atof(value.data_ptr);
	object->base_object.a = object->inner_size / 2.0 + border_x;
	object->base_object.b = object->inner_size / 2.0 + border_y;
	object->base_object.c = object->thickness / 2.0;
	object->base_object.base_object.contains = cuboid_contains;
	object->base_object.base_object.append_all_intersections =
		calculate_cuboid_intersection;
	object->base_object.base_object.surface_optics = chessboard_optics;
	return (1);
}
