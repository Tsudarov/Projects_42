/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid_check_y.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 08:23:57 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 08:38:24 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuboid.h"
#include "solid_object_wrapper.h"
#include "solid_object_reorientable_wrapper.h"
#include "intersection.h"
#include "raytrace.h"

static void	check_top_y_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vd[2],
	t_intersection_list **const intersection_list,
	const double b)
{
	const t_cuboid	*object = &solid_object_wrapper->as_cuboid;
	t_intersection	intersection;
	t_vector		displacement;
	double			u;

	u = (b - vd[0]->y) / vd[1]->y;
	if (u > EPSILON)
	{
		vector_operator_mulf(&displacement, u, vd[1]);
		vector_operator_add(&intersection.point, vd[0], &displacement);
		if (object->base_object.contains(
				solid_object_wrapper, &intersection.point))
		{
			intersection.distance_squared =
				vector_magnitude_squared(&displacement);
			intersection.surface_normal = (t_vector){0.0, 1.0, 0.0};
			intersection.solid =
				(const t_solid_object_wrapper *)solid_object_wrapper;
			intersection_list_push_new_back(intersection_list, &intersection);
		}
	}
}

static void	check_bot_y_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vd[2],
	t_intersection_list **const intersection_list,
	const double b)
{
	const t_cuboid	*object = &solid_object_wrapper->as_cuboid;
	t_intersection	intersection;
	t_vector		displacement;
	double			u;

	u = (-b - vd[0]->y) / vd[1]->y;
	if (u > EPSILON)
	{
		vector_operator_mulf(&displacement, u, vd[1]);
		vector_operator_add(&intersection.point, vd[0], &displacement);
		if (object->base_object.contains(
				solid_object_wrapper, &intersection.point))
		{
			intersection.distance_squared =
				vector_magnitude_squared(&displacement);
			intersection.surface_normal = (t_vector){0.0, -1.0, 0.0};
			intersection.solid =
				(const t_solid_object_wrapper *)solid_object_wrapper;
			intersection_list_push_new_back(intersection_list, &intersection);
		}
	}
}

void		cuboid_check_y(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vd[2],
	t_intersection_list **const intersection_list,
	const double b)
{
	check_top_y_intersection(solid_object_wrapper, vd,
							intersection_list, b);
	check_bot_y_intersection(solid_object_wrapper, vd,
							intersection_list, b);
}
