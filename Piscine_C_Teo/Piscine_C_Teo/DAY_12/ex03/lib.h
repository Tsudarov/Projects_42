/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 23:26:44 by tsudarov          #+#    #+#             */
/*   Updated: 2016/05/09 18:51:24 by tsudarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# define BUF_SIZE 1
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef	struct	s_offset
{
	int			offset;
	int			j;
	char		*optionc;
	int			i;
	int			c;
}				t_offset;

t_offset		ft_fct2(t_offset offset, char *buf);
t_offset		ft_fct(t_offset offset, char **argv, int fd, int i);
void			ft_print_c(char *str, int j);
char			*ft_strcat(char *s1, char *s2);
int				ft_strlen(char *str);
void			ft_putstr(char *str);
void			ft_putchar(char c);
void			ft_errmsg(char *argv, int errtyp);
void			ft_dectohex(int num, int k, t_offset offset);
int				ft_hexdump(char **argv, t_offset offset);
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(char *str);
void			ft_putnbr(int nb);

#endif
