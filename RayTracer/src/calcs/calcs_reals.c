/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs_reals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 06:29:13 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/14 10:48:33 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "calcs.h"
#include "string.h"

char		is_zero(const NORMAGE x)
{
	return ((fabs(creal(x)) < TOLERANCE) && (fabs(cimag(x)) < TOLERANCE));
}

static int	filter_real_numbers(const int num_complex_value,
							const NORMAGE in_array[],
							double out_array[])
{
	int	counter;
	int	num_real_values;

	counter = -1;
	num_real_values = 0;
	while (++counter < num_complex_value)
		if (fabs(cimag(in_array[counter])) < TOLERANCE)
			out_array[num_real_values++] = creal(in_array[counter]);
	return (num_real_values);
}

char		solve_quadratic_equation_real(t_calc_variables vars,
										double roots[2])
{
	NORMAGE		croots[2];
	int			num_complex_roots;

	ft_bzero(croots, sizeof(croots));
	num_complex_roots = solve_quadratic_equation(
		(t_calc_ivariables)
		{
			(NORMAGE)vars.a,
				(NORMAGE)vars.b,
				(NORMAGE)vars.c,
				(NORMAGE)0,
				(NORMAGE)0
				},
		croots);
	return (filter_real_numbers(num_complex_roots, croots, roots));
}

char		solve_cubic_equation_real(t_calc_variables vars,
									double roots[3])
{
	NORMAGE	croots[3];
	int		num_complex_roots;

	ft_bzero(croots, sizeof(croots));
	num_complex_roots = solve_cubic_equation(
		(t_calc_ivariables)
		{
			(NORMAGE)vars.a,
				(NORMAGE)vars.b,
				(NORMAGE)vars.c,
				(NORMAGE)0,
				(NORMAGE)0
				},
		croots);
	return (filter_real_numbers(num_complex_roots, croots, roots));
}

char		solve_quartic_equation_real(t_calc_variables vars,
										double roots[4])
{
	NORMAGE	croots[4];
	int		num_complex_roots;

	ft_bzero(croots, sizeof(croots));
	num_complex_roots = solve_quartic_equation(
		(t_calc_ivariables)
		{
			(NORMAGE)vars.a,
				(NORMAGE)vars.b,
				(NORMAGE)vars.c,
				(NORMAGE)vars.d,
				(NORMAGE)0
				},
		croots);
	return (filter_real_numbers(num_complex_roots, croots, roots));
}
