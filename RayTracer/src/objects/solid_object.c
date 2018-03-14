/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 03:58:27 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/25 16:36:03 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vector.h"
#include "intersection.h"
#include "solid_object.h"
#include "object_defs.h"
#include "solid_object_wrapper.h"
#include "object_wrapper.h"
#include "string.h"
#include "transformation_stack.h"
#include "raytrace.h"

static const char			*g_solid_types[SOLID_OBJECT_TYPE_MAX] =
{
	0,
	"Solid Object Reorientable",
	"Sphere",
	"Binary Operator",
};

static char (*const g_solid_objects_specific_funcs[SOLID_OBJECT_TYPE_MAX])
	(t_solid_object_wrapper *const, const t_string *const) =
{
	0,
	init_solid_object_reorientable,
	init_sphere,
	init_binary_operator,
};

char						contains(
	const t_solid_object_wrapper *const object_wrapper,
	const t_vector *const point)
{
	const t_vector			direction = (t_vector){0.0, 0.0, 1.0};
	t_intersection_list		*intersections;
	t_intersection_list		*intersections_ptr;
	char					exits;
	double					dotprod;

	exits = 0;
	intersections = 0;
	object_wrapper->as_solid_object.append_all_intersections(
		object_wrapper, point, &direction, &intersections);
	intersections_ptr = intersections;
	while (intersections_ptr)
	{
		dotprod = vector_dot_product(
			&direction, &intersections_ptr->data->surface_normal);
		if (dotprod > EPSILON)
			++exits;
		if (dotprod < -EPSILON)
			--exits;
		intersections_ptr = intersections_ptr->next;
	}
	free_list(intersections);
	return (exits);
}

void						fill_surface_optics(
	const t_solid_object_wrapper *const __attribute__((unused)) object_wrapper,
	const t_vector *const __attribute__((unused)) surface_point,
	t_optics *const dst)
{
	*dst = object_wrapper->as_solid_object.uniform_optics;
}

void						null_append_all_intersection(
	const t_solid_object_wrapper *const __attribute__((unused)) object_wrapper,
	const t_vector *const __attribute__((unused)) vantage,
	const t_vector *const __attribute__((unused)) direction,
	t_intersection_list **const __attribute__((unused)) intersection_list)
{
}

void						init_solid_object_vars(
	t_solid_object *const object,
	const t_string *const str)
{
	static const t_color	white = {1.0, 1.0, 1.0, 1.0};
	static const t_color	black = {0.0, 0.0, 0.0, 1.0};
	t_string				value;

	init_optics(&object->uniform_optics, &white, &black, 1.0);
	object->refractive_index = 1.55;
	if ((extract_value_same_level(&value, "Optics", str)))
		init_optics_from_string(&object->uniform_optics, &value);
	if ((extract_value_same_level(&value, "Refractive index", str)))
		object->refractive_index = strtod(value.data_ptr, 0);
	object->contains = contains;
	object->append_all_intersections = null_append_all_intersection;
	object->surface_optics = fill_surface_optics;
	object->base_object.object_flag |= OBJECT_FLAG_ACTIVE;
	object->base_object.object_type = OBJECT_TYPE_SOLID_OBJECT;
}

char						init_solid_object(
	t_object_wrapper *const object_wrapper,
	const t_string *const str)
{
	t_string				value;
	t_solid_objects_type	type;
	t_solid_object			*object;
	t_transformation_stack	stack;

	object = &object_wrapper->as_solid_object;
	init_solid_object_vars(object, str);
	type = 0;
	while (++type < SOLID_OBJECT_TYPE_MAX)
		if (extract_value_same_level(&value, g_solid_types[type], str))
		{
			if (!g_solid_objects_specific_funcs[type](
					&object_wrapper->as_solid_object_wrapper, &value))
				return (0);
			break ;
		}
	ft_bzero(&stack, sizeof(stack));
	if ((generate_transformation_stack(&stack, str)))
		transformation_stack_apply(&stack, &object_wrapper->as_object);
	delete_transformation_stack(stack.next);
	return (type != SOLID_OBJECT_TYPE_MAX);
}
