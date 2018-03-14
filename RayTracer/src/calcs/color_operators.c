/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 06:07:29 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/14 06:07:43 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void			color_operator_muleqf(t_color *const this, const double factor)
{
	this->r *= factor;
	this->g *= factor;
	this->b *= factor;
}

void			color_operator_diveq(t_color *const this, const double denom)
{
	this->r /= denom;
	this->g /= denom;
	this->b /= denom;
}

void			color_operator_mul(t_color *const dst,
								const t_color *const a,
								const t_color *const b)
{
	dst->r = a->r * b->r;
	dst->g = a->g * b->g;
	dst->b = a->b * b->b;
}

void			color_operator_mulf(t_color *const dst,
									const double scalar,
									const t_color *const color)
{
	dst->r = color->r * scalar;
	dst->g = color->g * scalar;
	dst->b = color->b * scalar;
}

void			color_operator_add(t_color *const dst,
								const t_color *const a,
								const t_color *const b)
{
	dst->r = a->r + b->r;
	dst->g = a->g + b->g;
	dst->b = a->b + b->b;
}
