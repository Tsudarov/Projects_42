/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 01:06:48 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/15 16:54:00 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "calcs.h"

char		solve_linear_equations(
	const t_linear_variables vars,
	double *const u,
	double *const v,
	double *const w)
{
	double	ovars[7];

	if (fabs(vars.f) < TOLERANCE)
		return (0);
	ovars[0] = vars.e * vars.j - vars.f * vars.ri;
	if (fabs(ovars[0]) < TOLERANCE)
		return (0);
	ovars[1] = vars.d * vars.j - vars.f * vars.h;
	ovars[2] = vars.h * vars.n - vars.j * vars.l;
	ovars[3] = vars.ri * vars.n - vars.j * vars.m;
	ovars[4] = ovars[1] * ovars[3] - ovars[0] * ovars[2];
	if (fabs(ovars[4]) < TOLERANCE)
		return (0);
	ovars[5] = vars.g * vars.j - vars.f * vars.k;
	ovars[6] = vars.k * vars.n - vars.j * vars.p;
	*u = (ovars[0] * ovars[6] - ovars[3] * ovars[5]) / ovars[4];
	*v = -(ovars[1] * *u + ovars[5]) / ovars[0];
	*w = -(vars.d * *u + vars.e * *v + vars.g) / vars.f;
	return (1);
}

char		solve_quadratic_equation(t_calc_ivariables vars,
								NORMAGE roots[2])
{
	NORMAGE radicand;
	NORMAGE r;
	NORMAGE d;

	if (is_zero(vars.a))
	{
		if (is_zero(vars.b))
			return (0);
		roots[0] = -vars.c / vars.b;
		return (1);
	}
	radicand = vars.b * vars.b - 4.0 * vars.a * vars.c;
	if (is_zero(radicand))
	{
		roots[0] = -vars.b / (2.0 * vars.a);
		return (1);
	}
	r = csqrt(radicand);
	d = 2.0 * vars.a;
	roots[0] = (-vars.b + r) / d;
	roots[1] = (-vars.b - r) / d;
	return (2);
}

NORMAGE		mcbrt(const NORMAGE a, const int n)
{
	const double twopi = 2.0 * M_PI;
	const double rho = cpow(cabs(a), 1.0 / 3.0);
	const double theta = ((twopi * n) + carg(a)) / 3.0;

	return ((NORMAGE){rho * cos(theta), rho * sin(theta)});
}

static void	end_cubic(const NORMAGE s,
					const NORMAGE f,
					const NORMAGE d,
					NORMAGE roots[3])
{
	unsigned int	counter;
	NORMAGE			g;

	counter = -1;
	while (++counter < 3)
	{
		g = mcbrt(f, counter);
		roots[counter] = g - d / g - s;
	}
}

char		solve_cubic_equation(t_calc_ivariables vars,
							NORMAGE roots[3])
{
	NORMAGE s;
	NORMAGE d;
	NORMAGE e;
	NORMAGE froot;
	NORMAGE f;

	if (is_zero(vars.a))
		return (solve_quadratic_equation((t_calc_ivariables)
			{vars.b, vars.c, vars.d, 0, 0}, roots));
		vars.b /= vars.a;
	vars.c /= vars.a;
	vars.d /= vars.a;
	s = vars.b / 3.0;
	d = vars.c / 3.0 - s * s;
	e = s * s * s + (vars.d - s * vars.c) / 2.0;
	froot = sqrt(e * e + d * d * d);
	f = -froot - e;
	if (is_zero(f))
		f = froot - e;
	end_cubic(s, f, d, roots);
	return (3);
}
