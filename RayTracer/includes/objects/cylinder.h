/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:52:41 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:30:44 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include <stddef.h>
# include "solid_object_reorientable.h"

union u_solid_object_reorientable_wrapper;
struct s_string;

typedef struct					s_cylinder
{
	t_solid_object_reorientable	base_object;
	double						height;
	double						ray;
}								t_cylinder;

char							init_cylinder(
	union u_solid_object_reorientable_wrapper *const object_wrapper,
	const struct s_string *datas);

#endif
