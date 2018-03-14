/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optics.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 20:11:19 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:16:56 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTICS_H
# define OPTICS_H

# include "color.h"

# define OPACITY_DEFAULT_VALUE 1.0

typedef struct		s_optics
{
	struct s_color	matte_color;
	struct s_color	gloss_color;
	double			opacity;
}					t_optics;

typedef enum		e_optic_error
{
	NO_OPTIC_ERROR = 0,
	OPTIC_ERROR_INVALID_MATTE_COLOR = 1,
	OPTIC_ERROR_INVALID_GLOSS_COLOR = OPTIC_ERROR_INVALID_MATTE_COLOR << 1,
	OPTIC_ERROR_INVALID_GLOSS_FACTOR = OPTIC_ERROR_INVALID_GLOSS_COLOR << 1,
	OPTIC_ERROR_INVALID_OPACITY = OPTIC_ERROR_INVALID_GLOSS_FACTOR << 1,
	OPTIC_ERROR_SET_MATTE_GLOSS_BALANCE = OPTIC_ERROR_INVALID_OPACITY << 1
}					t_optic_error;

struct s_string;

t_optic_error		init_optics(t_optics *const this,
								const struct s_color *const matte_color,
								const struct s_color *const gloss_color,
								const double opacity);
char				init_optics_from_string(t_optics *const this,
										const struct s_string *const string);
t_optic_error		optics_set_matte_gloss_balance(t_optics *const this,
											const double gloss_factor,
											const t_optics *const raw_optics);
t_optic_error		optics_set_matte_color(t_optics *const this,
									const struct s_color *const matte_color);
t_optic_error		optics_set_gloss_color(t_optics *const this,
									const struct s_color *const gloss_color);
t_optic_error		optics_set_opacity(t_optics *const this,
								const double opacity);

#endif
