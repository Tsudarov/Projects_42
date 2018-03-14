/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_optics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 06:11:30 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/14 06:22:38 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "optics.h"
#include "string.h"

char			init_optics_from_string(t_optics *const this,
										const t_string *const string)
{
	t_optic_error	error_flag;
	t_string		value;
	t_color			color;

	error_flag = NO_OPTIC_ERROR;
	if (!(extract_value(&value, "Opacity", string)))
		return (0);
	if ((error_flag |= optics_set_opacity(this, strtod(value.data_ptr, 0))))
		return (0);
	if (!(extract_value(&value, "Gloss color", string)))
		return (0);
	if (!(init_color_float(&color, &value)))
		return (0);
	if ((error_flag |= optics_set_gloss_color(this, &color)))
		return (0);
	if (!(extract_value(&value, "Matte color", string)))
		return (0);
	if (!(init_color_float(&color, &value)))
		return (0);
	if ((error_flag |= optics_set_matte_color(this, &color)))
		return (0);
	return (1);
}

t_optic_error	init_optics(t_optics *const this,
							const t_color *const matte_color,
							const t_color *const gloss_color,
							const double opacity)
{
	t_optic_error	error_flag;

	error_flag = NO_OPTIC_ERROR;
	error_flag |= optics_set_matte_color(this, matte_color);
	error_flag |= optics_set_gloss_color(this, gloss_color);
	error_flag |= optics_set_opacity(this, opacity);
	return (error_flag);
}
