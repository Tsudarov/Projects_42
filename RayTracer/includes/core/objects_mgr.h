/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_mgr.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:33:06 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:21:02 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_MGR_H
# define OBJECTS_MGR_H

# include <stddef.h>

union u_object_wrapper;
struct s_light;
struct s_camera;
struct s_string;

typedef struct				s_objects_mgr
{
	union u_object_wrapper	*objects;
	size_t					objects_len;
	const struct s_light	**lights;
	const struct s_camera	*camera;
}							t_objects_mgr;

char						init_objects_mgr(t_objects_mgr *const objects_mgr,
											const struct s_string *const file);
void						destroy_objects_mgr(
	t_objects_mgr *const objects_mgr);

#endif
