/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difference.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:56:19 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 06:05:11 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_operator_wrapper.h"
#include "complement.h"
#include "difference.h"
#include "intersection.h"
#include "solid_object_wrapper.h"
#include "string.h"

char		init_difference(
	t_binary_operator_wrapper *const object_wrapper,
	const t_string *const __attribute__((unused)) str)
{
	t_difference	*object;

	object = &object_wrapper->as_difference;
	object->base_object.base_object.base_object.contains =
		intersection_contains;
	object->base_object.base_object.base_object.append_all_intersections =
		calculate_intersection_intersection;
	if ((object->base_object.base_object.right =
		create_complement(object->base_object.base_object.right)))
		return (1);
	return (0);
}
