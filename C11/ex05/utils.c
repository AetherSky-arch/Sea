/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/21 12:25:46 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/21 17:40:37 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

void	ft_putchar(char c, int output)
{
	write(output, &c, 1);
}

void	ft_putstr(char *str, int output)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(output, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int	new;

	if (nb < 0)
	{
		ft_putchar('-', 1);
		new = -nb;
	}
	else
		new = nb;
	if (new < 10)
	{
		ft_putchar(new + '0', 1);
		return ;
	}
	ft_putnbr(new / 10);
	ft_putnbr(new % 10);
}
