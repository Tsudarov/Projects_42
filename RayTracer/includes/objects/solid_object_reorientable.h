/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_object_reorientable.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 10:28:51 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/25 16:34:06 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLID_OBJECT_REORIENTABLE_H
# define SOLID_OBJECT_REORIENTABLE_H

# include "solid_object.h"
# include "vector.h"

union u_solid_object_reorientable_wrapper;
union u_solid_object_wrapper;
struct s_string;
struct s_intersection_list;

typedef enum		e_solid_object_reorientables_type
{
	SOLID_OBJECT_REORIENTABLE_TYPE_NOTHING = 0,
	SOLID_OBJECT_REORIENTABLE_TYPE_CUBOID,
	SOLID_OBJECT_REORIENTABLE_TYPE_CONE,
	SOLID_OBJECT_REORIENTABLE_TYPE_CYLINDER,
	SOLID_OBJECT_REORIENTABLE_TYPE_SPHEROID,
	SOLID_OBJECT_REORIENTABLE_TYPE_THINRING,
	SOLID_OBJECT_REORIENTABLE_TYPE_CHESSBOARD,
	SOLID_OBJECT_REORIENTABLE_TYPE_MAX
}					t_solid_object_reorientables_type;

typedef struct		s_solid_object_reorientable
{
	t_solid_object	base_object;
	char			(*contains)
	(const union u_solid_object_reorientable_wrapper *const,
	const t_vector *const);
	void			(*append_all_intersections)
	(const union u_solid_object_reorientable_wrapper *const,
	const struct s_vector *const, const struct s_vector *const,
	struct s_intersection_list **const);
	void			(*surface_optics)
	(const union u_solid_object_reorientable_wrapper *const,
	const struct s_vector *const,
	struct s_optics *const);
	t_vector		r_dir;
	t_vector		s_dir;
	t_vector		t_dir;
	t_vector		x_dir;
	t_vector		y_dir;
	t_vector		z_dir;
}					t_solid_object_reorientable;

char				init_solid_object_reorientable(
	union u_solid_object_wrapper *const solid_object_reorientable,
	const struct s_string *const file);
double				deg2rad(
	const double deg);
void				solid_object_reorientable_append_all_intersections(
	const union u_solid_object_wrapper *const solid_object_wrapper,
	const t_vector *const vantage,
	const t_vector *const direction,
	struct s_intersection_list **const intersection_list);
void				object_dir_from_camera_dir(
	const t_solid_object_reorientable *const object,
	const t_vector *const camera_dir,
	t_vector *const dst);
void				object_point_from_camera_point(
	const t_solid_object_reorientable *const object,
	const t_vector *const camera_point,
	t_vector *const dst);
void				camera_dir_from_object_dir(
	const t_solid_object_reorientable *const object,
	const t_vector *const object_dir,
	t_vector *const dst);
void				camera_point_from_object_point(
	const t_solid_object_reorientable *const object,
	const t_vector *const object_point,
	t_vector *const dst);
void				solid_object_rotate_x(
	union u_object_wrapper *const object_wrapper,
	const double angle_in_degrees);
void				solid_object_rotate_y(
	union u_object_wrapper *const object_wrapper,
	const double angle_in_degrees);
void				solid_object_rotate_z(
	union u_object_wrapper *const object_wrapper,
	const double angle_in_degrees);

#endif
