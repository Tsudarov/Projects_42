/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_object_reorientable.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 10:28:51 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 06:43:41 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_OPERATOR_H
# define BINARY_OPERATOR_H

# include "solid_object.h"
# include "vector.h"

union u_solid_object_wrapper;
struct s_string;

typedef enum		e_binary_operator_types
{
	BINARY_OPERATOR_TYPE_NOTHING = 0,
	BINARY_OPERATOR_TYPE_DIFFERENCE,
	BINARY_OPERATOR_TYPE_INTERSECTION,
	BINARY_OPERATOR_TYPE_UNION,
	BINARY_OPERATOR_TYPE_MAX
}					t_binary_operator_types;

typedef struct		s_binary_operator
{
	t_solid_object	base_object;
	t_solid_object	*left;
	t_solid_object	*right;
}					t_binary_operator;

char				init_binary_operator(
	union u_solid_object_wrapper *const binary_operator,
	const struct s_string *const file);
void				binary_operator_rotate_x(
	union u_object_wrapper *const object_wrapper,
	const double angle_in_degrees);
void				binary_operator_rotate_y(
	union u_object_wrapper *const object_wrapper,
	const double angle_in_degrees);
void				binary_operator_rotate_z(
	union u_object_wrapper *const object_wrapper,
	const double angle_in_degrees);

#endif
