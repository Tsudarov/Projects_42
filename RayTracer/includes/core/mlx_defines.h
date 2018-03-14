/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_defines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 06:26:41 by tsudarov          #+#    #+#             */
/*   Updated: 2018/02/27 19:36:57 by cgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DEFINES_H
# define MLX_DEFINES_H

struct mlx_ptr_s;
struct mlx_win_list_s;
struct mlx_img_list_s;

struct mlx_ptr_s		*mlx_init();
struct mlx_win_list_s	*mlx_new_window(
	struct mlx_ptr_s *a,
	int b,
	int c,
	const char *const d);
int						*mlx_get_data_addr(
	struct mlx_img_list_s *a,
	int *b,
	int *c,
	int *d);
void					mlx_put_image_to_window();
void					mlx_destroy_window(
	struct mlx_ptr_s *a,
	struct mlx_win_list_s *b);
int						mlx_key_hook(
	void *win_ptr,
	int (*funct_ptr)(),
	void *param);
void					mlx_clear_window(
	struct mlx_ptr_s *ptr,
	struct mlx_win_list_s *win);
void					mlx_string_put(
	struct mlx_ptr_s *ptr,
	struct mlx_win_list_s *win,
	int x,
	int y,
	int color,
	unsigned char *str);

#endif
