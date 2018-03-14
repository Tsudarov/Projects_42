/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:51:02 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:32:55 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include <stddef.h>
# include "solid_object.h"

union u_solid_object_wrapper;
struct s_string;

typedef struct		s_sphere
{
	t_solid_object	base_object;
	double			ray;
}					t_sphere;

char				init_sphere(
	union u_solid_object_wrapper *const object_wrapper,
	const struct s_string *datas);

#endif
