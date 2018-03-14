/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_object_wrapper.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 02:32:28 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/25 16:34:29 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLID_OBJECT_WRAPPER_H
# define SOLID_OBJECT_WRAPPER_H

# include "object_defs.h"
# include "solid_object_reorientable.h"
# include "solid_object_reorientable_wrapper.h"
# include "binary_operator_wrapper.h"
# include "complement.h"

typedef union							u_solid_object_wrapper
{
	t_solid_object						as_solid_object;
	t_solid_object_reorientable			as_solid_object_reorientable;
	t_solid_object_reorientable_wrapper	as_solid_object_reorientable_wrapper;
	t_sphere							as_sphere;
	t_binary_operator_wrapper			as_binary_operator_wrapper;
	t_complement						as_complement;
}										t_solid_object_wrapper;

#endif
