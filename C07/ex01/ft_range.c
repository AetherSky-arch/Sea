/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:15:01 by arguez            #+#    #+#             */
/*   Updated: 2023/09/12 19:15:11 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*array;
	unsigned int	len;
	int				i;

	if (min >= max)
		return (NULL);
	len = max - min;
	array = (int *)malloc(len * sizeof(int));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (min < max)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}

/*
int	main(int argc, char **argv)
{
	int	*array;
	int	i;
	int	min;
	int	max;

	(void)argv;
	if (argc != 3)
	{
		printf("%s\n", "Error : Invalid number of arguments");
		return (1);
	}
	min = atoi(argv[1]);
	max = atoi(argv[2]);
	array = ft_range(min, max);
	i = max - min;
	while (i < (max - min) * 2)
	{
		printf("%d ", array[i - (max - min)]);
		i++;
	}
	printf("\n");
	return (0);
}*/
