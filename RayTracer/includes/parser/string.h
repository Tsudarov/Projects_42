/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 23:28:51 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/22 15:47:13 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stddef.h>

typedef struct		s_string
{
	const char		*data_ptr;
	size_t			size;
}					t_string;

typedef struct		s_inner_while_args
{
	t_string		*dst;
	t_string		*var_name;
	const t_string	*str;
	t_string		*current_tag;
	unsigned int	*occs;
	const char		*name;
	size_t			counter;
}					t_inner_while_args;

char				extract_value(
	t_string *const dst,
	const char *const name,
	const t_string *const str);
char				extract_value_loop(
	t_string *const dst,
	const char *const name,
	t_string *const str);
char				extract_value_same_level(
	t_string *const dst,
	const char *const name,
	const t_string *const str);
unsigned char		ft_atoi(
	const char *const line_ptr,
	const char **const end_ptr,
	const size_t max_len);
unsigned int		ft_atoi_string(
	const t_string *const string);
void				ft_bzero(
	void *const area,
	const size_t len);
int					get_first_of(
	t_string *const str,
	const char *const *const refs,
	t_string *const value);
size_t				ft_strlen(
	const char *const str);
char				ft_string_equal(
	const t_string *const str,
	const char *const name,
	const char flag);
char				ft_string_equal_string(
	const t_string *const str,
	const t_string *const name,
	const char flag);
char				extract_text_between_tag(
	t_string *const dst,
	const char *const line,
	const size_t max_len);

#endif
