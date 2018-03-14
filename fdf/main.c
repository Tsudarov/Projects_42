/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2018/02/14 14:15:13 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void					fdf_couleur(t_env *e)
{
	unsigned long		j;
	const int			seuil[] = {-100000, 1, 50, 100, 150, 100000};

	j = -1;
	while (++j < sizeof(seuil) / sizeof(*seuil))
	{
		if (e->keycode == 71)
			e->col->tab[0] = 0;
		if (e->keycode == 15)
		{
			e->col->innt += 75135;
			if (e->col->tab[3] > 110)
				e->col->tab[3] = 15;
		}
		if (e->keycode == 65)
			e->col->tab[3] += 100;
		fdf_init_random_col(e);
	}
}

void					fdf_drawline_2(t_env *e, t_pos *start, t_pos *end,
		const t_mlx_pic *mp)
{
	fdf_couleur(e);
	mlx_img_drwline(start, end, mp, e->col);
}

void					fdf_drawline(t_env *e)
{
	t_pos				start;
	t_pos				end;
	int					i;
	int					j;
	const t_mlx_pic		mp = (t_mlx_pic){&e->mlx, e->image};

	i = -1;
	while (e->map[++i])
	{
		j = -1;
		while (++j < e->size.sizeline)
		{
			fdf_gdp_init_math(&start, i, j, e);
			if (j + 1 < e->size.sizeline)
			{
				fdf_gdp_init_math(&end, i, j + 1, e);
				fdf_drawline_2(e, &start, &end, &mp);
			}
			if (e->map[i + 1])
			{
				fdf_gdp_init_math(&end, i + 1, j, e);
				fdf_drawline_2(e, &start, &end, &mp);
			}
		}
	}
}

int						main(int argc, char **argv)
{
	t_env				e;

	if (argc != 2)
		ft_exit("wrong argument number !\n");
	if (!(e.map = fdf_read(argv[1], &e.size.sizeline, &e.size.nbline)) ||
			!ft_check_fdf_file(argv[1]) || !fdf_init_env(&e))
		return (0);
	mlx_init_win(&e.mlx, WW_WIDTH_H, WW_HEIGHT_H, "fdf");
	mlx_hook(e.mlx.win, 2, (1L << 0), &fdf_evnt_kbd, &e);
	fdf_init_height(e.map, e.size.sizeline);
	fdf_drawline(&e);
	mlx_put_image_to_window(e.mlx.mlx, e.mlx.win, e.image->image, 0, 0);
	mlx_expose_hook(e.mlx.win, &fdf_event_expose, &e);
	mlx_loop(e.mlx.mlx);
	return (0);
}
