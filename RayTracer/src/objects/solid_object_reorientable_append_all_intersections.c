/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_object_reorientable_append_all_i...          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 06:54:52 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 06:58:39 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "solid_object_reorientable.h"
#include "solid_object_wrapper.h"

static void	restore_camera_positions(
	const t_solid_object_reorientable *const object,
	t_intersection_list *itr)
{
	while (itr)
	{
		if (!itr->data)
		{
			itr = itr->next;
			continue;
		}
		camera_point_from_object_point(
			object, &itr->data->point, &itr->data->point);
		camera_dir_from_object_dir(
			object, &itr->data->surface_normal, &itr->data->surface_normal);
		itr = itr->next;
	}
}

void		solid_object_reorientable_append_all_intersections(
	const t_solid_object_wrapper *const solid_object_wrapper,
	const t_vector *const vantage,
	const t_vector *const direction,
	t_intersection_list **const intersection_list)
{
	const t_solid_object_reorientable	*object;
	t_intersection_list					*itr;
	t_vector							object_vantage;
	t_vector							object_ray;

	object = &solid_object_wrapper->as_solid_object_reorientable;
	itr = *intersection_list;
	object_point_from_camera_point(object, vantage, &object_vantage);
	object_dir_from_camera_dir(object, direction, &object_ray);
	if (itr)
		while (itr->next)
			itr = itr->next;
	object->append_all_intersections(
		&solid_object_wrapper->as_solid_object_reorientable_wrapper,
		&object_vantage,
		&object_ray,
		intersection_list);
	if (!itr)
		itr = *intersection_list;
	else
		itr = itr->next;
	restore_camera_positions(object, itr);
}
