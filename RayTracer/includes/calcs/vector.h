/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 05:37:06 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:15:30 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

struct s_string;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

char			init_vector(t_vector *const this,
							const struct s_string *const str);
double			vector_magnitude_squared(const t_vector *const this);
double			vector_magnitude(const t_vector *const this);
void			vector_unit_vector(const t_vector *const this,
								t_vector *const copy);
void			vector_operator_multeq(t_vector *const this,
									const double factor);
void			vector_operator_addeq(t_vector *const this,
									const t_vector *const other);
void			vector_operator_add(t_vector *const dst,
									const t_vector *const a,
									const t_vector *const b);
void			vector_operator_addf(t_vector *const dst, const double val,
									const t_vector *const b);
void			vector_operator_sub(t_vector *const dst,
									const t_vector *const a,
									const t_vector *const b);
void			vector_operator_subeq(t_vector *const dst,
									const t_vector *const a);
void			vector_operator_inv(t_vector *const dst,
									const t_vector *const src);
double			vector_dot_product(const t_vector *const a,
								const t_vector *const b);
void			vector_cross_product(t_vector *const dst,
								const t_vector *const a,
								const t_vector *const b);
void			vector_operator_mul(t_vector *const dst,
									const t_vector *const a,
									const t_vector *const b);
void			vector_operator_mulf(t_vector *const dst, const double a,
									const t_vector *const b);
void			vector_operator_div(t_vector *const dst,
									const t_vector *const a,
									const t_vector *const b);

#endif
