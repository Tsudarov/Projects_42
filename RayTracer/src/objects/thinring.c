/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:56:19 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 06:18:33 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "thinring.h"
#include "solid_object_reorientable_wrapper.h"
#include "solid_object_wrapper.h"
#include "calcs.h"
#include "string.h"
#include "intersection.h"
#include "vector.h"
#include "raytrace.h"

void		add_thinring_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vantage_direction[2],
	const double vars[3],
	t_intersection_list **const intersection_list)
{
	t_intersection	intersection;
	t_vector		displacement;

	intersection.point = (t_vector){vars[0], vars[1], 0.0};
	vector_operator_mulf(&displacement, vars[2], vantage_direction[1]);
	intersection.distance_squared = vector_magnitude_squared(&displacement);
	intersection.surface_normal =
		(t_vector){0.0, 0.0, ((vantage_direction[0]->z >= 0.0) ? 1.0 : -1.0)};
	intersection.solid = (const t_solid_object_wrapper *)solid_object_wrapper;
	intersection_list_push_new_back(intersection_list, &intersection);
}

void		calculate_thinring_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vantage,
	const t_vector *const direction,
	t_intersection_list **const intersection_list)
{
	const t_thinring	*object = &solid_object_wrapper->as_thinring;
	const double		u = -vantage->z / direction->z;
	double				x;
	double				y;
	double				m;

	if (fabs(direction->z) <= EPSILON)
		return ;
	if (u <= EPSILON)
		return ;
	x = u * direction->x + vantage->x;
	y = u * direction->y + vantage->y;
	m = x * x + y * y;
	if (!(m <= object->outer_radius * object->outer_radius + EPSILON) ||
		!(object->inner_radius * object->inner_radius <= m + EPSILON))
		return ;
	add_thinring_intersection(solid_object_wrapper, (const t_vector *const[2])
	{vantage, direction}, (double[3]){x, y, u}, intersection_list);
}

char		thinring_contains(
	const t_solid_object_reorientable_wrapper *const object_wrapper,
	const t_vector *const point)
{
	const t_thinring	*object = &object_wrapper->as_thinring;
	const double		mag_squared = point->x * point->x + point->y * point->y;

	if (fabs(point->z) > EPSILON)
		return (0);
	return (object->inner_radius * object->inner_radius
			<= EPSILON + mag_squared && mag_squared
			<= EPSILON + object->outer_radius * object->outer_radius);
}

char		init_thinring(
	t_solid_object_reorientable_wrapper *const object_wrapper,
	const t_string *const str)
{
	t_thinring	*object;
	t_string	value;

	object = &object_wrapper->as_thinring;
	if (!extract_value_same_level(&value, "Inner Radius", str))
		return (0);
	object->inner_radius = atof(value.data_ptr);
	if (!extract_value_same_level(&value, "Outer Radius", str))
		return (0);
	object->outer_radius = atof(value.data_ptr);
	object->base_object.contains = thinring_contains;
	object->base_object.append_all_intersections =
		calculate_thinring_intersection;
	return (1);
}
