/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complement_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 06:47:29 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 06:49:35 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complement.h"
#include "object_wrapper.h"

char			complement_contains(
	const t_solid_object_wrapper *const object_wrapper,
	const t_vector *const point)
{
	const t_complement	*object = &object_wrapper->as_complement;

	return (!(object->other->contains(
				(t_solid_object_wrapper*)object->other, point)));
}

void			complement_translate(
	t_object_wrapper *const object_wrapper,
	const double dx,
	const double dy,
	const double dz)
{
	t_complement	*object;

	object = &object_wrapper->as_solid_object_wrapper.as_complement;
	object_translate(object_wrapper, dx, dy, dz);
	object->other->base_object.translate(
		(t_object_wrapper*)object->other, dx, dy, dz);
}

void			complement_rotate_x(
	t_object_wrapper *const object_wrapper,
	const double angle_in_degrees)
{
	t_complement	*object;

	object = &object_wrapper->as_solid_object_wrapper.as_complement;
	object->other->base_object.rotate_x(
		(t_object_wrapper*)object->other, angle_in_degrees);
}

void			complement_rotate_y(
	t_object_wrapper *const object_wrapper,
	const double angle_in_degrees)
{
	t_complement	*object;

	object = &object_wrapper->as_solid_object_wrapper.as_complement;
	object->other->base_object.rotate_y(
		(t_object_wrapper*)object->other, angle_in_degrees);
}

void			complement_rotate_z(
	t_object_wrapper *const object_wrapper,
	const double angle_in_degrees)
{
	t_complement	*object;

	object = &object_wrapper->as_solid_object_wrapper.as_complement;
	object->other->base_object.rotate_z(
		(t_object_wrapper*)object->other, angle_in_degrees);
}
