/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 20:40:53 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:24:25 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "color.h"

struct s_vector;
struct s_string;

typedef struct			s_scene
{
	struct s_color		background_color;
	double				ambiant_refraction;
	double				zoom;
	unsigned char		antialias;
	unsigned int		width;
	unsigned int		height;
}						t_scene;

void					init_scene(t_scene *const scene,
								const struct s_string *const str);
char					has_clear_line_of_sight(
	const struct s_vector *const v1,
	const struct s_vector *const v2);
double					polarized_reflection(
	const double n1,
	const double n2,
	const double cos_a1,
	const double cos_a2);
unsigned char			convert_pixel_value(const double color_component,
											const double max_color_value);

#endif
