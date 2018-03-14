/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 19:32:40 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 09:26:16 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_H
# define RAYTRACE_H

# define EPSILON 1.0e-6
# define MIN_OPTICAL_INTENSITY 0.001
# define MAX_OPTICAL_RECURSION_DEPTH 20
# define FIELD_OF_VIEW 2.0

struct s_vector;
struct s_color;
struct s_intersection;
struct s_intersection_list;
struct s_optics;

typedef struct					s_reflection_vars
{
	struct s_vector				*incident_dir;
	struct s_color				*ray_intensity;
	double						refractive_index;
	int							recursion_depth;
}								t_reflection_vars;

typedef struct					s_check_reflection_vars
{
	const struct s_intersection *intersection;
	const t_reflection_vars		vars;
	const double				transparency;
	const double				refractive_reflection_factor;
	const struct s_optics		*optics;
	const double				opacity;
	struct s_color				*result;
}								t_check_reflection_vars;

typedef struct					s_add_opacity_vars
{
	const t_reflection_vars		vars;
	const struct s_optics		*optics;
	const double				opacity;
	struct s_color				*result;
	const struct s_intersection	*intersection;
}								t_add_opacity_vars;

typedef struct					s_check_align_args
{
	const double				sin_a2;
	const double				cos_a1;
	const t_reflection_vars		vars;
	const double				target_refractive_index;
	double						*out_reflection_factor;
	const struct s_intersection	*intersection;
	struct s_vector				*refract_dir;
	struct s_color				*result;
}								t_check_align_args;

typedef struct					s_calc_align_args
{
	const double				k;
	const struct s_intersection	*intersection;
	const struct s_vector		*dir_unit;
	double						*max_alignment;
	struct s_vector				*refract_dir;
}								t_calc_align_args;

typedef struct					s_check_solutions_args
{
	const double				ratio;
	const double				cos_a1;
	const double				sin_a2;
	const struct s_intersection	*intersection;
	const struct s_vector		*dir_unit;
	const t_reflection_vars		vars;
	double						*out_reflection_factor;
	const double				target_refractive_index;
	struct s_color				*result;
}								t_check_solutions_args;

typedef struct					s_continue_refraction_args
{
	const struct s_vector		*dir_unit;
	const struct s_intersection	*intersection;
	const t_reflection_vars		vars;
	const double				sin_a1;
	const double				cos_a1;
	double						*out_reflection_factor;
	struct s_color				*result;
}								t_continue_refraction_args;

void							trace_ray(
	const struct s_vector *const vantage,
	const t_reflection_vars vars,
	struct s_color *const result);
void							raytrace(void);
void							calculate_reflection(
	const struct s_intersection *const intersection,
	const t_reflection_vars vars,
	struct s_color *const result);
void							calculate_refraction(
	const struct s_intersection *const intersection,
	const t_reflection_vars vars,
	double *const out_reflection_factor,
	struct s_color *const result);
void							calculate_matte(
	const struct s_intersection *const intersection,
	struct s_color *const result);
char							is_on_los(
	const struct s_vector *const a,
	const struct s_vector *const b);
void							check_align(
	const t_check_align_args args);
int								pick_closest_intersection(
	const struct s_intersection_list *const list,
	struct s_intersection *const intersection);
void							calculate_lightning(
	const struct s_intersection *const intersection,
	const t_reflection_vars vars,
	struct s_color *const result);

#endif
