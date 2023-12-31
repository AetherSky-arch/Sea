/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/20 21:58:10 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/20 21:58:52 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_char_as_hex(unsigned char c)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	ft_putchar(92);
	ft_putchar(hex_base[c / 16]);
	ft_putchar(hex_base[c % 16]);
}

int	check(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (check(str[i]))
			ft_putchar(str[i]);
		else
			print_char_as_hex(str[i]);
	}
}
