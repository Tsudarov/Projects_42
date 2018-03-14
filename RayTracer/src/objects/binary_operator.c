/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 10:37:52 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 06:41:29 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "binary_operator.h"
#include "object_wrapper.h"
#include "solid_object_wrapper.h"
#include "solid_object_reorientable.h"
#include "string.h"

const char	*g_binary_types[BINARY_OPERATOR_TYPE_MAX] =
{
	0,
	"Difference",
	"Intersection",
	"Union"
};

char (*const g_binary_operators_specific_funcs[BINARY_OPERATOR_TYPE_MAX])
(t_binary_operator_wrapper *const, const t_string *const) =
{
	0,
	init_difference,
	init_intersection,
	init_union
};

void	binary_operator_translate(
	t_object_wrapper *const object_wrapper,
	const double dx,
	const double dy,
	const double dz)
{
	t_binary_operator *object;

	object = &object_wrapper->as_solid_object_wrapper.
		as_binary_operator_wrapper.as_binary_operator;
	object_translate((t_object_wrapper*)object, dx, dy, dz);
	object->left->base_object.translate(
		(t_object_wrapper*)object->left, dx, dy, dz);
	object->right->base_object.translate(
		(t_object_wrapper*)object->right, dx, dy, dz);
}

void	destroy_binary_operator(t_object_wrapper *const object_wrapper)
{
	t_binary_operator	*object;

	object = &object_wrapper->as_solid_object_wrapper.
		as_binary_operator_wrapper.as_binary_operator;
	if (object->left)
	{
		object->left->base_object.destroy_object(
			(t_object_wrapper*)object->left);
		free(object->left);
		object->left = 0;
	}
	if (object->right)
	{
		object->right->base_object.destroy_object(
			(t_object_wrapper*)object->right);
		free(object->right);
		object->right = 0;
	}
}

char	init_operand(t_solid_object *const operand,
					const t_string *const value,
					const t_binary_operator *const object)
{
	ft_bzero(operand, sizeof(t_solid_object_wrapper));
	operand->base_object.destroy_object = destroy_object_null;
	operand->uniform_optics = object->base_object.uniform_optics;
	operand->base_object.translate = object_translate;
	operand->base_object.rotate_x = null_rotate;
	operand->base_object.rotate_y = null_rotate;
	operand->base_object.rotate_z = null_rotate;
	return (init_solid_object((t_object_wrapper*)operand, value));
}

char	init_binary_operator_vars(t_binary_operator *const object,
								const t_string *const file)
{
	t_string				value;

	object->base_object.base_object.rotate_x = binary_operator_rotate_x;
	object->base_object.base_object.rotate_y = binary_operator_rotate_y;
	object->base_object.base_object.rotate_z = binary_operator_rotate_z;
	object->base_object.base_object.translate = binary_operator_translate;
	object->base_object.base_object.destroy_object = destroy_binary_operator;
	object->left = 0;
	object->right = 0;
	if (!(extract_value_same_level(&value, "Left", file))
		|| !(object->left = malloc(sizeof(t_solid_object_wrapper)))
		|| !(init_operand(object->left, &value, object)))
	{
		destroy_binary_operator((t_object_wrapper*)object);
		return (0);
	}
	if (!(extract_value_same_level(&value, "Right", file))
		|| !(object->right = malloc(sizeof(t_solid_object_wrapper)))
		|| !(init_operand(object->right, &value, object)))
	{
		destroy_binary_operator((t_object_wrapper*)object);
		return (0);
	}
	return (1);
}

char	init_binary_operator(t_solid_object_wrapper *const binary_operator,
							const t_string *const file)
{
	t_binary_operator		*object;
	t_binary_operator_types	type;
	t_string				value;

	object = &binary_operator->as_binary_operator_wrapper.as_binary_operator;
	init_binary_operator_vars(object, file);
	type = BINARY_OPERATOR_TYPE_NOTHING;
	while (++type < BINARY_OPERATOR_TYPE_MAX)
		if (extract_value_same_level(&value, g_binary_types[type], file))
			return (g_binary_operators_specific_funcs[type](
						&binary_operator->as_binary_operator_wrapper, &value));
			return (0);
}
