/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complement.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:51:02 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 08:46:49 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEMENT_H
# define COMPLEMENT_H

# include "solid_object.h"

union u_solid_object_wrapper;
struct s_string;

typedef struct		s_complement
{
	t_solid_object	base_object;
	t_solid_object	*other;
}					t_complement;

t_solid_object		*create_complement(
	t_solid_object *const other);
char				init_complement(
	union u_solid_object_wrapper *const object_wrapper,
	const struct s_string *datas);
char				complement_contains(
	const union u_solid_object_wrapper *const object_wrapper,
	const t_vector *const point);
void				complement_translate(
	union u_object_wrapper *const object_wrapper,
	const double dx,
	const double dy,
	const double dz);
void				complement_rotate_x(
	union u_object_wrapper *const object_wrapper,
	const double angle_in_degrees);
void				complement_rotate_y(
	union u_object_wrapper *const object_wrapper,
	const double angle_in_degrees);
void				complement_rotate_z(
	union u_object_wrapper *const object_wrapper,
	const double angle_in_degrees);

#endif
