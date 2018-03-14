/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lightning.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 08:56:33 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 09:25:51 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "optics.h"
#include "intersection.h"
#include "raytrace.h"
#include "solid_object_wrapper.h"

char	is_significant(
	const t_color *const color)
{
	return (color->r >= MIN_OPTICAL_INTENSITY
			|| color->g >= MIN_OPTICAL_INTENSITY
			|| color->b >= MIN_OPTICAL_INTENSITY);
}

void	check_reflection(
	const t_check_reflection_vars vars)
{
	t_color	reflection_color;
	t_color	gloss_color;
	t_color matte_color;

	reflection_color = (t_color){1.0, 1.0, 1.0, 1.0};
	gloss_color = vars.optics->gloss_color;
	color_operator_muleqf(&reflection_color,
						vars.refractive_reflection_factor * vars.transparency);
	color_operator_muleqf(&gloss_color, vars.opacity);
	color_operator_addeq(&reflection_color, &gloss_color);
	color_operator_muleq(&reflection_color, vars.vars.ray_intensity);
	if (is_significant(&reflection_color))
	{
		matte_color = (t_color){0.0, 0.0, 0.0, 1.0};
		calculate_reflection(vars.intersection,
		(t_reflection_vars) { vars.vars.incident_dir,
		&reflection_color, vars.vars.refractive_index,
		vars.vars.recursion_depth },
							&matte_color);
		color_operator_addeq(vars.result, &matte_color);
	}
}

double	add_transparency(
	const t_intersection *const intersection,
	const t_reflection_vars vars,
	const double transparency,
	t_color *const result)
{
	t_color	tmp_ray_intensity;
	t_color	tmp_color;
	double	refractive_reflection_factor;

	refractive_reflection_factor = 0.0;
	tmp_color = (t_color){0.0, 0.0, 0.0, 1.0};
	color_operator_mulf(&tmp_ray_intensity, transparency, vars.ray_intensity);
	calculate_refraction(intersection,
						(t_reflection_vars)
						{
							vars.incident_dir,
							&tmp_ray_intensity,
							vars.refractive_index,
							vars.recursion_depth
						},
						&refractive_reflection_factor,
						&tmp_color);
	color_operator_addeq(result, &tmp_color);
	return (refractive_reflection_factor);
}

void	add_opacity(
	const t_add_opacity_vars vars)
{
	t_color	matte_color;
	t_color	tmp;

	tmp = (t_color){0.0, 0.0, 0.0, 1.0};
	color_operator_mul(
		&tmp, vars.vars.ray_intensity, &vars.optics->matte_color);
	matte_color = (t_color){0.0, 0.0, 0.0, 1.0};
	calculate_matte(vars.intersection, &matte_color);
	color_operator_muleqf(&tmp, vars.opacity);
	color_operator_muleq(&tmp, &matte_color);
	color_operator_addeq(vars.result, &tmp);
}

void	calculate_lightning(
	const t_intersection *const intersection,
	const t_reflection_vars vars,
	t_color *const result)
{
	t_optics		optics;
	double			opacity;
	double			transparency;
	double			refractive_reflection_factor;

	if (vars.recursion_depth > MAX_OPTICAL_RECURSION_DEPTH
		|| !is_significant(vars.ray_intensity))
	{
		*result = (t_color){0.0, 0.0, 0.0, 1.0};
		return ;
	}
	intersection->solid->as_solid_object.surface_optics(
		intersection->solid, &intersection->point, &optics);
	opacity = optics.opacity;
	transparency = 1.0 - opacity;
	if (opacity > 0.0)
		add_opacity(
			(t_add_opacity_vars){vars, &optics, opacity, result, intersection});
	refractive_reflection_factor = 0.0;
	if (transparency > 0.0)
		refractive_reflection_factor =
			add_transparency(intersection, vars, transparency, result);
	check_reflection((t_check_reflection_vars){intersection, vars, transparency,
				refractive_reflection_factor, &optics, opacity, result});
}
