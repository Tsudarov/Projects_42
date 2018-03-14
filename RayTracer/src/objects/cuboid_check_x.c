/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid_check_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 08:23:01 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 08:38:20 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuboid.h"
#include "solid_object_wrapper.h"
#include "solid_object_reorientable_wrapper.h"
#include "intersection.h"
#include "raytrace.h"

static void	check_top_x_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vd[2],
	t_intersection_list **const intersection_list,
	const double a)
{
	const t_cuboid	*object = &solid_object_wrapper->as_cuboid;
	t_intersection	intersection;
	t_vector		displacement;
	double			u;

	u = (a - vd[0]->x) / vd[1]->x;
	if (u > EPSILON)
	{
		vector_operator_mulf(&displacement, u, vd[1]);
		vector_operator_add(&intersection.point, vd[0], &displacement);
		if (object->base_object.contains(
				solid_object_wrapper, &intersection.point))
		{
			intersection.distance_squared =
				vector_magnitude_squared(&displacement);
			intersection.surface_normal = (t_vector){1.0, 0.0, 0.0};
			intersection.solid =
				(const t_solid_object_wrapper *)solid_object_wrapper;
			intersection_list_push_new_back(intersection_list, &intersection);
		}
	}
}

static void	check_bot_x_intersection(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vd[2],
	t_intersection_list **const intersection_list,
	const double a)
{
	const t_cuboid	*object = &solid_object_wrapper->as_cuboid;
	t_intersection	intersection;
	t_vector		displacement;
	double			u;

	u = (-a - vd[0]->x) / vd[1]->x;
	if (u > EPSILON)
	{
		vector_operator_mulf(&displacement, u, vd[1]);
		vector_operator_add(&intersection.point, vd[0], &displacement);
		if (object->base_object.contains(
				solid_object_wrapper, &intersection.point))
		{
			intersection.distance_squared =
				vector_magnitude_squared(&displacement);
			intersection.surface_normal = (t_vector){-1.0, 0.0, 0.0};
			intersection.solid =
				(const t_solid_object_wrapper *)solid_object_wrapper;
			intersection_list_push_new_back(intersection_list, &intersection);
		}
	}
}

void		cuboid_check_x(
	const t_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vd[2],
	t_intersection_list **const intersection_list,
	const double a)
{
	check_top_x_intersection(solid_object_wrapper, vd,
							intersection_list, a);
	check_bot_x_intersection(solid_object_wrapper, vd,
							intersection_list, a);
}
