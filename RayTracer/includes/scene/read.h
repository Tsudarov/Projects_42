/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 02:49:07 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 13:23:16 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include <stddef.h>

# define BUFF_SIZE 256

struct s_string;

typedef struct		s_read
{
	size_t			ret;
	char			buff[BUFF_SIZE];
	struct s_read	*next;
}					t_read;

char				read_scene_file(const char *const filename,
									struct s_string *const dst);

#endif
