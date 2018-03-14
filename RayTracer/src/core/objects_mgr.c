/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_mgr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 02:59:23 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/14 07:55:53 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "objects_mgr.h"
#include "object.h"
#include "object_wrapper.h"
#include "string.h"

void		destroy_objects_mgr(t_objects_mgr *const objects_mgr)
{
	size_t	counter;

	counter = -1;
	while (++counter < objects_mgr->objects_len)
		objects_mgr->objects[counter].as_object.destroy_object(
			&objects_mgr->objects[counter]);
	free(objects_mgr->objects);
	free(objects_mgr->lights);
}

char		link_lights(t_objects_mgr *const objects_mgr)
{
	size_t	lights_len;
	size_t	objects_itr;

	lights_len = 1;
	objects_itr = -1;
	while (++objects_itr < objects_mgr->objects_len)
		if (objects_mgr->objects[objects_itr].as_object.object_type
			== OBJECT_TYPE_LIGHT)
			lights_len++;
	if (!(objects_mgr->lights = malloc(
			sizeof(*objects_mgr->lights) * lights_len)))
		return (0);
	lights_len = 0;
	objects_itr = -1;
	while (++objects_itr < objects_mgr->objects_len)
		if (objects_mgr->objects[objects_itr].as_object.object_type
			== OBJECT_TYPE_LIGHT)
			objects_mgr->lights[lights_len++] =
				(const t_light *)&objects_mgr->objects[objects_itr];
	objects_mgr->lights[lights_len++] = 0;
	return (1);
}

char		create_objects(t_objects_mgr *const objects_mgr,
		const t_string *const file)
{
	t_string		objects;
	t_string		object;
	t_string		line;

	objects_mgr->objects_len = 0;
	line = *file;
	while (extract_value_loop(&objects, "Objects", &line))
		while (extract_value_loop(&object, "Object", &objects))
			objects_mgr->objects_len++;
	if (!(objects_mgr->objects =
		malloc(sizeof(*objects_mgr->objects) * objects_mgr->objects_len)))
		return (0);
	ft_bzero(
		objects_mgr->objects,
		sizeof(*objects_mgr->objects) * objects_mgr->objects_len);
	line = *file;
	objects_mgr->objects_len = 0;
	while (extract_value_loop(&objects, "Objects", &line))
		while (extract_value_loop(&object, "Object", &objects))
			if (!(create_object(
					&objects_mgr->objects[objects_mgr->objects_len++].as_object,
					&object)))
				objects_mgr->objects_len--;
	return (1);
}

char		init_objects_mgr(t_objects_mgr *const objects_mgr,
							const t_string *const file)
{
	unsigned int	counter;

	counter = -1;
	if (!(create_objects(objects_mgr, file)))
		return (0);
	while (++counter < objects_mgr->objects_len)
		if (objects_mgr->objects[counter].as_object.object_type
			== OBJECT_TYPE_CAMERA)
		{
			objects_mgr->camera = &objects_mgr->objects[counter].as_camera;
			break ;
		}
	return (counter < objects_mgr->objects_len && link_lights(objects_mgr));
}
