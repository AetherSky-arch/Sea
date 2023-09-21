/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:19:37 by arguez            #+#    #+#             */
/*   Updated: 2023/09/09 17:29:23 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	original;

	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	original = nb - 1;
	while (original > 1)
	{
		nb = nb * original;
		original--;
	}
	return (nb);
}
