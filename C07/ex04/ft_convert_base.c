/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/20 22:17:02 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/23 00:26:14 by ae7th            ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putstr(char *str, int output);
int		ft_atoi_base(char *str, char *base);
int		check_base(char *base);
int		ft_strlen(char *str);

int	count_digit(int nbr, char *base)
{
	int			base_size;
	long int	nb;
	int			count;

	count = 0;
	base_size = ft_strlen(base);
	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb >= base_size)
	{
		nb = nb / base_size;
		count++;
	}
	return (++count);
}

void	ft_convnbr_base(int nbr, char *base, char *ptr, int i)
{
	int			base_size;
	long int	nb;

	base_size = ft_strlen(base);
	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		ptr[0] = '-';
	}
	if (nb >= base_size)
		ft_convnbr_base(nb / base_size, base, ptr, i - 1);
	ptr[i] = base[nb % base_size];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		convert;
	int		count;
	char	*ptr;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	convert = ft_atoi_base(nbr, base_from);
	count = count_digit(convert, base_to) + 1;
	ptr = malloc(sizeof(*nbr) * count);
	ft_convnbr_base(convert, base_to, ptr, count - 2);
	ptr[count - 1] = '\0';
	return (ptr);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		ft_putstr("Error : Expected 3 arguments : \
				[number] [base_from] [base_to]\n", 2);
		return (1);
	}
	ft_putstr(ft_convert_base(argv[1], argv[2], argv[3]), 1);
	ft_putstr("\n", 1);
	return (0);
}
