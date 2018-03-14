/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 05:32:19 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 16:16:23 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "object_wrapper.h"
#include "string.h"

char			init_camera(t_object_wrapper *const object_wrapper,
							const t_string *const str)
{
	t_camera	*object;
	t_string	value;

	object = &object_wrapper->as_camera;
	if (!(extract_value_same_level(&value, "Direction", str)))
		return (0);
	if (!init_vector(&object->direction, &value))
		return (0);
	object->base_object.object_type = OBJECT_TYPE_CAMERA;
	return (1);
}
