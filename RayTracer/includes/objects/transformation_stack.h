/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_stack.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:26:26 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 06:43:57 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATION_STACK_H
# define TRANSFORMATION_STACK_H

# include "vector.h"

struct s_object;
struct s_string;

typedef enum						e_transformation_type
{
	TRANSFORMATION_TYPE_TRANSLATE = 0,
	TRANSFORMATION_TYPE_ROTATE_X,
	TRANSFORMATION_TYPE_ROTATE_Y,
	TRANSFORMATION_TYPE_ROTATE_Z
}									t_transformation_type;

typedef union						u_transformation_args
{
	t_vector						translate;
	float							rotate;
}									t_transformation_args;

typedef struct						s_transformation_stack
{
	t_transformation_type			type;
	struct s_transformation_stack	*next;
	t_transformation_args			args;
}									t_transformation_stack;

void								transformation_stack_apply(
	t_transformation_stack *const stack,
	struct s_object *const object);
char								generate_transformation_stack(
	t_transformation_stack *const stack,
	const struct s_string *const string);
void								delete_transformation_stack(
	t_transformation_stack *const stack);
void								transformation_stack_apply(
	t_transformation_stack *const stack,
	t_object *const target);

#endif
