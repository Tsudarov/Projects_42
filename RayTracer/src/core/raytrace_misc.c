/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 09:06:53 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 09:23:57 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "color.h"
#include "raytrace.h"
#include "intersection.h"

void	calculate_reflection(
	const t_intersection *const intersection,
	const t_reflection_vars vars,
	t_color *const result)
{
	t_vector		normal;
	t_vector		reflect_dir;
	double			perp;

	perp = 2.0 * vector_dot_product(
		vars.incident_dir, &intersection->surface_normal);
	vector_operator_mulf(&normal, perp, &intersection->surface_normal);
	vector_operator_sub(&reflect_dir, vars.incident_dir, &normal);
	trace_ray(&intersection->point,
		(t_reflection_vars)
		{
			&reflect_dir,
			vars.ray_intensity,
			vars.refractive_index,
			vars.recursion_depth,
		},
		result);
}

double	polarized_reflection(
	const double n1,
	const double n2,
	const double cos_a1,
	const double cos_a2)
{
	const double	left = n1 * cos_a1;
	const double	right = n2 * cos_a2;
	const double	numer = left - right;
	double			denom;
	double			reflection;

	denom = left + right;
	denom *= denom;
	if (denom < EPSILON)
		return (1.0);
	reflection = numer * numer / denom;
	if (reflection > 1.0)
		return (1.0);
	return (reflection);
}

void	check_align(
	const t_check_align_args args)
{
	double			cos_a2;
	double			rs;
	double			rp;
	t_color			next_ray_intensity;

	cos_a2 = sqrtf(1.0 - args.sin_a2 * args.sin_a2);
	if (args.cos_a1 < 0.0)
		cos_a2 = -cos_a2;
	rs = polarized_reflection(args.vars.refractive_index,
		args.target_refractive_index, args.cos_a1, cos_a2);
	rp = polarized_reflection(args.vars.refractive_index,
		args.target_refractive_index, cos_a2, args.cos_a1);
	*args.out_reflection_factor = (rs + rp) / 2.0;
	color_operator_mulf(&next_ray_intensity,
		1.0 - *args.out_reflection_factor, args.vars.ray_intensity);
	trace_ray(
		&args.intersection->point,
		(t_reflection_vars)
		{
			args.refract_dir,
			&next_ray_intensity,
			args.target_refractive_index,
			args.vars.recursion_depth,
		},
		args.result);
}
