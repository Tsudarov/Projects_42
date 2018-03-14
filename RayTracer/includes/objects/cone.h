/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:51:02 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/25 17:16:21 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include <stddef.h>
# include "solid_object_reorientable.h"
# include "vector.h"

union u_solid_object_reorientable_wrapper;
struct s_string;

typedef struct					s_cone
{
	t_solid_object_reorientable	base_object;
	double						angle;
	t_vector					axis;
}								t_cone;

char							init_cone(
	union u_solid_object_reorientable_wrapper *const object_wrapper,
	const struct s_string *datas);

#endif
