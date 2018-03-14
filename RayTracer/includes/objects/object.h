/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:33:08 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 08:47:04 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stddef.h>
# include "vector.h"

typedef enum		e_objects_type
{
	OBJECT_TYPE_NOTHING = 0,
	OBJECT_TYPE_CAMERA,
	OBJECT_TYPE_LIGHT,
	OBJECT_TYPE_SOLID_OBJECT,
	OBJECT_TYPE_MAX
}					t_objects_type;

typedef enum		e_object_flag
{
	OBJECT_FLAG_NUL = 0,
	OBJECT_FLAG_ACTIVE = 1
}					t_object_flag;

union u_object_wrapper;
union u_solid_object_wrapper;
struct s_string;

typedef struct		s_object
{
	t_vector		coords;
	t_objects_type	object_type;
	t_object_flag	object_flag;
	void			(*destroy_object)(union u_object_wrapper *const);
	void			(*rotate_x)(union u_object_wrapper *const, const double);
	void			(*rotate_y)(union u_object_wrapper *const, const double);
	void			(*rotate_z)(union u_object_wrapper *const, const double);
	void			(*translate)
	(union u_object_wrapper *const, const double, const double, const double);
}					t_object;

char				create_object(
	t_object *const object,
	const struct s_string *const file);
void				null_rotate(
	union u_object_wrapper *const object,
	const double angle);
void				object_translate(
	union u_object_wrapper *const object_wrapper,
	const double dx,
	const double dy,
	const double dz);
void				destroy_object_null(
	union u_object_wrapper *const object);

#endif
