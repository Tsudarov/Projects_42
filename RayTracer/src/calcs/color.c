/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 23:54:25 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/14 06:10:14 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "color.h"
#include "string.h"

static void		factorise(t_color *const this,
						const t_string *const str,
						char *line_ptr)
{
	double		factor;

	if (line_ptr < str->data_ptr + str->size)
	{
		factor = strtod(line_ptr, &line_ptr);
		if (line_ptr <= str->data_ptr + str->size)
		{
			this->r *= factor;
			this->g *= factor;
			this->b *= factor;
		}
	}
}

char			init_color_float(t_color *const this, const t_string *const str)
{
	char		*line_ptr;

	line_ptr = (char*)str->data_ptr;
	this->r = strtod(line_ptr, &line_ptr);
	if (line_ptr > str->data_ptr + str->size)
		return (0);
	while (++line_ptr < str->data_ptr + str->size
		&& (*line_ptr < '0' || *line_ptr > '9'))
		;
	this->g = strtod(line_ptr, &line_ptr);
	if (line_ptr > str->data_ptr + str->size)
		return (0);
	while (++line_ptr < str->data_ptr + str->size
		&& (*line_ptr < '0' || *line_ptr > '9'))
		;
	this->b = strtod(line_ptr, &line_ptr);
	if (line_ptr > str->data_ptr + str->size)
		return (0);
	while (++line_ptr < str->data_ptr + str->size
		&& (*line_ptr < '0' || *line_ptr > '9'))
		;
	factorise(this, str, line_ptr);
	this->lum = 1.0;
	return (1);
}

void			color_operator_addeq(t_color *const this,
									const t_color *const other)
{
	this->r += other->r;
	this->g += other->g;
	this->b += other->b;
}

void			color_operator_muleq(t_color *const this,
									const t_color *const other)
{
	this->r *= other->r;
	this->g *= other->g;
	this->b *= other->b;
}
