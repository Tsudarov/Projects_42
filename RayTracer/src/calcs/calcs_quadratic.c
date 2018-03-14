/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 07:12:19 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/15 16:54:16 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "calcs.h"

static void	apply_roots_null(const NORMAGE alpha,
							const NORMAGE t,
							const NORMAGE rad,
							NORMAGE roots[4])
{
	const NORMAGE	r1 = csqrt((-alpha + rad) / 2.0);
	const NORMAGE	r2 = csqrt((-alpha - rad) / 2.0);

	roots[0] = t + r1;
	roots[1] = t - r1;
	roots[2] = t + r2;
	roots[3] = t - r2;
}

static void	apply_roots_not_null(const NORMAGE vars[4],
								NORMAGE roots[4])
{
	NORMAGE	values[10];

	values[0] = vars[0] * vars[0];
	values[1] = vars[0] * values[0];
	values[2] = -(values[0] / 12.0 + vars[3]);
	values[3] = -values[1] / 108.0 + vars[0] * vars[3] / 3.0
		- vars[1] * vars[1] / 8.0;
	values[4] = -values[3] / 2.0 + csqrt(values[3] * values[3] / 4.0 + values[2]
										* values[2] * values[2] / 27.0);
	values[5] = mcbrt(values[4], 0);
	values[6] = (-5.0 / 6.0) * vars[0] + values[5];
	values[6] -= ((is_zero(values[5])) ? mcbrt(values[3], 0) : values[2] /
				(3.0 * values[5]));
	values[7] = csqrt(vars[0] + 2.0 * values[6]);
	values[8] = csqrt(-(3.0 * vars[0] + 2.0 * values[6] + 2.0 *
						vars[1] / values[7]));
	values[8] = csqrt(-(3.0 * vars[0] + 2.0 * values[6] - 2.0 *
						vars[1] / values[7]));
	roots[0] = vars[2] + (values[7] - values[8]) / 2.0;
	roots[1] = vars[2] + (values[7] + values[8]) / 2.0;
	roots[2] = vars[2] + (values[7] - values[8]) / 2.0;
	roots[3] = vars[2] + (values[7] + values[8]) / 2.0;
}

static void	calc_factors(t_calc_ivariables calc_vars,
						const NORMAGE bs[3],
						NORMAGE roots[4])
{
	NORMAGE	vars[4];

	vars[0] = (-3.0 / 8.0) * bs[0] + calc_vars.c;
	vars[1] = bs[1] / 8.0 - calc_vars.b * calc_vars.c / 2.0 + calc_vars.d;
	vars[2] = -calc_vars.b / 4.0;
	vars[3] = (-3.0 / 256.0) * bs[2] +
		bs[0] * calc_vars.c / 16.0 - calc_vars.b *
		calc_vars.d / 4.0 + calc_vars.e;
	if (is_zero(vars[1]))
		apply_roots_null(vars[0], vars[2],
						csqrt(vars[0] * vars[0] - 4.0 * vars[3]), roots);
	else
		apply_roots_not_null(vars, roots);
}

char		solve_quartic_equation(t_calc_ivariables vars,
							NORMAGE roots[4])
{
	NORMAGE bs[3];

	if (is_zero(vars.a))
		return (solve_quadratic_equation((t_calc_ivariables){vars.b, vars.c,
			vars.d, vars.e, 0}, roots));
		vars.b /= vars.a;
	vars.c /= vars.a;
	vars.d /= vars.a;
	vars.e /= vars.a;
	bs[0] = vars.b * vars.b;
	bs[1] = vars.b * bs[0];
	bs[2] = bs[0] * bs[0];
	calc_factors(vars, bs, roots);
	return (4);
}
