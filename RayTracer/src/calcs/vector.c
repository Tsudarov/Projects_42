/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 23:36:38 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/14 06:20:10 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "vector.h"
#include "string.h"

char			init_vector(t_vector *const target, const t_string *const str)
{
	const char	*line_ptr = str->data_ptr;

	target->x = strtod(line_ptr, (char**)&line_ptr);
	if (line_ptr > str->data_ptr + str->size)
		return (0);
	while ((*line_ptr < '0' || *line_ptr > '9') && *line_ptr != '-')
		line_ptr++;
	target->y = strtod(line_ptr, (char**)&line_ptr);
	if (line_ptr > str->data_ptr + str->size)
		return (0);
	while ((*line_ptr < '0' || *line_ptr > '9') && *line_ptr != '-')
		line_ptr++;
	target->z = strtod(line_ptr, (char**)&line_ptr);
	if (line_ptr > str->data_ptr + str->size)
		return (0);
	return (1);
}

double			vector_magnitude_squared(const t_vector *const this)
{
	return ((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

double			vector_magnitude(const t_vector *const this)
{
	return (sqrtf(vector_magnitude_squared(this)));
}

double			vector_dot_product(const t_vector *const a,
								const t_vector *const b)
{
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
}

void			vector_cross_product(t_vector *const dst,
									const t_vector *const a,
									const t_vector *const b)
{
	dst->x = (a->y * b->z) - (a->z * b->y);
	dst->y = (a->z * b->x) - (a->x * b->z);
	dst->z = (a->x * b->y) - (a->y * b->x);
}
