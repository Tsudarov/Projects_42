/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 00:49:13 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 08:44:40 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCS_H
# define CALCS_H

# include <complex.h>

# define TOLERANCE (double)1.0e-8
# define NORMAGE double complex

typedef struct	s_linear_variables
{
	double		d;
	double		e;
	double		f;
	double		g;
	double		h;
	double		ri;
	double		j;
	double		k;
	double		l;
	double		m;
	double		n;
	double		p;
}				t_linear_variables;

typedef struct	s_calc_ivariables
{
	NORMAGE		a;
	NORMAGE		b;
	NORMAGE		c;
	NORMAGE		d;
	NORMAGE		e;
}				t_calc_ivariables;

typedef struct	s_calc_variables
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		e;
}				t_calc_variables;

char			is_zero(
	const NORMAGE x);
char			solve_linear_equations(
				const t_linear_variables vars,
				double *const u,
				double *const v,
				double *const w);
char			solve_quadratic_equation(
	t_calc_ivariables vars,
	NORMAGE roots[2]);
char			solve_cubic_equation(
	t_calc_ivariables vars,
	NORMAGE roots[3]);
char			solve_quartic_equation(
	t_calc_ivariables vars,
	NORMAGE roots[4]);
char			solve_quadratic_equation_real(
	t_calc_variables vars,
	double roots[2]);
char			solve_cubic_equation_real(
	t_calc_variables vars,
	double roots[3]);
char			solve_quartic_equation_real(
	t_calc_variables vars,
	double roots[4]);
NORMAGE			mcbrt(
	const NORMAGE a,
	const int n);

#endif
