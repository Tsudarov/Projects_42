/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:46:48 by gnebie            #+#    #+#             */
/*   Updated: 2017/12/27 14:54:54 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 20
# define TTX1 tetra->point[0]
# define TTX2 tetra->point[2]
# define TTX3 tetra->point[4]
# define TTX4 tetra->point[6]
# define TTY1 tetra->point[1]
# define TTY2 tetra->point[3]
# define TTY3 tetra->point[5]
# define TTY4 tetra->point[7]
# define TPX tetra->position[0]
# define TPY tetra->position[1]

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_tetra
{
	char				name;
	unsigned char		point[9];
	struct s_tetra		*parent;
	char				position[3];
	struct s_tetra		*next;
}					t_tetra;

int					ft_reco_1_12(t_tetra *tmp);
int					ft_reco_12_19(t_tetra *tmp);
int					fillit_r_carre(int i);
int					fillit_test(char *chaine);
int					fillit_tetra(char *string);
char				**fillit_tableau(int i, int plus, char **oldtab);
void				fillit_print(char **tab, t_tetra *tetra);
int					fillit_backtracking_start(t_tetra *begin_tetra,
		int nbr_tetra);
int					fillit_pgpx(t_tetra *tetra);
int					fillit_pgpy(t_tetra *tetra);
int					ft_uniquetest(t_tetra *tetra);

#endif
