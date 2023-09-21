/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:46:02 by arguez            #+#    #+#             */
/*   Updated: 2023/09/04 19:46:20 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	comma_space(int j, int k)
{
	if ((j + '0' != 1) && (k + '0' != '2'))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				comma_space(j, k);
				ft_putchar(i + 48);
				ft_putchar(j + 48);
				ft_putchar(k + 48);
				k = k + 1;
			}
			j = j + 1;
		}
		i = i + 1;
	}
}
