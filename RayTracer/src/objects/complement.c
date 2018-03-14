/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:56:19 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 14:39:35 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "complement.h"
#include "object_wrapper.h"
#include "solid_object_wrapper.h"
#include "string.h"
#include "intersection.h"
#include "vector.h"
#include "raytrace.h"

void			calculate_complement_intersection(
	const t_solid_object_wrapper *const object_wrapper,
	const t_vector *const vantage,
	const t_vector *const direction,
	t_intersection_list **const intersection_list)
{
	const t_complement	*object = &object_wrapper->as_complement;
	t_intersection_list *itr;

	itr = *intersection_list;
	if (itr)
		while (itr->next)
			itr = itr->next;
	object->other->append_all_intersections(
		(t_solid_object_wrapper*)object->other,
		vantage,
		direction,
		intersection_list);
	itr = ((itr) ? itr->next : *intersection_list);
	while (itr)
	{
		if (!itr->data)
		{
			itr = itr->next;
			continue;
		}
		vector_operator_mulf(
			&itr->data->surface_normal, -1.0, &itr->data->surface_normal);
		itr = itr->next;
	}
}

void			destroy_complement(t_object_wrapper *const object_wrapper)
{
	t_complement	*object;

	object = &object_wrapper->as_solid_object_wrapper.as_complement;
	if (object->other)
	{
		object->other->base_object.destroy_object(
			(t_object_wrapper*)object->other);
		free(object->other);
		object->other = 0;
	}
}

t_solid_object	*create_complement(t_solid_object *const other)
{
	t_complement	*object;

	if (!other || !(object = malloc(sizeof(*object))))
		return (0);
	ft_bzero(object, sizeof(*object));
	object->other = other;
	object->base_object.contains = complement_contains;
	object->base_object.append_all_intersections =
		calculate_complement_intersection;
	object->base_object.base_object.rotate_x = complement_rotate_x;
	object->base_object.base_object.rotate_y = complement_rotate_y;
	object->base_object.base_object.rotate_z = complement_rotate_z;
	object->base_object.base_object.translate = complement_translate;
	object->base_object.base_object.destroy_object = destroy_complement;
	object->base_object.uniform_optics = object->base_object.uniform_optics;
	object->base_object.base_object.coords = other->base_object.coords;
	object->base_object.base_object.object_flag |= OBJECT_FLAG_ACTIVE;
	return ((t_solid_object*)object);
}

void			init_complement_vars(t_complement *const object)
{
	object->base_object.contains = complement_contains;
	object->base_object.append_all_intersections =
		calculate_complement_intersection;
	object->base_object.base_object.rotate_x = complement_rotate_x;
	object->base_object.base_object.rotate_y = complement_rotate_y;
	object->base_object.base_object.rotate_z = complement_rotate_z;
	object->base_object.base_object.translate = complement_translate;
	object->base_object.base_object.destroy_object = destroy_complement;
	object->other->base_object.destroy_object = destroy_object_null;
	object->other->uniform_optics = object->base_object.uniform_optics;
	object->other->base_object.translate = object_translate;
	object->other->base_object.rotate_x = null_rotate;
	object->other->base_object.rotate_y = null_rotate;
	object->other->base_object.rotate_z = null_rotate;
}

char			init_complement(t_solid_object_wrapper *const object_wrapper,
							const t_string *const str)
{
	t_complement	*object;
	t_string		value;

	object = &object_wrapper->as_complement;
	init_complement_vars(object);
	if (!extract_value_same_level(&value, "Other", str)
		|| !(object->other = malloc(sizeof(t_solid_object_wrapper))))
		return (0);
	ft_bzero(object->other, sizeof(t_solid_object_wrapper));
	if (!(init_solid_object((t_object_wrapper*)object->other, &value)))
	{
		destroy_complement((t_object_wrapper*)object);
		return (0);
	}
	return (1);
}
