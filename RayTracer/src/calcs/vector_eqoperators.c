/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_eqoperators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 06:19:10 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/14 06:19:19 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			vector_operator_multeq(t_vector *const this,
									const double factor)
{
	this->x *= factor;
	this->y *= factor;
	this->z *= factor;
}

void			vector_operator_addeq(t_vector *const this,
									const t_vector *const other)
{
	this->x += other->x;
	this->y += other->y;
	this->z += other->z;
}

void			vector_operator_subeq(t_vector *const dst,
									const t_vector *const a)
{
	dst->x -= a->x;
	dst->y -= a->y;
	dst->z -= a->z;
}

void			vector_operator_addf(t_vector *const dst,
									const double val,
									const t_vector *const b)
{
	dst->x = b->x + val;
	dst->y = b->y + val;
	dst->z = b->z + val;
}

void			vector_operator_inv(t_vector *const dst,
									const t_vector *const src)
{
	dst->x = -src->x;
	dst->y = -src->y;
	dst->z = -src->z;
}
