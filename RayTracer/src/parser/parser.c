/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 22:30:22 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 15:44:31 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

size_t	ft_strlen(
	const char *const str)
{
	size_t	counter;

	counter = -1;
	while (str[++counter])
		;
	return (counter);
}

char	ft_string_equal(
	const t_string *const str,
	const char *const name,
	const char flag)
{
	size_t	counter;

	if (ft_strlen(name) != str->size - flag)
		return (0);
	counter = -1;
	while (++counter < str->size
		&& str->data_ptr[counter + flag] == name[counter])
		;
	return (counter == str->size - flag);
}

char	ft_string_equal_string(
	const t_string *const str,
	const t_string *const name,
	const char flag)
{
	size_t	counter;

	if (name->size != str->size - flag)
		return (0);
	counter = -1;
	while (++counter < str->size && str->data_ptr[counter + flag]
		== name->data_ptr[counter])
		;
	return (counter == str->size);
}

char	extract_text_between_tag(
	t_string *const dst,
	const char *const line,
	const size_t max_len)
{
	dst->data_ptr = line + 1;
	dst->size = -1;
	while (++dst->size < max_len && dst->data_ptr[dst->size] != '>')
		;
	return (dst->data_ptr[dst->size] == '>');
}

int		get_first_of(
	t_string *const str,
	const char *const *const refs,
	t_string *const value)
{
	t_string		current;
	t_string		tmp;
	unsigned int	counter;
	unsigned int	rem;

	current = (t_string){0, 0};
	counter = -1;
	while (refs[++counter])
		if (extract_value_same_level(&tmp, refs[counter], str))
		{
			if (!current.data_ptr || tmp.data_ptr < current.data_ptr)
			{
				current = tmp;
				rem = counter;
			}
		}
	if (current.data_ptr)
	{
		str->size -= current.size + current.data_ptr - str->data_ptr;
		str->data_ptr = current.data_ptr + current.size;
		*value = current;
		return (rem + 1);
	}
	return (0);
}
