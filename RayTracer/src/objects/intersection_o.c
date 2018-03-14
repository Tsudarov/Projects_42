/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:56:19 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/19 09:21:21 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection_o.h"
#include "binary_operator.h"
#include "solid_object_wrapper.h"
#include "string.h"
#include "intersection.h"
#include "vector.h"

void		append_overlapping_intersections(
	const t_vector *const vantage_direction[2],
	const t_solid_object *const solid_a,
	const t_solid_object *const solid_b,
	t_intersection_list **intersection_list)
{
	t_intersection_list *tmp_list;
	t_intersection_list *itr;

	tmp_list = 0;
	solid_a->append_all_intersections(
		(union u_solid_object_wrapper*)solid_a,
		vantage_direction[0], vantage_direction[1], &tmp_list);
	itr = tmp_list;
	while (itr)
	{
		if (solid_b->contains(
				(union u_solid_object_wrapper*)solid_b, &itr->data->point))
			intersection_list_push_new_back(intersection_list, itr->data);
		itr = itr->next;
	}
	free_list(tmp_list);
}

void		calculate_intersection_intersection(
	const t_solid_object_wrapper *const object_wrapper,
	const t_vector *const vantage,
	const t_vector *const direction,
	t_intersection_list **const intersection_list)
{
	const t_intersection_o	*object;

	object = &object_wrapper->as_binary_operator_wrapper.as_intersection;
	append_overlapping_intersections(
		(const t_vector *const[2]){
		vantage, direction},
		object->base_object.left,
		object->base_object.right,
		intersection_list);
	append_overlapping_intersections(
		(const t_vector *const[2]){
		vantage, direction},
		object->base_object.right,
		object->base_object.left,
		intersection_list);
}

char		intersection_contains(
	const t_solid_object_wrapper *const object_wrapper,
	const t_vector *const point)
{
	const t_intersection_o	*object;

	object = &object_wrapper->as_binary_operator_wrapper.as_intersection;
	return (
		object->base_object.left->contains(
			(t_solid_object_wrapper*)object->base_object.left, point) &&
		object->base_object.right->contains(
			(t_solid_object_wrapper*)object->base_object.right, point));
}

char		init_intersection(
	t_binary_operator_wrapper *const object_wrapper,
	const t_string *const __attribute__((unused)) str)
{
	t_intersection_o	*object;

	object = &object_wrapper->as_intersection;
	object->base_object.base_object.contains = intersection_contains;
	object->base_object.base_object.append_all_intersections =
		calculate_intersection_intersection;
	return (1);
}
