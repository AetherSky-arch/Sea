/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:31:55 by arguez            #+#    #+#             */
/*   Updated: 2023/09/23 00:46:38 by ae7th            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	original;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	original = nb;
	while (power > 1)
	{
		nb = nb * original;
		power--;
	}
	return (nb);
}
