/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exctract_value_same_level.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:37:47 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 16:57:28 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static char	is_string_equals(
	const size_t counter,
	const t_string *const str,
	t_string *const vars[2],
	const char *const name)
{
	if (str->data_ptr[counter] != '<' ||
		!(extract_text_between_tag(
			vars[0], &str->data_ptr[counter], str->size - counter)))
		return (0);
	if (vars[1]->data_ptr)
	{
		if (str->data_ptr[counter + 1] != '/'
			|| !ft_string_equal_string(vars[0], vars[1], 1))
			return (0);
		*vars[1] = (t_string){0, 0};
	}
	if (!ft_string_equal(vars[0], name, 0))
	{
		if (str->data_ptr[counter + 1] == '/')
			return (0);
		*vars[1] = *vars[0];
		return (0);
	}
	return (1);
}

static char	check_occ(
	t_string *const dst,
	t_string *const current_tag,
	const t_string *const var_name,
	unsigned int *const occs)
{
	if (ft_string_equal_string(var_name, current_tag, 0))
	{
		++(*occs);
		return (0);
	}
	if (dst->data_ptr[dst->size + 1] != '/' ||
		!ft_string_equal_string(var_name, current_tag, 1))
		return (0);
	if (*occs)
	{
		--(*occs);
		return (0);
	}
	*current_tag = (t_string){0, 0};
	return (1);
}

static char	inner_while(
	const t_inner_while_args args)
{
	if (args.dst->data_ptr[args.dst->size] != '<')
		return (0);
	if (!(extract_text_between_tag(
			args.var_name,
			&args.dst->data_ptr[args.dst->size],
			args.str->size - (args.counter + args.dst->size))))
		return (0);
	if (args.current_tag->data_ptr)
		if (!(check_occ(args.dst, args.current_tag, args.var_name, args.occs)))
			return (0);
	if (!ft_string_equal(args.var_name, args.name, 1))
	{
		if (args.dst->data_ptr[args.dst->size + 1] == '/')
			return (0);
		*args.current_tag = *args.var_name;
		return (0);
	}
	if (args.dst->data_ptr[args.dst->size + 1] != '/')
		return (0);
	return (1);
}

char		extract_value_same_level(
	t_string *const dst,
	const char *const name,
	const t_string *const str)
{
	t_string		current_tag;
	t_string		var_name;
	size_t			counter;
	unsigned int	occs;

	counter = -1;
	current_tag = (t_string){0, 0};
	while (++counter < str->size)
	{
		if (!(is_string_equals(counter, str,
			(t_string *const[2]){&var_name, &current_tag}, name)))
			continue ;
		dst->data_ptr = str->data_ptr + counter + 2 + var_name.size;
		dst->size = -1;
		occs = 0;
		while (counter + ++(dst->size) < str->size)
			if ((inner_while((t_inner_while_args)
				{dst, &var_name, str, &current_tag, &occs, name, counter})))
				return (1);
	}
	return (0);
}
