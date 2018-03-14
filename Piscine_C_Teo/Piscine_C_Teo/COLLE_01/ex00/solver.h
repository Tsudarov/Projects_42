/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 14:07:19 by yewen             #+#    #+#             */
/*   Updated: 2015/10/25 14:42:50 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

int		ft_check_row(char *tab[], int i, int j, int n);
int		ft_check_col(char *tab[], int i, int j, int n);
int		ft_check_square(char *tab[], int i, int j, int n);
int		ft_solve(char *tab[], int pos);
int		ft_solve_reverse(char *tab[], int pos);

#endif
