/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exctract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:09:01 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 15:37:14 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	extract_value(
	t_string *const dst,
	const char *const name,
	const t_string *const str)
{
	t_string	var_name;
	size_t		counter;

	counter = -1;
	while (++counter < str->size)
	{
		if (str->data_ptr[counter] != '<' || !(extract_text_between_tag(
			&var_name, &str->data_ptr[counter], str->size - counter)) ||
			!ft_string_equal(&var_name, name, 0))
			continue ;
		dst->data_ptr = str->data_ptr + counter + 2 + var_name.size;
		dst->size = -1;
		while (counter + ++dst->size < str->size)
		{
			if (dst->data_ptr[dst->size] != '<'
				|| dst->data_ptr[dst->size + 1] != '/' ||
				!(extract_text_between_tag(&var_name,
				&dst->data_ptr[dst->size], str->size - (counter + dst->size)))
				|| !ft_string_equal(&var_name, name, 1))
				continue;
			return (1);
		}
	}
	return (0);
}

char	extract_value_loop(
	t_string *const dst,
	const char *const name,
	t_string *const str)
{
	t_string		tmp;
	size_t			len;

	if (!(extract_value_same_level(&tmp, name, str)))
		return (0);
	*dst = tmp;
	len = 5 + 2 * ft_strlen(name) + tmp.size;
	str->data_ptr += len;
	str->size -= len;
	return (1);
}
