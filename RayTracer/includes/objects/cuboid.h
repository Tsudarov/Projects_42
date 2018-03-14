/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:52:41 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 08:46:07 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBOID_H
# define CUBOID_H

# include "solid_object_reorientable.h"

union u_solid_object_reorientable_wrapper;
struct s_string;
struct s_intersection_list;

typedef struct					s_cuboid
{
	t_solid_object_reorientable	base_object;
	double						a;
	double						b;
	double						c;
}								t_cuboid;

char							init_cuboid(
	union u_solid_object_reorientable_wrapper *const object_wrapper,
	const struct s_string *datas);
char							cuboid_contains(
	const union u_solid_object_reorientable_wrapper *const object_wrapper,
	const t_vector *const point);
void							calculate_cuboid_intersection(
	const union u_solid_object_reorientable_wrapper *const object_wrapper,
	const t_vector *const vantage,
	const t_vector *const direction,
	struct s_intersection_list **const intersection_list);
void							cuboid_check_x(
	const union u_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vd[2],
	struct s_intersection_list **const intersection_list,
	const double a);
void							cuboid_check_y(
	const union u_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vd[2],
	struct s_intersection_list **const intersection_list,
	const double b);
void							cuboid_check_z(
	const union u_solid_object_reorientable_wrapper *const solid_object_wrapper,
	const t_vector *const vd[2],
	struct s_intersection_list **const intersection_list,
	const double c);

#endif
