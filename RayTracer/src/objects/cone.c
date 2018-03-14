/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:56:19 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/25 17:10:20 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "cone.h"
#include "object_wrapper.h"
#include "intersection.h"
#include "string.h"
#include "vector.h"
#include "raytrace.h"

static void		add_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vantage_direction[2],
	const double u,
	t_intersection_list **const intersection_list)
{
	const t_cone	*object = &solid_object_wrapper->as_cone;
	t_intersection	intersection;
	t_vector		vantage_to_surface;
	t_vector		surface_unit_vector;

	vector_operator_mulf(&vantage_to_surface, u, vantage_direction[1]);
	vector_operator_add(&intersection.point, vantage_direction[0],
		&vantage_to_surface);
	vector_operator_sub(&surface_unit_vector, &intersection.point,
		&object->base_object.base_object.base_object.coords);
	surface_unit_vector = (t_vector){2.0 * surface_unit_vector.x,
		2.0 * cos(object->angle) * cos(object->angle) *
		-surface_unit_vector.y, 2.0 * surface_unit_vector.z};
	vector_unit_vector(&surface_unit_vector, &intersection.surface_normal);
	intersection.distance_squared =
		vector_magnitude_squared(&vantage_to_surface);
	intersection.solid =
		(const t_solid_object_wrapper*)solid_object_wrapper;
	intersection_list_push_new_back(intersection_list, &intersection);
}

static void		check_radicand(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vantage_direction[2],
	const double vars[3],
	t_intersection_list **const intersection_list)
{
	const double	root = sqrt(vars[2]);
	const double	d = 2.0 * vars[0];
	const double	u[2] = {(-vars[1] + root) / d, (-vars[1] - root) / d};
	unsigned int	i;

	i = -1;
	while (++i < 2)
		if (u[i] > EPSILON)
			add_intersection(solid_object_wrapper, vantage_direction,
				u[i], intersection_list);
}

static void		calculate_cone_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vantage,
	const t_vector *const direction,
	t_intersection_list **const intersection_list)
{
	const t_cone	*object = &solid_object_wrapper->as_cone;
	t_vector		displacement;
	double			a;
	double			b;
	double			c;

	vector_operator_sub(&displacement, vantage,
		&object->base_object.base_object.base_object.coords);
	a = (vector_dot_product(direction, &object->axis) *
		vector_dot_product(direction, &object->axis)) -
		cos(object->angle) * cos(object->angle);
	b = 2.0 * (vector_dot_product(direction, &object->axis) *
		vector_dot_product(&displacement, &object->axis) -
		vector_dot_product(direction, &displacement) *
		cos(object->angle) * cos(object->angle));
	c = vector_dot_product(&displacement, &object->axis) *
		vector_dot_product(&displacement, &object->axis) -
		vector_magnitude_squared(&displacement)
		* cos(object->angle) * cos(object->angle);
	if (b * b - 4.0 * a * c >= 0.0)
		check_radicand(solid_object_wrapper, (const t_vector *const[2])
			{vantage, direction}, (const double[3]){a, b, b * b - 4.0 * a * c},
			intersection_list);
}

static char		cone_contains(
	const t_solid_object_reorientable_wrapper *const object_wrapper,
	const t_vector *const point)
{
	const t_cone	*object = &object_wrapper->as_cone;
	t_vector		apex_to_point;

	vector_operator_sub(&apex_to_point,
		&object->base_object.base_object.base_object.coords, point);
	return (vector_dot_product(
		&apex_to_point, &object->axis) / vector_magnitude(&apex_to_point)
		/ vector_magnitude(&object->axis) > cos(object->angle));
}

char			init_cone(
	t_solid_object_reorientable_wrapper *const object_wrapper,
	const t_string *const str)
{
	t_cone		*object;
	t_string	value;

	object = &object_wrapper->as_cone;
	if (!extract_value_same_level(&value, "Angle", str))
		return (0);
	object->angle = atof(value.data_ptr) / 2.0;
	if (!extract_value_same_level(&value, "Axis", str))
		return (0);
	init_vector(&object->axis, &value);
	object->base_object.contains = cone_contains;
	object->base_object.append_all_intersections = calculate_cone_intersection;
	return (1);
}
