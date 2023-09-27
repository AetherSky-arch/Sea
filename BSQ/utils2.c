/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:45:25 by arguez            #+#    #+#             */
/*   Updated: 2023/09/26 22:47:07 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	freeer(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}
