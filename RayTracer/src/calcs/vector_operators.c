/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 06:18:15 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/14 06:19:15 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			vector_operator_add(t_vector *const dst,
									const t_vector *const a,
									const t_vector *const b)
{
	dst->x = a->x + b->x;
	dst->y = a->y + b->y;
	dst->z = a->z + b->z;
}

void			vector_operator_sub(t_vector *const dst,
									const t_vector *const a,
									const t_vector *const b)
{
	dst->x = a->x - b->x;
	dst->y = a->y - b->y;
	dst->z = a->z - b->z;
}

void			vector_operator_mul(t_vector *const dst,
									const t_vector *const a,
									const t_vector *const b)
{
	dst->x = a->x * b->x;
	dst->y = a->y * b->y;
	dst->z = a->z * b->z;
}

void			vector_operator_mulf(t_vector *const dst,
									const double factor,
									const t_vector *const vector)
{
	dst->x = vector->x * factor;
	dst->y = vector->y * factor;
	dst->z = vector->z * factor;
}

void			vector_operator_div(t_vector *const dst,
									const t_vector *const a,
									const t_vector *const b)
{
	dst->x = a->x / b->x;
	dst->y = a->y / b->y;
	dst->z = a->z / b->z;
}
