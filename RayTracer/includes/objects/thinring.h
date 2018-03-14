/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinring.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:52:41 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:32:41 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THINRING_H
# define THINRING_H

# include "solid_object_reorientable.h"

union u_solid_object_reorientable_wrapper;
struct s_string;

typedef struct					s_thinring
{
	t_solid_object_reorientable	base_object;
	double						inner_radius;
	double						outer_radius;
}								t_thinring;

char							init_thinring(
	union u_solid_object_reorientable_wrapper *const object_wrapper,
	const struct s_string *datas);

#endif
