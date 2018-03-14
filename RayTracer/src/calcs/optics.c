/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 00:06:53 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/14 06:12:49 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optics.h"

static char		validate_reflection_color(const t_color *const color)
{
	return (!(color->r < 0.0 || color->r > 1.0 || color->g < 0.0
			|| color->g > 1.0 || color->b < 0.0 || color->b > 1.0));
}

t_optic_error	optics_set_matte_gloss_balance(t_optics *const this,
											const double gloss_factor,
											const t_optics *const raw_optics)
{
	t_color		tmp;

	if (!validate_reflection_color(&raw_optics->matte_color))
		return (OPTIC_ERROR_INVALID_MATTE_COLOR
				| OPTIC_ERROR_SET_MATTE_GLOSS_BALANCE);
		if (!validate_reflection_color(&raw_optics->gloss_color))
		return (OPTIC_ERROR_INVALID_GLOSS_COLOR
				| OPTIC_ERROR_SET_MATTE_GLOSS_BALANCE);
		if (gloss_factor < 0.0 || gloss_factor > 1.0)
		return (OPTIC_ERROR_INVALID_GLOSS_FACTOR
				| OPTIC_ERROR_SET_MATTE_GLOSS_BALANCE);
		tmp = raw_optics->matte_color;
	color_operator_muleqf(&tmp, 1.0 - gloss_factor);
	optics_set_matte_color(this, &tmp);
	tmp = raw_optics->gloss_color;
	color_operator_muleqf(&tmp, gloss_factor);
	optics_set_gloss_color(this, &tmp);
	return (NO_OPTIC_ERROR);
}

t_optic_error	optics_set_matte_color(t_optics *const this,
									const t_color *const matte_color)
{
	if (!matte_color)
	{
		this->matte_color = (t_color){1.0, 1.0, 1.0, 1.0};
		return (NO_OPTIC_ERROR);
	}
	if (!validate_reflection_color(matte_color))
		return (OPTIC_ERROR_INVALID_MATTE_COLOR);
	this->matte_color = *matte_color;
	return (NO_OPTIC_ERROR);
}

t_optic_error	optics_set_gloss_color(t_optics *const this,
									const t_color *const gloss_color)
{
	if (!gloss_color)
	{
		this->gloss_color = (t_color){0.0, 0.0, 0.0, 1.0};
		return (NO_OPTIC_ERROR);
	}
	if (!validate_reflection_color(gloss_color))
		return (OPTIC_ERROR_INVALID_GLOSS_COLOR);
	this->gloss_color = *gloss_color;
	return (NO_OPTIC_ERROR);
}

t_optic_error	optics_set_opacity(t_optics *const this, const double opacity)
{
	if (opacity < 0.0 || opacity > 1.0)
		return (OPTIC_ERROR_INVALID_OPACITY);
	this->opacity = opacity;
	return (NO_OPTIC_ERROR);
}
