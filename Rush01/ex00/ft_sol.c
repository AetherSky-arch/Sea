/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:02:39 by lmahe             #+#    #+#             */
/*   Updated: 2023/09/17 12:35:27 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	ft_print(int board[8][4])
{	
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			c = board[i][j] + '0';
			write (1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		j = 0;
		i++;
		if (i != 4)
			write(1, "\n", 1);
	}
}

int	ft_put_line(int tab[8][4], int x)
{
	int	i;
	int	j;

	i = tab[6][x];
	j = tab[7][x];
	if (ft_check_row(tab[x], i, j) == 0)
		return (0);
	if (ft_check_sudoku(tab, x) == 0)
		return (0);
	return (1);
}

void	ft_put_perm_line( int tab[8][4], int x, int perm[24][4], int n)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tab[x][i] = perm[n][i];
		i++;
	}
}	

int	ft_sol(int tab[8][4], int x, int perm[24][4], int *flag)
{
	int	n;
	int	j;

	n = 0;
	j = 0;
	if (x == 4 && *flag == 0)
	{
		while (j < 4)
		{
			if (ft_check_col(tab, j, tab[4][j], tab[5][j]) == 0)
				return (0);
			j++;
		}
		*flag = 1;
		ft_print(tab);
		return (*flag);
	}
	while (n < 23 && *flag == 0)
	{
		ft_put_perm_line(tab, x, perm, n);
		if (ft_put_line(tab, x))
			ft_sol(tab, x + 1, perm, flag);
		n++;
	}
	return (*flag);
}
