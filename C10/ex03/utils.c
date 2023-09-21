/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/19 10:11:40 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/19 13:35:31 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "header.h"

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

void	ft_strcat(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	str[i] = c;
	i++;
	str[i] = '\0';
}

void	ft_catstr(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
		j++;
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_puterror(int errno)
{
	if (errno == 0)
		ft_putstr("Error: Can't open file", 2);
}
