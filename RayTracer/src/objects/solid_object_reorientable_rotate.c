/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_object_reorientable_rotate.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 06:53:08 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 07:08:14 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "object_wrapper.h"
#include "solid_object_reorientable.h"

void	update_inverse_rotation(
	t_solid_object_reorientable *const object)
{
	object->x_dir = (t_vector){
		object->r_dir.x, object->s_dir.x, object->t_dir.x};
	object->y_dir = (t_vector){
		object->r_dir.y, object->s_dir.y, object->t_dir.y};
	object->z_dir = (t_vector){
		object->r_dir.z, object->s_dir.z, object->t_dir.z};
}

void	solid_object_rotate_x(
	t_object_wrapper *const object_wrapper,
	const double angle_in_degrees)
{
	t_solid_object_reorientable	*object;
	const double				angle_in_radian = deg2rad(angle_in_degrees);
	const double				a = cos(angle_in_radian);
	const double				b = sin(angle_in_radian);

	object =
		&object_wrapper->as_solid_object_wrapper.as_solid_object_reorientable;
	object->r_dir = (t_vector){
		object->r_dir.x,
		a * object->r_dir.y - b * object->r_dir.z,
		a * object->r_dir.z + b * object->r_dir.y};
	object->s_dir = (t_vector){
		object->s_dir.x,
		a * object->s_dir.y - b * object->s_dir.z,
		a * object->s_dir.z + b * object->s_dir.y};
	object->t_dir = (t_vector){
		object->t_dir.x,
		a * object->t_dir.y - b * object->t_dir.z,
		a * object->t_dir.z + b * object->t_dir.y};
	update_inverse_rotation(object);
}

void	solid_object_rotate_y(
	t_object_wrapper *const object_wrapper,
	const double angle_in_degrees)
{
	t_solid_object_reorientable *object;
	const double				angle_in_radian = deg2rad(angle_in_degrees);
	const double				a = cos(angle_in_radian);
	const double				b = sin(angle_in_radian);

	object =
		&object_wrapper->as_solid_object_wrapper.as_solid_object_reorientable;
	object->r_dir = (t_vector){
		a * object->r_dir.x + b * object->r_dir.z,
		object->r_dir.y,
		a * object->r_dir.z - b * object->r_dir.x};
	object->s_dir = (t_vector){
		a * object->s_dir.x + b * object->s_dir.z,
		object->s_dir.y,
		a * object->s_dir.z - b * object->s_dir.x};
	object->t_dir = (t_vector){
		a * object->t_dir.x + b * object->t_dir.z,
		object->t_dir.y,
		a * object->t_dir.z - b * object->t_dir.x};
	update_inverse_rotation(object);
}

void	solid_object_rotate_z(
	t_object_wrapper *const object_wrapper,
	const double angle_in_degrees)
{
	t_solid_object_reorientable *object;
	const double				angle_in_radian = deg2rad(angle_in_degrees);
	const double				a = cos(angle_in_radian);
	const double				b = sin(angle_in_radian);

	object =
		&object_wrapper->as_solid_object_wrapper.as_solid_object_reorientable;
	object->r_dir = (t_vector){
		a * object->r_dir.x - b * object->r_dir.y,
		a * object->r_dir.y + b * object->r_dir.x,
		object->r_dir.z};
	object->s_dir = (t_vector){
		a * object->s_dir.x - b * object->s_dir.y,
		a * object->s_dir.y + b * object->s_dir.x,
		object->s_dir.z};
	object->t_dir = (t_vector){
		a * object->t_dir.x - b * object->t_dir.y,
		a * object->t_dir.y + b * object->t_dir.x,
		object->t_dir.z};
	update_inverse_rotation(object);
}
