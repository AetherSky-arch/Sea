/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/07 14:22:49 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/20 20:39:05 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if ((nb == 2) || (nb == 3) || (nb == 2147483647))
		return (1);
	if (nb % 2 == 0)
		return (0);
	i = 3;
	while ((nb % i != 0) && (i * i <= nb))
		i += 2;
	if (nb % i == 0)
		return (0);
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (nb % 2 == 0)
		nb++;
	if (ft_is_prime(nb))
		return (nb);
	return (ft_find_next_prime(nb + 2));
}
