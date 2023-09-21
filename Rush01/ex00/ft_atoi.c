/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:18:39 by lmahe             #+#    #+#             */
/*   Updated: 2023/09/17 12:35:17 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '1') || (str[i] > '4'))
			return (0);
		i++;
		if ((str[i] != ' ') && (str[i] != '\0'))
			return (0);
		if (str[i] != '\0')
			i++;
	}
	return (1);
}

int	ft_atoi_conditions(char *str, int tab[16])
{
	int	i;
	int	j;

	if (ft_strlen(str) != 31)
		return (0);
	if (check_str(str) == 0)
		return (0);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		tab[j] = str[i] - '0';
		j++;
		i += 2;
	}
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	char	tab0[] = "1 4 2 3 3 2 4 1 2 3 1 4 2 3 1 4";
//	char	tab1[] = "1 5 4 2 3 2 1 4 2 3 1 4 2 2 1 4";
//	char	tab2[] = "2 1 4 2 3 2 1 4 2 3 1 4";
//	char	tab3[] = "21 5 2 4 1 3 4 7 1 4 2 3 2 1 4 2";
	int	tab[16];

	//printf("%d\n%d\n",ft_atoi_conditions(tab0, tab),
 ft_atoi_conditions(tab1,tab));
	//printf("%d\n%d\n", ft_atoi_conditions(tab2,tab),
 ft_atoi_conditions(tab3,tab));
	int x = ft_atoi_conditions(tab0, tab);
	if (x == 0)
		return (1);
	int	i;
	for ( i = 0; i < 16; i++)
		printf("%d ,", tab[i]);
	return (0);
}*/
