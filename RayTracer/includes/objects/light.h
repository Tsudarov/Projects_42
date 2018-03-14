/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 02:29:18 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:39:46 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include <stddef.h>
# include "object.h"
# include "color.h"

union u_object_wrapper;
struct s_string;

typedef struct		s_light
{
	struct s_object	base_object;
	struct s_color	color;
}					t_light;

char				init_light(union u_object_wrapper *const object_wrapper,
							const struct s_string *datas);

#endif
