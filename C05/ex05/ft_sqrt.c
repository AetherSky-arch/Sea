/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:49:59 by arguez            #+#    #+#             */
/*   Updated: 2023/09/09 21:39:45 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt;

	if (nb < 1)
		return (0);
	if (nb == 1)
		return (1);
	if ((nb == 2) || (nb == 3))
		return (0);
	if (nb == 4)
		return (2);
	sqrt = 3;
	while ((sqrt * sqrt != nb) && (sqrt <= nb / 3) && (sqrt <= 46340))
		sqrt++;
	if (sqrt * sqrt == nb)
		return (sqrt);
	return (0);
}
