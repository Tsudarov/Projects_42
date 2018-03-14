/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:56:19 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 15:08:11 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "union.h"
#include "binary_operator.h"
#include "solid_object_wrapper.h"
#include "string.h"
#include "intersection.h"

#define WRAPPER_TO_UNION &object_wrapper->as_binary_operator_wrapper.as_union

void		calculate_union_intersection(
	const t_solid_object_wrapper *const object_wrapper,
	const t_vector *const vantage,
	const t_vector *const direction,
	t_intersection_list **const intersection_list)
{
	const t_union	*const object = WRAPPER_TO_UNION;

	object->base_object.left->append_all_intersections(
		(t_solid_object_wrapper*)object->base_object.left,
		vantage,
		direction,
		intersection_list);
	object->base_object.right->append_all_intersections(
		(t_solid_object_wrapper*)object->base_object.right,
		vantage,
		direction,
		intersection_list);
}

char		union_contains(const t_solid_object_wrapper *const object_wrapper,
						const t_vector *const point)
{
	const t_union	*const object = WRAPPER_TO_UNION;

	return (object->base_object.left->contains(
				(t_solid_object_wrapper*)object->base_object.left, point) ||
		object->base_object.right->contains(
			(t_solid_object_wrapper*)object->base_object.right, point));
}

char		init_union(t_binary_operator_wrapper *const object_wrapper,
					const t_string *const __attribute__((unused)) str)
{
	t_union	*const object = &object_wrapper->as_union;

	object->base_object.base_object.contains = union_contains;
	object->base_object.base_object.append_all_intersections =
		calculate_union_intersection;
	return (1);
}
