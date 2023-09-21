/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/07 17:30:51 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/07 17:32:33 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	n;

	n = argc - 1;
	while (n >= 1)
	{
		ft_putstr(argv[n]);
		ft_putchar('\n');
		n--;
	}
	return (0);
}
