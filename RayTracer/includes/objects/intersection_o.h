/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_object_reorientable.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 10:28:51 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 08:46:32 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_O_H
# define INTERSECTION_O_H

# include "binary_operator.h"

union u_binary_operator_wrapper;
struct s_string;

typedef struct					s_intersection_o
{
	struct s_binary_operator	base_object;
}								t_intersection_o;

char							init_intersection(
	union u_binary_operator_wrapper *const intersection,
	const struct s_string *const file);
char							intersection_contains(
	const union u_solid_object_wrapper *const object_wrapper,
	const t_vector *const point);
void							calculate_intersection_intersection(
	const union u_solid_object_wrapper *const object_wrapper,
	const t_vector *const vantage,
	const t_vector *const direction,
	struct s_intersection_list **const intersection_list);

#endif
