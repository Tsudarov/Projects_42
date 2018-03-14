/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:56:19 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 06:04:51 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "cylinder.h"
#include "solid_object_reorientable_wrapper.h"
#include "solid_object_wrapper.h"
#include "calcs.h"
#include "string.h"
#include "intersection.h"
#include "vector.h"
#include "raytrace.h"

void		append_disk_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vant_dir[2],
	const double z_disk,
	t_intersection_list **const intersection_list)
{
	const t_cylinder	*object = &solid_object_wrapper->as_cylinder;
	const double		u = (z_disk - vant_dir[0]->z) / vant_dir[1]->z;
	t_intersection		intersection;
	t_vector			displacement;

	if (u <= EPSILON)
		return ;
	vector_operator_mulf(&displacement, u, vant_dir[1]);
	vector_operator_add(&intersection.point, vant_dir[0], &displacement);
	if (intersection.point.x * intersection.point.x + intersection.point.y *
		intersection.point.y > object->ray * object->ray)
		return ;
	intersection.distance_squared = vector_magnitude_squared(&displacement);
	intersection.surface_normal =
		(t_vector){0.0, 0.0, ((z_disk > 0.0) ? 1.0 : -1.0)};
	intersection.solid = (const t_solid_object_wrapper *)solid_object_wrapper;
	intersection_list_push_new_back(intersection_list, &intersection);
}

void		add_cylinder_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const double u,
	const t_vector *const vantage_direction[2],
	t_intersection_list **const intersection_list)
{
	const t_cylinder	*object = &solid_object_wrapper->as_cylinder;
	t_intersection		intersection;
	t_vector			displacement;
	t_vector			unit;

	vector_operator_mulf(&displacement, u, vantage_direction[1]);
	vector_operator_add(&intersection.point,
						vantage_direction[0], &displacement);
	if (fabs(intersection.point.z) > object->height)
		return ;
	intersection.distance_squared = vector_magnitude_squared(&displacement);
	unit = (t_vector){intersection.point.x, intersection.point.y, 0.0};
	vector_unit_vector(&unit, &intersection.surface_normal);
	intersection.solid = (const t_solid_object_wrapper *)solid_object_wrapper;
	intersection_list_push_new_back(intersection_list, &intersection);
}

void		calculate_cylinder_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vantage,
	const t_vector *const direction,
	t_intersection_list **const intersection_list)
{
	const t_cylinder	*object = &solid_object_wrapper->as_cylinder;
	double				u[2];
	int					num_roots;
	int					i;

	num_roots = solve_quadratic_equation_real((t_calc_variables) {
		direction->x * direction->x + direction->y * direction->y,
		2.0 * (vantage->x * direction->x + vantage->y * direction->y),
		vantage->x * vantage->x + vantage->y * vantage->y
		- object->ray * object->ray, 0, 0}, u);
	if (fabs(direction->z) > EPSILON)
	{
		append_disk_intersection(
	solid_object_wrapper, (const t_vector *const[2]){vantage, direction},
	object->height, intersection_list);
		append_disk_intersection(
	solid_object_wrapper, (const t_vector *const[2]){vantage, direction},
	-object->height, intersection_list);
	}
	i = -1;
	while (++i < num_roots)
		if (u[i] > EPSILON)
			add_cylinder_intersection(solid_object_wrapper,
	u[i], (const t_vector *const[2]){vantage, direction}, intersection_list);
}

char		cylinder_contains(
	const t_solid_object_reorientable_wrapper *const object_wrapper,
	const t_vector *const point)
{
	const t_cylinder	*object = &object_wrapper->as_cylinder;

	return (fabs(point->z) <= object->ray + EPSILON
			&& point->x * point->x + point->y * point->y
			<= object->ray * object->ray + EPSILON);
}

char		init_cylinder(
	t_solid_object_reorientable_wrapper *const object_wrapper,
	const t_string *const str)
{
	t_cylinder	*object;
	t_string	value;

	object = &object_wrapper->as_cylinder;
	if (!extract_value_same_level(&value, "Height", str))
		return (0);
	object->height = atof(value.data_ptr) / 2.0;
	if (!extract_value_same_level(&value, "Ray", str))
		return (0);
	object->ray = atof(value.data_ptr);
	object->base_object.contains = cylinder_contains;
	object->base_object.append_all_intersections =
		calculate_cylinder_intersection;
	return (1);
}
