/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_object_reorientable.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 10:28:51 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:44:21 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIFFERENCE_H
# define DIFFERENCE_H

# include "intersection_o.h"
# include "vector.h"

union u_binary_operator_wrapper;
struct s_string;

typedef struct				s_difference
{
	struct s_intersection_o	base_object;
}							t_difference;

char						init_difference(
	union u_binary_operator_wrapper *const difference,
	const struct s_string *const file);

#endif
