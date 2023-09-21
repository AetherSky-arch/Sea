/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/17 12:14:56 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/17 12:16:58 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

int	ft_check_row(int tab[4], int x, int y);
int	ft_check_col(int tab[4][4], int col, int x, int y);
int	ft_check_sudoku(int tab[4][4], int x);
int	ft_combs(int final[24][4], int *tab, int size, int *index);
int	ft_atoi_conditions(char *str, int tab[16]);
int	ft_sol(int tab[8][4], int x, int perm[24][4], int *flag);

#endif
