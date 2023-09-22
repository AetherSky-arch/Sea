/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:16:16 by lmahe             #+#    #+#             */
/*   Updated: 2023/09/23 00:22:46 by ae7th            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	ft_error(void)
{
	write(1, "Error", 5);
	write(1, "\n", 1);
}

void	ft_transfer(int tab[8][4], int cond[16])
{
	int	i;
	int	j;
	int	k;

	i = 4;
	j = 0;
	k = 0;
	while (i < 8)
	{
		while (k < 4)
		{
			tab[i][k] = cond[j];
			k++;
			j++;
		}
		k = 0;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	perm[25][4];
	int	board[8][4];
	int	*flag;
	int	k;
	int	cond[16];

	perm[24][0] = 1;
	perm[24][1] = 2;
	perm[24][2] = 3;
	perm[24][3] = 4;
	if (argc != 2 || !ft_atoi_conditions(argv[1], cond))
	{
		ft_error();
		return (0);
	}
	ft_transfer(board, cond);
	k = 0;
	flag = &k;
	ft_combs(perm, perm[24], 4, flag);
	k = 0;
	if (ft_sol(board, 0, perm, flag) == 0)
		ft_error();
	return (0);
}
