/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_unit_vector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 06:19:51 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/14 06:22:58 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			vector_unit_vector(const t_vector *const this,
								t_vector *const copy)
{
	const double	mag = vector_magnitude(this);

	copy->x = this->x / mag;
	copy->y = this->y / mag;
	copy->z = this->z / mag;
}
