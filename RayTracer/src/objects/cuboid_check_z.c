/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid_check_z.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 08:24:19 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 08:38:56 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuboid.h"
#include "solid_object_wrapper.h"
#include "solid_object_reorientable_wrapper.h"
#include "intersection.h"
#include "raytrace.h"

static void	check_top_z_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vd[2],
	t_intersection_list **const intersection_list,
	const double c)
{
	const t_cuboid	*object = &solid_object_wrapper->as_cuboid;
	t_intersection	intersection;
	t_vector		displacement;
	double			u;

	u = (c - vd[0]->z) / vd[1]->z;
	if (u > EPSILON)
	{
		vector_operator_mulf(&displacement, u, vd[1]);
		vector_operator_add(&intersection.point, vd[0], &displacement);
		if (object->base_object.contains(
				solid_object_wrapper, &intersection.point))
		{
			intersection.distance_squared =
				vector_magnitude_squared(&displacement);
			intersection.surface_normal = (t_vector){0.0, 0.0, 1.0};
			intersection.solid =
				(const t_solid_object_wrapper *)solid_object_wrapper;
			intersection_list_push_new_back(intersection_list, &intersection);
		}
	}
}

static void	check_bot_z_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vd[2],
	t_intersection_list **const intersection_list,
	const double c)
{
	const t_cuboid	*object = &solid_object_wrapper->as_cuboid;
	t_intersection	intersection;
	t_vector		displacement;
	double			u;

	u = (-c - vd[0]->z) / vd[1]->z;
	if (u > EPSILON)
	{
		vector_operator_mulf(&displacement, u, vd[1]);
		vector_operator_add(&intersection.point, vd[0], &displacement);
		if (object->base_object.contains(
				solid_object_wrapper, &intersection.point))
		{
			intersection.distance_squared =
				vector_magnitude_squared(&displacement);
			intersection.surface_normal = (t_vector){0.0, 0.0, -1.0};
			intersection.solid =
				(const t_solid_object_wrapper *)solid_object_wrapper;
			intersection_list_push_new_back(intersection_list, &intersection);
		}
	}
}

void		cuboid_check_z(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vd[2],
	t_intersection_list **const intersection_list,
	const double c)
{
	check_top_z_intersection(solid_object_wrapper, vd,
							intersection_list, c);
	check_bot_z_intersection(solid_object_wrapper, vd,
							intersection_list, c);
}
