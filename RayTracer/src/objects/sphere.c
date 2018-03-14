/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:56:19 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 06:07:11 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "sphere.h"
#include "solid_object_wrapper.h"
#include "string.h"
#include "intersection.h"
#include "vector.h"
#include "raytrace.h"

void		push_sphere_intersection(
	const t_solid_object_wrapper *const solid_object_wrapper,
	const double u,
	const t_vector *const vantage_direction[2],
	t_intersection_list **const intersection_list)
{
	const t_sphere	*object = &solid_object_wrapper->as_sphere;
	t_intersection	intersection;
	t_vector		vantage_to_surface;
	t_vector		surface_unit_vector;

	vector_operator_mulf(&vantage_to_surface, u, vantage_direction[1]);
	vector_operator_add(&intersection.point, vantage_direction[0],
						&vantage_to_surface);
	vector_operator_sub(&surface_unit_vector, &intersection.point,
						&object->base_object.base_object.coords);
	vector_unit_vector(&surface_unit_vector, &intersection.surface_normal);
	intersection.distance_squared =
		vector_magnitude_squared(&vantage_to_surface);
	intersection.solid = solid_object_wrapper;
	intersection_list_push_new_back(intersection_list, &intersection);
}

void		check_sphere_intersections(
	const t_solid_object_wrapper *const solid_object_wrapper,
	const double val[3],
	const t_vector *const vantage_direction[2],
	t_intersection_list **const intersection_list)
{
	const double	root = sqrt(val[2]);
	const double	denom = 2.0 * val[0];
	const double	u[2] = {(-val[1] + root) / denom, (-val[1] - root) / denom};
	unsigned int	i;

	i = -1;
	while (++i < 2)
	{
		if (u[i] <= EPSILON)
			continue ;
		push_sphere_intersection(
			solid_object_wrapper, u[i], vantage_direction, intersection_list);
	}
}

void		calculate_sphere_intersection(
	const t_solid_object_wrapper *const solid_object_wrapper,
	const t_vector *const vantage,
	const t_vector *const direction,
	t_intersection_list **const intersection_list)
{
	const t_sphere	*object = &solid_object_wrapper->as_sphere;
	t_vector		displacement;
	double			abc[3];
	double			radicand;

	vector_operator_sub(
		&displacement, vantage, &object->base_object.base_object.coords);
	abc[0] = vector_magnitude_squared(direction);
	abc[1] = 2.0 * vector_dot_product(direction, &displacement);
	abc[2] = vector_magnitude_squared(&displacement) -
		object->ray * object->ray;
	radicand = abc[1] * abc[1] - 4.0 * abc[0] * abc[2];
	if (radicand < 0.0)
		return ;
	check_sphere_intersections(
		solid_object_wrapper, (double[4]){abc[0], abc[1], radicand},
		(const t_vector *const[2]){vantage, direction}, intersection_list);
}

char		sphere_contains(const t_solid_object_wrapper *const object_wrapper,
							const t_vector *const point)
{
	const t_sphere	*object = &object_wrapper->as_sphere;
	const double	r = object->ray + EPSILON;
	t_vector		diff;

	vector_operator_sub(&diff, point, &object->base_object.base_object.coords);
	return (vector_magnitude_squared(&diff) <= r * r);
}

char		init_sphere(t_solid_object_wrapper *const object_wrapper,
						const t_string *const str)
{
	t_sphere	*object;
	t_string	value;

	object = &object_wrapper->as_sphere;
	if (!extract_value_same_level(&value, "Ray", str))
		return (0);
	object->ray = atof(value.data_ptr);
	object->base_object.contains = sphere_contains;
	object->base_object.append_all_intersections =
		calculate_sphere_intersection;
	return (1);
}
