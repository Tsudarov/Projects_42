/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:58:46 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/12 15:47:28 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "string.h"

void				ft_bzero(void *const area, const size_t len)
{
	long	*ptr;
	char	*cptr;
	size_t	counter;

	ptr = area;
	counter = len / sizeof(*ptr);
	while (counter--)
		*(ptr++) = 0;
	cptr = (char*)ptr;
	counter = len % sizeof(*ptr);
	while (counter--)
		*(cptr++) = 0;
}

unsigned char		ft_atoi(const char *const line_ptr,
							const char **const end_ptr,
							const size_t max_len)
{
	unsigned int	result;
	size_t			counter;

	counter = -1;
	while (++counter < max_len
		&& (line_ptr[counter] < '0' || line_ptr[counter] > '9'))
		;
	if (counter == max_len)
	{
		*end_ptr = line_ptr + counter;
		return (0);
	}
	result = 0;
	counter--;
	while (++counter < max_len
		&& line_ptr[counter] >= '0' && line_ptr[counter] <= '9')
	{
		result *= 10;
		result += line_ptr[counter] - '0';
	}
	*end_ptr = line_ptr + counter;
	return (result);
}

unsigned int		ft_atoi_string(const t_string *const string)
{
	unsigned int	result;
	size_t			counter;

	counter = -1;
	while (++counter < string->size
		&& (string->data_ptr[counter] < '0' || string->data_ptr[counter] > '9'))
		;
	if (counter == string->size)
		return (0);
	result = 0;
	counter--;
	while (++counter < string->size
		&& string->data_ptr[counter] >= '0' && string->data_ptr[counter] <= '9')
	{
		result *= 10;
		result += string->data_ptr[counter] - '0';
	}
	return (result);
}
