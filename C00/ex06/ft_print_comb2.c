/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:48:16 by arguez            #+#    #+#             */
/*   Updated: 2023/09/04 19:50:12 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_comma(void)
{
	write(1, ", ", 2);
}

void	print(int n1, int n2)
{
	char	c1;
	char	c2;
	char	c3;
	char	c4;

	c1 = n1 / 10 + 48;
	c2 = n1 % 10 + 48;
	c3 = n2 / 10 + 48;
	c4 = n2 % 10 + 48;
	ft_putchar(c1);
	ft_putchar(c2);
	ft_putchar(' ');
	ft_putchar(c3);
	ft_putchar(c4);
}

void	ft_print_comb2(void)
{
	int	i;
	int	y;
	int	printed;

	printed = 0;
	i = 0;
	while (i <= 99)
	{
		y = i + 1;
		while (y <= 99)
		{
			if (printed == 1)
				print_comma();
			else
				(printed = 1);
			print (i, y);
			y++;
		}
		i++;
	}
}
