/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 17:24:33 by yewen             #+#    #+#             */
/*   Updated: 2015/10/18 22:05:06 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TOP_LEFT		'o'
#define TOP_RIGHT		'o'
#define BOTTOM_LEFT		'o'
#define BOTTOM_RIGHT	'o'
#define HOR_BORDER		'-'
#define VER_BORDER		'|'

int		ft_putchar(int c);

int		build_first_line(int *line, int width)
{
	int		i;

	i = 0;
	while (i < width)
	{
		if (i == 0)
			line[i++] = TOP_LEFT;
		else if (i == width - 1)
			line[i++] = TOP_RIGHT;
		else
			line[i++] = HOR_BORDER;
	}
	return (0);
}

int		build_last_line(int *line, int width)
{
	int		i;

	i = 0;
	while (i < width)
	{
		if (i == 0)
			line[i++] = BOTTOM_LEFT;
		else if (i == width - 1)
			line[i++] = BOTTOM_RIGHT;
		else
			line[i++] = HOR_BORDER;
	}
	return (0);
}

int		build_normal_line(int *line, int width)
{
	int		i;

	i = 0;
	while (i < width)
	{
		if (i == 0 || i == width - 1)
			line[i++] = VER_BORDER;
		else
			line[i++] = ' ';
	}
	return (0);
}

int		print_line(int *line, int width)
{
	int		i;

	i = 0;
	while (i < width)
		ft_putchar(line[i++]);
	ft_putchar('\n');
	return (0);
}

int		colle(int width, int height)
{
	int		line[width];
	int		i;

	i = 0;
	while (i < height)
	{
		if (i == 0)
			build_first_line(line, width);
		else if (i == height - 1)
			build_last_line(line, width);
		else
			build_normal_line(line, width);
		print_line(line, width);
		i++;
	}
	return (0);
}
