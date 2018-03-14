/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:29:27 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/19 10:32:47 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "scene_list.h"

const t_scene	*get_current_scene(const t_scene_list *const scene_list)
{
	return (get_current_scene_list_member((t_scene_list*)scene_list)->scene);
}
