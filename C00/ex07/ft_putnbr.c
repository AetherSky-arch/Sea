/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:52:55 by arguez            #+#    #+#             */
/*   Updated: 2023/09/07 20:44:21 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	new;

	if (nb < 0)
	{
		ft_putchar('-');
		new = -nb;
	}
	else
		new = nb;
	if (new >= 10)
	{
		ft_putnbr(new / 10);
		ft_putnbr(new % 10);
	}
	else
	{
		ft_putchar(new + '0');
	}
}

int	main(void)
{
	ft_putnbr(INT_MAX);
	return (0);
}
