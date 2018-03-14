/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_wrapper.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:54:33 by cgerbaud          #+#    #+#             */
/*   Updated: 2017/07/12 02:34:06 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_WRAPPER_H
# define OBJECT_WRAPPER_H

# include "object_defs.h"
# include "solid_object_wrapper.h"

typedef union				u_object_wrapper
{
	t_object				as_object;
	t_solid_object			as_solid_object;
	t_solid_object_wrapper	as_solid_object_wrapper;
	t_camera				as_camera;
	t_light					as_light;
}							t_object_wrapper;

#endif
