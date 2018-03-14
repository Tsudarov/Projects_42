/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_mgr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:20:26 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 14:24:05 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lights_mgr.h"
#include "object.h"

void		destroy_lights_mgr(t_lights_mgr *const lights_mgr)
{
	free(lights_mgr->lights);
}

char		init_lights_mgr(t_lights_mgr *const lights_mgr,
							const char *const *const file)
{
	size_t	counter;

	counter = -1;
	lights_mgr->lights_len = 1;
	while (file[++counter])
	{
		if (is_object_declaration(file[counter]))
			lights_mgr->lights_len++;
	}
	if (!(lights_mgr->lights = malloc(
			sizeof(*lights_mgr->lights) * lights_mgr->lights_len)))
		return (0);
	ft_bzero(lights_mgr->lights);
	counter = -1;
	lights_mgr->lights_len = 0;
	while (file[++counter])
	{
		if (is_light_declaration(file[counter]))
			init_light(
				&lights_mgr->lights[lights_mgr->lights_len++], file, &counter);
	}
	return (1);
}
