/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheroid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:52:41 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 17:09:29 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHEROID_H
# define SPHEROID_H

# include "solid_object_reorientable.h"

union u_solid_object_reorientable_wrapper;
struct s_string;

typedef struct					s_spheroid
{
	t_solid_object_reorientable	base_object;
	double						a;
	double						b;
	double						c;
	double						a2;
	double						b2;
	double						c2;
}								t_spheroid;

char							init_spheroid(
	union u_solid_object_reorientable_wrapper *const object_wrapper,
	const struct s_string *datas);

#endif
