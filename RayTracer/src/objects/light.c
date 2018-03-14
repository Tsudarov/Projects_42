/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:23:31 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 16:31:43 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "vector.h"
#include "color.h"
#include "object_wrapper.h"
#include "string.h"

char		init_light(t_object_wrapper *const object_wrapper,
					const t_string *const str)
{
	t_light		*light;
	t_string	value;

	light = &object_wrapper->as_light;
	if (!extract_value_same_level(&value, "Color", str))
		return (0);
	init_color_float(&light->color, &value);
	light->base_object.object_type = OBJECT_TYPE_LIGHT;
	return (1);
}
