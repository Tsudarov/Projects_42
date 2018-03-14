/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 20:04:16 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:17:52 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

struct s_string;

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
	double		lum;
}				t_color;

char			init_color_float(t_color *const this,
								const struct s_string *const str);
void			color_operator_addeq(t_color *const this,
									const t_color *const other);
void			color_operator_addeqf(t_color *const this,
									const double addition);
void			color_operator_muleq(t_color *const this,
									const t_color *const other);
void			color_operator_muleqf(t_color *const this,
									const double factor);
void			color_operator_diveq(t_color *const this,
									const double denom);
void			color_operator_mul(t_color *const dst, const t_color *const a,
								const t_color *const b);
void			color_operator_mulf(t_color *const dst, const double scalar,
									const t_color *const color);
void			color_operator_add(t_color *const dst, const t_color *const a,
								const t_color *const b);

#endif
