/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:13:09 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 15:05:06 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "scene.h"
#include "string.h"

void	init_scene(t_scene *const scene, const t_string *const str)
{
	t_string	area;
	t_string	value;

	scene->background_color = (t_color){0.0, 0.0, 0.0, 1.0};
	scene->ambiant_refraction = 1.0;
	scene->zoom = 1.0;
	scene->width = 1000;
	scene->height = 1000;
	scene->antialias = 1.0;
	if (!extract_value(&area, "Scene", str))
		return ;
	if (extract_value(&value, "Background color", &area))
		init_color_float(&scene->background_color, &value);
	if (extract_value(&value, "Ambiant refraction", &area))
		scene->ambiant_refraction = strtod(value.data_ptr, 0);
	if (extract_value(&value, "Zoom", &area))
		scene->zoom = strtod(value.data_ptr, 0);
	if (extract_value(&value, "Antialiasing", &area))
		scene->antialias = ft_atoi_string(&value);
	if (extract_value(&value, "Width", &area))
		scene->width = ft_atoi_string(&value);
	if (extract_value(&value, "Height", &area))
		scene->height = ft_atoi_string(&value);
}
