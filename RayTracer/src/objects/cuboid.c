/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:56:19 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 08:31:04 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "cuboid.h"
#include "solid_object_reorientable_wrapper.h"
#include "calcs.h"
#include "string.h"
#include "raytrace.h"

void		calculate_cuboid_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vantage,
	const t_vector *const direction,
	struct s_intersection_list **const intersection_list)
{
	const t_cuboid	*object = &solid_object_wrapper->as_cuboid;

	if (fabs(direction->x) > EPSILON)
		cuboid_check_x(solid_object_wrapper, (const t_vector *[2])
			{vantage, direction}, intersection_list, object->a);
	if (fabs(direction->y) > EPSILON)
		cuboid_check_y(solid_object_wrapper, (const t_vector *[2])
			{vantage, direction}, intersection_list, object->b);
	if (fabs(direction->z) > EPSILON)
		cuboid_check_z(solid_object_wrapper, (const t_vector *[2])
			{vantage, direction}, intersection_list, object->c);
}

char		cuboid_contains(
	const t_solid_object_reorientable_wrapper *const object_wrapper,
	const t_vector *const point)
{
	const t_cuboid	*object = &object_wrapper->as_cuboid;

	return ((fabs(point->x) <= object->a + EPSILON) &&
		(fabs(point->y) <= object->b + EPSILON) &&
		(fabs(point->z) <= object->c + EPSILON));
}

char		init_cuboid(
	t_solid_object_reorientable_wrapper *const object_wrapper,
	const t_string *const str)
{
	t_cuboid	*object;
	t_string	value;

	object = &object_wrapper->as_cuboid;
	if (!extract_value_same_level(&value, "Width", str))
		return (0);
	object->a = atof(value.data_ptr);
	if (!extract_value_same_level(&value, "Depth", str))
		return (0);
	object->b = atof(value.data_ptr);
	if (!extract_value_same_level(&value, "Height", str))
		return (0);
	object->c = atof(value.data_ptr);
	object->base_object.contains = cuboid_contains;
	object->base_object.append_all_intersections =
		calculate_cuboid_intersection;
	return (1);
}
