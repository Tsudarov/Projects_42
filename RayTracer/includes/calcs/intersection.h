/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 20:23:54 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:12:48 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include <stddef.h>
# include "vector.h"

struct s_object;
union u_solid_object_wrapper;

typedef struct							s_intersection
{
	double								distance_squared;
	struct s_vector						point;
	struct s_vector						surface_normal;
	const union u_solid_object_wrapper	*solid;
}										t_intersection;

typedef struct							s_intersection_list
{
	t_intersection						*data;
	struct s_intersection_list			*next;
}										t_intersection_list;

void									free_list(
	t_intersection_list *const list);
size_t									list_len(
	const t_intersection_list *const list);
void									intersection_list_push_new_back(
	t_intersection_list **intersection_list,
	const t_intersection *const intersection);

#endif
