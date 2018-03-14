/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_matte.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 09:00:42 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 09:16:24 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "intersection.h"
#include "global.h"
#include "raytrace.h"

extern t_global g_global;

static void	calc_incidence(
	const double incidence,
	const t_vector *const direction,
	const t_light *const light,
	t_color *const result)
{
	t_color			tmp;

	if (incidence <= 0.0)
		return ;
	color_operator_mulf(&tmp,
						incidence / vector_magnitude_squared(direction),
						&light->color);
	color_operator_addeq(result, &tmp);
}

void		calculate_matte(
	const t_intersection *const intersection,
	t_color *const result)
{
	const t_light	**lights;
	t_vector		direction;
	t_vector		direction_unit_vector;
	double			incidence;

	lights = OBJ_MGR.lights;
	while (*lights)
	{
		if (!(is_on_los(&intersection->point, &(*lights)->base_object.coords)))
		{
			lights++;
			continue ;
		}
		vector_operator_sub(
			&direction, &(*lights)->base_object.coords, &intersection->point);
		vector_unit_vector(&direction, &direction_unit_vector);
		incidence = vector_dot_product(
			&intersection->surface_normal, &direction_unit_vector);
		calc_incidence(incidence, &direction, *lights, result);
		lights++;
	}
}
