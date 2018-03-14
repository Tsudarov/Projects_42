/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 08:58:40 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 09:28:10 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "global.h"
#include "object_wrapper.h"
#include "scene.h"
#include "raytrace.h"
#include "intersection.h"

extern t_global g_global;

static t_intersection	*get_closest(
	const t_intersection_list *const list,
	int *const tie_count)
{
	const t_intersection_list	*list_ptr;
	t_intersection				*closest;
	double						diff;

	*tie_count = 1;
	list_ptr = list->next;
	closest = list->data;
	while (list_ptr)
	{
		diff = list_ptr->data->distance_squared - closest->distance_squared;
		if (fabs(diff) < EPSILON)
			++(*tie_count);
		else if (diff < 0.0)
		{
			*tie_count = 1;
			closest = list_ptr->data;
		}
		list_ptr = list_ptr->next;
	}
	return (closest);
}

int						pick_closest_intersection(
	const t_intersection_list *const list,
	t_intersection *const intersection)
{
	const size_t				count = list_len(list);
	int							tie_count;

	if (!count)
	{
		free_list((t_intersection_list*)list);
		return (0);
	}
	if (count == 1)
	{
		*intersection = *(list->data);
		free_list((t_intersection_list*)list);
		return (1);
	}
	*intersection = *get_closest(list, &tie_count);
	free_list((t_intersection_list*)list);
	return (tie_count);
}

static char				find_closest_intersection(
	const t_vector *const vantage,
	const t_vector *const direction,
	t_intersection *const intersection)
{
	t_intersection_list	*intersection_list;
	size_t				counter;

	intersection_list = 0;
	counter = -1;
	while (++counter < OBJ_MGR.objects_len)
		if ((OBJ_MGR.objects[counter].as_object.object_flag
			& OBJECT_FLAG_ACTIVE)
			== OBJECT_FLAG_ACTIVE)
			OBJ_MGR.objects[counter].as_solid_object.append_all_intersections(
				(t_solid_object_wrapper *const)&OBJ_MGR.objects[counter],
				vantage, direction,
				&intersection_list);
	return (pick_closest_intersection(intersection_list, intersection));
}

void					trace_ray(
	const t_vector *const vantage,
	const t_reflection_vars vars,
	t_color *const result)
{
	t_intersection	intersection;
	char			intersections;

	intersections = find_closest_intersection(
		vantage, vars.incident_dir, &intersection);
	if (!intersections)
	{
		color_operator_mul(
			result,
			&get_current_scene(&SCENE_LIST)->background_color,
			vars.ray_intensity);
	}
	else if (intersections == 1)
	{
		calculate_lightning(&intersection,
							(t_reflection_vars)
							{
								vars.incident_dir,
								vars.ray_intensity,
								vars.refractive_index,
								vars.recursion_depth + 1
							},
							result);
	}
}
