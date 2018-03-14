/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheroid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:56:19 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 08:16:38 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "spheroid.h"
#include "solid_object_reorientable_wrapper.h"
#include "solid_object_wrapper.h"
#include "calcs.h"
#include "string.h"
#include "intersection.h"
#include "vector.h"
#include "raytrace.h"

void		calc_normal(
	t_intersection *const intersection,
	const double abc2[3],
	const double xyz[3])
{
	t_vector	tmp;

	if (fabs(xyz[2]) <= EPSILON)
	{
		if (fabs(xyz[0]) <= EPSILON)
			intersection->surface_normal =
				(t_vector){0.0, ((xyz[1] > 0.0) ? 1.0 : -1.0), 0.0};
		else
		{
			tmp =
				(t_vector){-1.0, -(abc2[0] * xyz[1]) / (abc2[1] * xyz[0]), 0.0};
			vector_unit_vector(&tmp, &intersection->surface_normal);
		}
	}
	else
	{
		tmp =
			(t_vector){(abc2[2] * xyz[0]) / (abc2[0] * xyz[2]),
					(abc2[2] * xyz[1]) / (abc2[1] * xyz[2]), 1.0};
		vector_unit_vector(&tmp, &intersection->surface_normal);
	}
}

void		add_spheroid_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vantage_direction[2],
	const double abcu[4],
	t_intersection_list **const intersection_list)
{
	t_intersection	intersection;
	t_vector		displacement;
	double			x;
	double			y;
	double			z;

	vector_operator_mulf(&displacement, abcu[3], vantage_direction[1]);
	intersection.distance_squared = vector_magnitude_squared(&displacement);
	vector_operator_add(&intersection.point,
						vantage_direction[0], &displacement);
	x = intersection.point.x;
	y = intersection.point.y;
	z = intersection.point.z;
	calc_normal(&intersection, (const double[3]){abcu[0], abcu[1], abcu[2]},
				(const double[3]){x, y, z});
	if (x * intersection.surface_normal.x < 0.0)
		intersection.surface_normal.x *= -1.0;
	if (y * intersection.surface_normal.y < 0.0)
		intersection.surface_normal.y *= -1.0;
	if (z * intersection.surface_normal.z < 0.0)
		intersection.surface_normal.z *= -1.0;
	intersection.solid =
		(const t_solid_object_wrapper *)solid_object_wrapper;
	intersection_list_push_new_back(intersection_list, &intersection);
}

void		calculate_spheroid_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vantage,
	const t_vector *const direction,
	t_intersection_list **const intersection_list)
{
	const t_spheroid	*object = &solid_object_wrapper->as_spheroid;
	const double		abc2[] = {object->a2, object->b2, object->c2};
	double				u[2];
	int					num_roots;
	int					i;

	num_roots = solve_quadratic_equation_real(
	(t_calc_variables) {(abc2[1] * abc2[2] * direction->x * direction->x) +
	(abc2[0] * abc2[2] * direction->y * direction->y) + (abc2[0] * abc2[1] *
	direction->z * direction->z), 2.0 * ((abc2[1] * abc2[2] * vantage->x *
	direction->x) + (abc2[0] * abc2[2] * vantage->y * direction->y) +
	(abc2[0] * abc2[1] * vantage->z * direction->z)), (abc2[1] * abc2[2] *
	vantage->x * vantage->x) + (abc2[0] * abc2[2] * vantage->y * vantage->y) +
	(abc2[0] * abc2[1] * vantage->z * vantage->z) -
	(abc2[0] * abc2[1] * abc2[2]), 0, 0}, u);
	i = -1;
	while (++i < num_roots)
	{
		if (u[i] <= EPSILON)
			continue;
		add_spheroid_intersection(solid_object_wrapper,
		(const t_vector *const[2]){vantage, direction},
		(const double[4]){abc2[0], abc2[1], abc2[2], u[i]},
		intersection_list);
	}
}

char		spheroid_contains(
	const t_solid_object_reorientable_wrapper *const object_wrapper,
	const t_vector *const point)
{
	const t_spheroid	*object = &object_wrapper->as_spheroid;
	const double		xr = point->x / object->a;
	const double		yr = point->y / object->b;
	const double		zr = point->z / object->b;

	return (xr * xr + yr * yr + zr * zr <= 1.0 + EPSILON);
}

char		init_spheroid(
	t_solid_object_reorientable_wrapper *const object_wrapper,
	const t_string *const str)
{
	t_spheroid	*object;
	t_string	value;

	object = &object_wrapper->as_spheroid;
	if (!extract_value_same_level(&value, "RayA", str))
		return (0);
	object->a = atof(value.data_ptr);
	object->a2 = object->a * object->a;
	if (!extract_value_same_level(&value, "RayB", str))
		return (0);
	object->b = atof(value.data_ptr);
	object->b2 = object->b * object->b;
	if (!extract_value_same_level(&value, "Height", str))
		return (0);
	object->c = atof(value.data_ptr);
	object->c2 = object->c * object->c;
	object->base_object.contains = spheroid_contains;
	object->base_object.append_all_intersections =
		calculate_spheroid_intersection;
	return (1);
}
