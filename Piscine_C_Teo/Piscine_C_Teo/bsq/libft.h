/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <mulzega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:46:58 by mulzega           #+#    #+#             */
/*   Updated: 2016/05/27 13:24:34 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_swap(int *a, int *b);
char	*ft_strdup(char *src);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, int nb);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strstr(const char *str, const char *to_find);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
char	**ft_split_backslash(char *str);
int		ft_count_words(char *str);
int		ft_ln_w(char *str, int i);


#endif
