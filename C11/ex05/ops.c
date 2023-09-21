/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:29:57 by arguez            #+#    #+#             */
/*   Updated: 2023/09/21 17:40:28 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	div(int val1, int val2)
{
	if (val2 == 0)
	{
		ft_putstr("Stop : division by zero", 1);
		return ;
	}
	val1 = val1 / val2;
	ft_putnbr(val1);
}

void	mod(int val1, int val2)
{
	if (val2 == 0)
	{
		ft_putstr("Stop : modulo by zero", 1);
		return ;
	}
	val1 = val1 % val2;
	ft_putnbr(val1);
}

void	add(int val1, int val2)
{
	val1 = val1 + val2;
	ft_putnbr(val1);
}

void	sub(int val1, int val2)
{
	val1 = val1 - val2;
	ft_putnbr(val1);
}

void	mult(int val1, int val2)
{
	val1 = val1 * val2;
	ft_putnbr(val1);
}
