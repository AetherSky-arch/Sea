/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/17 15:08:30 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/19 18:17:41 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "header.h"

char	*hexa_converter(int n, char *res)
{
	char	*base;

	base = (char *) malloc (16 * sizeof(char));
	if ((base == NULL) || (res == NULL))
		return (NULL);
	base = "0123456789abcdef";
	res[0] = '\0';
	if (n != 0)
	{
		hexa_converter(n / 16, res);
		ft_strcat(res, base[n % 16]);
	}
	return (res);
}

void	offset_printer(int *offset)
{
	char	*res;
	int		i;

	res = (char *) malloc (8 * sizeof(char));
	if (res == NULL)
		return ;
	i = 0;
	res = hexa_converter(*offset, res);
	while (i < 8 - ft_strlen(res))
	{
		ft_putstr("0", 1);
		i++;
	}
	ft_putstr(res, 1);
	*offset = *offset + 16;
}

char	*byte_converter(int n, char *res)
{
	char	*base;

	base = (char *) malloc (16 * sizeof(char));
	if ((base == NULL) || (res == NULL))
		return (NULL);
	base = "0123456789abcdef";
	res[1] = base[n % 16];
	n = n / 16;
	res[0] = base[n % 16];
	return (res);
}
