/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:33:31 by tsudarov          #+#    #+#             */
/*   Updated: 2017/12/27 15:25:38 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WW_WIDTH_H 1900
# define WW_HEIGHT_H 1200
# define BUFFER_SIZE 512

# include "libft.h"
# include "mlx_cust.h"
# include <fcntl.h>
# include <math.h>

typedef struct		s_read
{
	ssize_t			len;
	char			line[BUFFER_SIZE];
	struct s_read	*next;
}					t_read;

typedef struct		s_size
{
	int				nbline;
	int				sizeline;
}					t_size;

typedef struct		s_fact
{
	double				x;
	double				y;
}					t_fact;

typedef struct		s_env
{
	t_pic			*image;
	t_mlx			mlx;
	t_size			size;
	t_fact			fact;
	t_col			*col;
	int				**map;
	int				zoom;
	int				keycode;
}					t_env;

int					ft_check_fdf_file(char *line);
int					fdf_evnt_kbd(int keycode, t_env *e);
int					fdf_event_mouse(int button, int x, int y);
int					fdf_event_expose(t_env *e);
void				mlx_help_display(t_env *e);
int					**fdf_read(char *argv, int *nblineptr, int *nbbsn);
int					**ft_error(int k);
int					ft_exit(char *str);
void				destroy_list(t_read *list);
void				fdf_drawline(t_env *e);
int					fdf_init_random_col(t_env *e);
int					fdf_init_env(t_env *e);
int					fdf_init_height(int **map, int sizeline);
int					fdf_gdp_init_math(t_pos *start, int i, int j, t_env *e);

#endif
