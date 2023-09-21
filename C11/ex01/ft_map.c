/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:23:01 by arguez            #+#    #+#             */
/*   Updated: 2023/09/21 10:28:39 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*returned;
	int	i;

	returned = (int *) malloc (length * sizeof(int));
	i = -1;
	while (++i < length)
		returned[i] = f(tab[i]);
	return (returned);
}
