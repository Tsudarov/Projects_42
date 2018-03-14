/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:04:31 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:41:41 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <stddef.h>
# include "object.h"
# include "vector.h"

union u_object_wrapper;
struct s_string;

typedef struct		s_camera
{
	struct s_object	base_object;
	t_vector		direction;
}					t_camera;

char				init_camera(union u_object_wrapper *const object_wrapper,
								const struct s_string *datas);

#endif
