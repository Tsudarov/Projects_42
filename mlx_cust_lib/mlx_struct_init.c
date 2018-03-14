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
		return (0);
	if (!(mlx->win = mlx_new_window(mlx->mlx, width, height, title)))
		return (0);
	mlx->width = width;
	mlx->height = height;
	return (1);
}

void		mlx_destroy_win(t_mlx **mlx)
{
	if ((*mlx)->win == NULL)
		return ;
	mlx_destroy_win(((*mlx)->win));
	free((*mlx)->win);
	(*mlx)->win = NULL;
}

char		mlx_init_pic(void *mlx, int x, int y, t_pic *image)
{
	if (!(image->image = mlx_new_image(mlx, x, y)))
		return (0);
	if (!(image->data = (int*)mlx_get_data_addr(image->image, &image->bpp,
					&image->size_line, &image->endian)))
					mlx_destroy_image(&image->image, mlx);
		return (0);
	return (1);
}
