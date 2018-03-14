/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_on_los.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 09:05:23 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 09:22:52 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "solid_object_wrapper.h"
#include "object_wrapper.h"
#include "intersection.h"
#include "raytrace.h"

extern t_global g_global;

char	solid_object_find_closest_intersection(
	const union u_solid_object_wrapper *const solid_object_wrapper,
	const struct s_vector *const vantage,
	const struct s_vector *const direction,
	struct s_intersection *const intersection)
{
	t_intersection_list		*intersection_list;
	const t_solid_object	*object = &solid_object_wrapper->as_solid_object;

	intersection_list = 0;
	object->append_all_intersections(
		solid_object_wrapper, vantage, direction, &intersection_list);
	return (pick_closest_intersection(intersection_list, intersection));
}

char	is_on_los(
	const t_vector *const a,
	const t_vector *const b)
{
	t_vector		dir;
	double			gap_distance_squared;
	t_intersection	closest;
	size_t			counter;

	vector_operator_sub(&dir, b, a);
	gap_distance_squared = vector_magnitude_squared(&dir);
	counter = -1;
	while (++counter < OBJ_MGR.objects_len)
		if ((OBJ_MGR.objects[counter].as_object.object_flag
			& OBJECT_FLAG_ACTIVE)
			== OBJECT_FLAG_ACTIVE)
		{
			if (solid_object_find_closest_intersection(
					&OBJ_MGR.objects[counter].as_solid_object_wrapper,
					a,
					&dir,
					&closest))
				if (closest.distance_squared < gap_distance_squared)
					return (0);
		}
	return (1);
}
