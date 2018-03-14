/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 15:26:10 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdf_event_gdp(char *str, t_env *e, int code)
{
		ft_bzero(e->image->data, WW_WIDTH_H * WW_HEIGHT_H * e->image->bpp / 8);
	if (code == 1)
		if (e->zoom < 70)
			e->zoom += 5;
	if (code == 2)
		if (e->zoom > 10)
			e->zoom -= 5;
		fdf_drawline(e);
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->image->image, 0, 0);
		mlx_help_display(e);
	ft_putstr(str);
	return (0);
}

int			fdf_evnt_kbd(int keycode, t_env *e)
{
	e->keycode = keycode;
	if (e->keycode == 53)
		ft_exit("What a clean ");
	else if (e->keycode == 75)
		fdf_event_gdp("Horizontal trip\n", e, 0);
	else if (e->keycode == 67)
		fdf_event_gdp("Vertical trip\n", e, 0);
	else if (e->keycode == 71)
		fdf_event_gdp("Refresh\n", e, 0);
	else if (e->keycode == 15)
		fdf_event_gdp("Random\n", e, 0);
	else if (e->keycode == 69)
		fdf_event_gdp("Zooming in\n", e, 1);
	else if (e->keycode == 78)
		fdf_event_gdp("Zooming out\n", e, 2);
	return (0);
}

void		mlx_help_display(t_env *e)
{
	mlx_string_put(e->mlx.mlx, e->mlx.win, 95, 1040, 0x99FF88,
			"HELP");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 40, 1060, 0x0000FF,
			"ESC : exit");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 40, 1080, 0x0000FF,
			"R : Random");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 40, 1100, 0x0000FF,
			"clear : refresh");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 40, 1120, 0x0000FF,
			"+/- : Zoom in/out");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 40, 1140, 0x0000FF,
			"*-/ : trip threw the 4th dimension");
}
