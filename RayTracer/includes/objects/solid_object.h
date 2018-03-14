/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_object.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 01:56:31 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/25 16:33:47 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLID_OBJECT_H
# define SOLID_OBJECT_H

# include "object.h"
# include "optics.h"

union u_solid_object_wrapper;
union u_object_wrapper;
struct s_intersection_list;

typedef enum	e_solid_objects_type
{
	SOLID_OBJECT_TYPE_NOTHING = 0,
	SOLID_OBJECT_TYPE_REORIENTABLE,
	SOLID_OBJECT_TYPE_SPHERE,
	SOLID_OBJECT_TYPE_BINARY_OPERATOR,
	SOLID_OBJECT_TYPE_MAX
}				t_solid_objects_type;

typedef struct	s_solid_object
{
	t_object	base_object;
	t_optics	uniform_optics;
	double		refractive_index;
	void		(*append_all_intersections)
	(const union u_solid_object_wrapper *const,
	const struct s_vector *const,
	const struct s_vector *const,
	struct s_intersection_list **const);
	char		(*contains)
	(const union u_solid_object_wrapper *const,
	const struct s_vector *const);
	void		(*surface_optics)
	(const union u_solid_object_wrapper *const,
	const struct s_vector *const,
	struct s_optics *const);
}				t_solid_object;

char			init_solid_object(
	union u_object_wrapper *const solid_object,
	const struct s_string *const file);
void			solid_object_translate(
	union u_solid_object_wrapper *const object_wrapper,
	const double dx,
	const double dy,
	const double dz);

#endif
