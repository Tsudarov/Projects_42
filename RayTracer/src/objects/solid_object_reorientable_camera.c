/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_object_reorientable_camera.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 06:52:01 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 07:06:20 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "solid_object_reorientable.h"

double	deg2rad(const double angle_in_degrees)
{
	return (angle_in_degrees * M_PI / 180.0);
}

void	object_dir_from_camera_dir(
	const t_solid_object_reorientable *const object,
	const t_vector *const camera_dir,
	t_vector *const dst)
{
	*dst = (t_vector){
		vector_dot_product(camera_dir, &object->r_dir),
		vector_dot_product(camera_dir, &object->s_dir),
		vector_dot_product(camera_dir, &object->t_dir)};
}

void	object_point_from_camera_point(
	const t_solid_object_reorientable *const object,
	const t_vector *const camera_point,
	t_vector *const dst)
{
	t_vector	diff;

	vector_operator_sub(
		&diff, camera_point, &object->base_object.base_object.coords);
	object_dir_from_camera_dir(object, &diff, dst);
}

void	camera_dir_from_object_dir(
	const t_solid_object_reorientable *const object,
	const t_vector *const object_dir,
	t_vector *const dst)
{
	*dst = (t_vector){
		vector_dot_product(object_dir, &object->x_dir),
		vector_dot_product(object_dir, &object->y_dir),
		vector_dot_product(object_dir, &object->z_dir)};
}

void	camera_point_from_object_point(
	const t_solid_object_reorientable *const object,
	const t_vector *const object_point,
	t_vector *const dst)
{
	t_vector	camera_point;

	camera_dir_from_object_dir(object, object_point, &camera_point);
	vector_operator_add(
		dst, &camera_point, &object->base_object.base_object.coords);
}
