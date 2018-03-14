/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:22:53 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 06:36:58 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "object_wrapper.h"
#include "string.h"
#include "transformation_stack.h"
#include "object.h"

const char	*const g_ref_strings[] =
{
	"Coords",
	"RotateX",
	"RotateY",
	"RotateZ",
	0
};

char	transformation_stack_add(t_transformation_stack *const stack,
								const t_transformation_type type,
								const t_transformation_args *const args)
{
	if (stack->type)
	{
		if (!(stack->next))
		{
			if (!(stack->next = malloc(sizeof(*stack->next))))
				return (0);
			ft_bzero(stack->next, sizeof(*stack->next));
		}
		return (transformation_stack_add(stack->next, type, args));
	}
	stack->type = type;
	stack->args = *args;
	return (1);
}

char	generate_transformation_stack(t_transformation_stack *const stack,
									const t_string *const string)
{
	unsigned int			value;
	t_string				copy;
	t_string				str_args;
	t_transformation_args	args;
	char					found;

	found = 0;
	copy = *string;
	while ((value = get_first_of(&copy, g_ref_strings, &str_args)))
	{
		found = 1;
		if (value == TRANSFORMATION_TYPE_TRANSLATE + 1)
		{
			if (!init_vector(&args.translate, &str_args))
				return (0);
		}
		else
			args.rotate = atof(str_args.data_ptr);
		if (!(transformation_stack_add(stack, value, &args)))
			return (0);
	}
	return (found);
}

void	delete_transformation_stack(t_transformation_stack *const stack)
{
	if (!stack)
		return ;
	if (stack->next)
		delete_transformation_stack(stack->next);
	free(stack);
}
