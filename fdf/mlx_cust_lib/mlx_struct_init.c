/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_struct_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2017/10/07 18:47:16 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_cust.h"

int			mlx_init_win(t_mlx *mlx, int width, int height, char *title)
{
	if (!(mlx->mlx = mlx_init()))
	{
		free(mlx->mlx);
		return (0);
	}
	if (!(mlx->win = mlx_new_window(mlx->mlx, width, height, title)))
	{
		free(mlx->win);
		return (0);
	}
	mlx->width = width;
	mlx->height = height;
	return (0);
}

void		mlx_destroy_win(t_mlx **mlx)
{
	if ((*mlx)->win == NULL)
		return ;
	mlx_destroy_win(((*mlx)->win));
	free((*mlx)->win);
	(*mlx)->win = NULL;
}

t_pic		*mlx_init_pic(void *mlx, int x, int y)
{
	t_pic *image;

	if (!(image = malloc(sizeof(*image))))
		return (NULL);
	if (!(image->image = mlx_new_image(mlx, x, y)))
	{
		free(image);
		return (NULL);
	}
	image->data = malloc(sizeof(*image->data) * 1900 * 1200);
	if (!(image->data = (int*)mlx_get_data_addr(image->image, &image->bpp,
					&image->size_line, &image->endian)))
	{
		free(image);
		return (NULL);
	}
	return (image);
}

void		mlx_destroy_pic(t_pic **pic, void *mlx)
{
	if (*pic == NULL)
		return ;
	mlx_destroy_image(mlx, (*pic)->image);
	free(*pic);
	*pic = NULL;
}
