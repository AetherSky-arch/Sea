/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:22:55 by lmoran            #+#    #+#             */
/*   Updated: 2023/09/27 22:24:13 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	count_digits(int n)
{
	int	counter;

	if (n == 0)
		return (1);
	counter = 0;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

void	reader(void)
{
	int		file;
	char	c;

	file = open("tmp", O_RDWR | O_TRUNC);
	if (file == -1)
	{
		printf("%d, map error\n", file);
		return ;
	}
	while (read(0, &c, 1))
		write(file, &c, 1);
	parser("tmp", file);
}
