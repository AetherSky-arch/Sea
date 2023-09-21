/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/19 13:43:31 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/20 17:14:59 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c, int output)
{
	write(output, &c, 1);
}

void	ft_printer_twobytwo(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i++], 1);
		ft_putchar(str[i++], 1);
		ft_putchar(str[i++], 1);
		ft_putchar(str[i++], 1);
		ft_putchar(' ', 1);
	}
}

void	ft_printer_onebyone(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i++], 1);
		ft_putchar(str[i++], 1);
		ft_putchar(' ', 1);
		if (i == 16)
			ft_putchar(' ', 1);
	}
	while (i != 32)
	{
		ft_putchar(' ', 1);
		i++;
	}
}

void	ascii_printer(char *str)
{
	int	i;

	i = 0;
	ft_putchar('|', 1);
	while (str[i] != '\0')
	{
		if ((str[i] >= 9) && (str[i] <= 13))
			ft_putchar('.', 1);
		else
			ft_putchar(str[i], 1);
		i++;
	}
	ft_putchar('|', 1);
}

int	file_len(int file)
{
	int		i;
	char	c;

	i = 0;
	while (read(file, &c, 1))
		i++;
	close(file);
	return (i);
}
