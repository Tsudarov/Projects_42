/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_object_reorientable.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 10:28:51 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:31:26 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNION_H
# define UNION_H

# include "binary_operator.h"

union u_binary_operator_wrapper;
struct s_string;

typedef struct					s_union
{
	struct s_binary_operator	base_object;
}								t_union;

char							init_union(
	union u_binary_operator_wrapper *const o_union,
	const struct s_string *const file);

#endif
