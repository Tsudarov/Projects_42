/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_object_reorientable_wrapper.h                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 11:17:49 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/25 16:34:44 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLID_OBJECT_REORIENTABLE_WRAPPER_H
# define SOLID_OBJECT_REORIENTABLE_WRAPPER_H

# include "object_defs.h"
# include "solid_object_reorientable.h"

typedef union					u_solid_object_reorientable_wrapper
{
	t_solid_object_reorientable	as_solid_object_reorientable;
	t_cuboid					as_cuboid;
	t_cone						as_cone;
	t_cylinder					as_cylinder;
	t_spheroid					as_spheroid;
	t_thinring					as_thinring;
	t_chessboard				as_chessboard;
}								t_solid_object_reorientable_wrapper;

#endif
