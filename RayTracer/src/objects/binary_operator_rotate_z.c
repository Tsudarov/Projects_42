/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_operator_rotate_z.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 06:39:42 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 07:07:30 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "binary_operator.h"
#include "object_wrapper.h"
#include "solid_object_reorientable.h"

static void	nested_rotate_z(
	const t_binary_operator *const this,
	t_solid_object *const nested,
	const double angle_in_degrees,
	const double ab[2])
{
	const t_vector	c = this->base_object.base_object.coords;
	const t_vector	nc = nested->base_object.coords;
	const double	dx = nc.x - c.x;
	const double	dy = nc.y - c.y;

	nested->base_object.rotate_z((t_object_wrapper*)nested, angle_in_degrees);
	nested->base_object.translate(
		(t_object_wrapper*)nested,
		c.x + ab[0] * dx - ab[1] * dy - nc.x,
		c.y + (ab[0] * dy + ab[1] * dx) - nc.y,
		0);
}

void		binary_operator_rotate_z(
	t_object_wrapper *const object_wrapper,
	const double angle_in_degrees)
{
	t_binary_operator	*object;
	const double		angle_in_radians = deg2rad(angle_in_degrees);
	const double		a = cos(angle_in_radians);
	const double		b = sin(angle_in_radians);

	object = &object_wrapper->as_solid_object_wrapper.
		as_binary_operator_wrapper.as_binary_operator;
	nested_rotate_z(object, object->left, angle_in_degrees, (double[2]){a, b});
	nested_rotate_z(object, object->right, angle_in_degrees, (double[2]){a, b});
}
