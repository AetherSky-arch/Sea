/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:45:11 by arguez            #+#    #+#             */
/*   Updated: 2023/09/26 20:35:24 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_digit(char c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (((*str >= 9) && (*str <= 13)) || (*str == 32))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (sign * res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_point	initializer(int x, int y)
{
	struct s_point	square;

	square.x = x;
	square.y = y;
	square.original_x = x;
	square.original_y = y;
	return (square);
}

void	filler(char **tab, char *path)
{
	int	file;
	int	i;
	int	j;
	char	c;

	c = 0;
	i = 0;
	j = 0;
	file = open(path, O_RDONLY);
	while (c != '\n')
		read(file, &c, 1);
	while (read(file, &c, 1))
	{
		tab[j][i] = c;
		if (c == '\n')
		{
			i = 0;
			j++;
		}
		else
			i++;
	}
}
