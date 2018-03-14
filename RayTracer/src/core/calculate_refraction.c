/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_refraction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 08:55:29 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 09:29:29 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "calcs.h"
#include "global.h"
#include "intersection.h"
#include "scene.h"
#include "solid_object.h"
#include "object_wrapper.h"
#include "raytrace.h"

extern t_global g_global;

static const t_solid_object	*primary_container(
	const t_vector *const point)
{
	size_t				counter;

	counter = -1;
	while (++counter < OBJ_MGR.objects_len)
		if ((OBJ_MGR.objects[counter].as_object.object_flag
			& OBJECT_FLAG_ACTIVE)
			== OBJECT_FLAG_ACTIVE)
		{
			if (OBJ_MGR.objects[counter].as_solid_object.contains(
					&OBJ_MGR.objects[counter].as_solid_object_wrapper, point))
				return (&OBJ_MGR.objects[counter].as_solid_object);
		}
	return (0);
}

static void					calc_align(
	const t_calc_align_args args)
{
	t_vector	refract_attempt;
	t_vector	tmp;
	double		alignment;

	vector_operator_mulf(&tmp, args.k, &args.intersection->surface_normal);
	vector_operator_add(&refract_attempt, args.dir_unit, &tmp);
	alignment = vector_dot_product(args.dir_unit, &refract_attempt);
	if (alignment > *args.max_alignment)
	{
		*args.refract_dir = refract_attempt;
		*args.max_alignment = alignment;
	}
}

static void					check_solutions(
	const t_check_solutions_args args)
{
	double			k[2];
	double			max_alignment;
	t_vector		refract_dir;
	unsigned int	i;
	int				num_solutions;

	num_solutions =
		solve_quadratic_equation_real(
			(t_calc_variables) {1.0, 2.0 * args.cos_a1,
			1.0 - 1.0 / (args.ratio * args.ratio), 0, 0}, k);
	max_alignment = -0.0001;
	i = -1;
	while ((signed)++i < num_solutions)
		calc_align((t_calc_align_args) {k[i], args.intersection,
			args.dir_unit, &max_alignment, &refract_dir});
	if (max_alignment <= 0.0)
		return ;
	check_align(
		(t_check_align_args)
		{
			args.sin_a2, args.cos_a1, args.vars, args.target_refractive_index,
			args.out_reflection_factor, args.intersection,
			&refract_dir, args.result
		});
}

static void					continue_refraction(
	const t_continue_refraction_args args)
{
	t_vector				test_point;
	t_vector				dir_unit2;
	const t_solid_object	*container;
	double					tab[3];

	vector_operator_mulf(&dir_unit2, 0.001, args.dir_unit);
	vector_operator_add(&test_point, &args.intersection->point, &dir_unit2);
	container = primary_container(&test_point);
	tab[0] = ((container)
		? container->refractive_index
		: get_current_scene(&SCENE_LIST)->ambiant_refraction);
	tab[1] = args.vars.refractive_index / tab[0];
	tab[2] = tab[1] * args.sin_a1;
	if (tab[2] <= -1.0 || tab[2] >= 1.0)
	{
		*args.out_reflection_factor = 1.0;
		*args.result = (t_color){0.0, 0.0, 0.0, 1.0};
		return ;
	}
	check_solutions(
		(t_check_solutions_args)
		{
			tab[1], args.cos_a1, tab[2], args.intersection, args.dir_unit,
			args.vars, args.out_reflection_factor, tab[0], args.result
		});
}

void						calculate_refraction(
	const t_intersection *const intersection,
	const t_reflection_vars vars,
	double *const out_reflection_factor,
	t_color *const result)
{
	t_vector	dir_unit;
	double		cos_a1;
	double		sin_a1;

	vector_unit_vector(vars.incident_dir, &dir_unit);
	cos_a1 = vector_dot_product(&dir_unit, &intersection->surface_normal);
	if (cos_a1 <= -1.0)
	{
		if (cos_a1 < -1.0001)
			return ;
		cos_a1 = -1.0;
		sin_a1 = 0.0;
	}
	else if (cos_a1 >= 1.0)
	{
		if (cos_a1 > 1.0001)
			return ;
		cos_a1 = 1.0;
		sin_a1 = 0.0;
	}
	else
		sin_a1 = sqrtf(1.0 - cos_a1 * cos_a1);
	continue_refraction(
		(t_continue_refraction_args) {&dir_unit, intersection, vars,
			sin_a1, cos_a1, out_reflection_factor, result});
}
