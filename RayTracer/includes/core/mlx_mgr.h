/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mgr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:45:00 by cgerbaud          #+#    #+#             */
/*   Updated: 2018/02/14 06:53:20 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MGR_H
# define MLX_MGR_H

struct s_color;
struct mlx_ptr_s;
struct mlx_win_list_s;
struct mlx_img_list_s;

typedef struct				s_mlx_datas
{
	struct mlx_ptr_s		*mlx;
	struct mlx_win_list_s	*win;
}							t_mlx_datas;

typedef struct				s_img_datas
{
	struct mlx_img_list_s	*img;
	int						*data;
	int						bpp;
	int						size_line;
	int						endian;
}							t_img_datas;

typedef struct				s_mlx_mgr
{
	t_mlx_datas				mlx_datas;
	t_img_datas				img_datas;
}							t_mlx_mgr;

char						mlx_mgr_new_window(t_mlx_mgr *const mlx_datas,
											const unsigned int width,
											const unsigned int height);
void						mlx_close_window(t_mlx_mgr *const mlx_mgr);
char						init_mlx_mgr(t_mlx_mgr *const mlx_mgr,
										const unsigned int width,
										const unsigned int height);
char						init_img_datas(t_img_datas *const img_datas,
										struct mlx_ptr_s *const mlx_ptr,
										const unsigned int width,
										const unsigned int height);
void						destroy_mlx_mgr(t_mlx_mgr *const mlx_mgr);
void						set_pixel_value(t_mlx_mgr *const mlx_mgr,
										const unsigned int xy[2],
										const struct s_color *const pixel_value,
										const double max);
void						print(t_mlx_mgr *const mlx_mgr,
								t_img_datas *const img_datas);

#endif
