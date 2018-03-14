/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chessboard.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:52:41 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:43:21 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHESSBOARD_H
# define CHESSBOARD_H

# include "cuboid.h"
# include "color.h"

union u_solid_object_reorientable_wrapper;
struct s_string;

typedef struct	s_chessboard
{
	t_cuboid	base_object;
	double		inner_size;
	double		thickness;
	t_color		light;
	t_color		dark;
	t_color		border;
}				t_chessboard;

char			init_chessboard(
	union u_solid_object_reorientable_wrapper *const object_wrapper,
	const struct s_string *datas);

#endif
