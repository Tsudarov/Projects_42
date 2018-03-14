/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_operator_wrapper.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 02:32:28 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 17:08:06 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_OPERATOR_WRAPPER_H
# define BINARY_OPERATOR_WRAPPER_H

# include "binary_operator.h"
# include "difference.h"
# include "intersection_o.h"
# include "union.h"

typedef union			u_binary_operator_wrapper
{
	t_binary_operator	as_binary_operator;
	t_difference		as_difference;
	t_intersection_o	as_intersection;
	t_union				as_union;
}						t_binary_operator_wrapper;

#endif
