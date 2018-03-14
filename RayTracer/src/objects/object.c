/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:31:29 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 16:42:28 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "object_defs.h"
#include "object_wrapper.h"
#include "transformation_stack.h"
#include "string.h"
#include "vector.h"

const char	*g_types[OBJECT_TYPE_MAX] =
{
	0,
	"Camera",
	"Light",
	"Solid Object"
};

char (*const g_objects_specific_funcs[OBJECT_TYPE_MAX])
	(t_object_wrapper *const, const t_string *const) =
{
	0,
	init_camera,
	init_light,
	init_solid_object
};

void						destroy_object_null(
	t_object_wrapper *const __attribute__((unused)) object)
{
}

void						object_translate(
	t_object_wrapper *const object_wrapper,
	const double dx,
	const double dy,
	const double dz)
{
	t_solid_object *object;

	object = &object_wrapper->as_solid_object;
	object->base_object.coords.x += dx;
	object->base_object.coords.y += dy;
	object->base_object.coords.z += dz;
}

void						null_rotate(
	union u_object_wrapper *const __attribute__((unused)) object,
	const double __attribute__((unused)) angle)
{
}

char						create_object(t_object *const object,
										const t_string *const str)
{
	t_string				value;
	t_objects_type			type;
	t_transformation_stack	stack;

	object->destroy_object = destroy_object_null;
	object->rotate_x = null_rotate;
	object->rotate_y = null_rotate;
	object->rotate_z = null_rotate;
	object->translate = object_translate;
	type = 0;
	while (++type < OBJECT_TYPE_MAX)
		if (extract_value_same_level(&value, g_types[type], str))
		{
			if (!g_objects_specific_funcs[type](
					(t_object_wrapper *const)object, &value))
				return (0);
			break ;
		}
	ft_bzero(&stack, sizeof(stack));
	if ((generate_transformation_stack(&stack, str)))
		transformation_stack_apply(&stack, object);
	delete_transformation_stack(stack.next);
	return (type != OBJECT_TYPE_MAX);
}
