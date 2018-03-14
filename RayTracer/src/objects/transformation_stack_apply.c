/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_stack_apply.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 06:21:45 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 06:37:37 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_wrapper.h"
#include "transformation_stack.h"
#include "object.h"

static void	apply_type_translate(
	t_object *const target,
	const t_transformation_args *const args)
{
	const t_vector	translate_args = args->translate;

	target->translate(
		(t_object_wrapper*)target,
		translate_args.x,
		translate_args.y,
		translate_args.z);
}

static void	apply_type_rotate_x(
	t_object *const target,
	const t_transformation_args *const args)
{
	const float	rotate = args->rotate;

	target->rotate_x((t_object_wrapper*)target, rotate);
}

static void	apply_type_rotate_y(
	t_object *const target,
	const t_transformation_args *const args)
{
	const float	rotate = args->rotate;

	target->rotate_y((t_object_wrapper*)target, rotate);
}

static void	apply_type_rotate_z(
	t_object *const target,
	const t_transformation_args *const args)
{
	const float	rotate = args->rotate;

	target->rotate_z((t_object_wrapper*)target, rotate);
}

void		(*const g_apply_type[])
	(t_object *const, const t_transformation_args *const) =
{
	apply_type_translate,
	apply_type_rotate_x,
	apply_type_rotate_y,
	apply_type_rotate_z,
	0
};

void		transformation_stack_apply(
	t_transformation_stack *const stack,
	t_object *const target)
{
	t_transformation_stack	*stack_ptr;

	stack_ptr = stack;
	while (stack_ptr)
	{
		g_apply_type[stack_ptr->type - 1](target, &stack_ptr->args);
		stack_ptr = stack_ptr->next;
	}
}
