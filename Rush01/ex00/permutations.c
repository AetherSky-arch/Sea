/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:59:09 by arguez            #+#    #+#             */
/*   Updated: 2023/09/17 11:29:04 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swapper(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_phillcollins(int final[24][4], int *tab, int *index)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		final[*index][i] = tab[i];
		i++;
	}
	*index += 1;
}

int	ft_combs(int final[24][4], int *tab, int size, int *index)
{
	int	i;

	if (size == 1)
	{
		ft_phillcollins(final, tab, index);
	}
	i = 0;
	while (i < size)
	{
		ft_combs(final, tab, size - 1, index);
		if (size % 2 == 1)
			swapper(&tab[0], &tab[size - 1]);
		if (size % 2 == 0)
			swapper(&tab[i], &tab[size - 1]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*ptr;
	int	n;
	int	final[24][4] = {{0}};
	int	i;
	int	j;

	n = 0;
	ptr = &n;
	ft_combs(final, 4, ptr);
	i = 0;
	j = 0;

	while(i < 24)
	{
		while (j < 4)
		{
			printf("%d ", final[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;

	}
	
} 
*/
