/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   bytes.c                                            :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/18 22:48:32 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/21 16:02:24 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "header.h"

void	ohbabyitsadouble(int file, char *ascii, char *hexa)
{
	int		i;
	char	*twice;
	char	c;
	char	b1;
	char	b2;

	twice = (char *) malloc (2 * sizeof(char));
	if (twice == NULL)
		return ;
	i = 0;
	while (i < 16)
	{
		read(file, &c, 1);
		b1 = c;
		read(file, &c, 1);
		b2 = c;
		ft_strcat(ascii, b1);
		ft_strcat(ascii, b2);
		ft_catstr(hexa, byte_converter(b1, twice));
		ft_catstr(hexa, byte_converter(b2, twice));
		i += 2;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
}

int	file_catter(int argc, char **argv, int is_option)
{
	int	i;
	int	final;
	int	file;
	char	c;

	i = 0;
	final = open("big", O_RDWR, O_TRUNC);
	while (i + 1 + is_option < argc)
	{
		file = open(argv[i + is_option + 1], O_RDONLY, 777);
		while (read(file, &c, 1))
			write(final, &c, 1);
		close(file);
		i++;
	}
	return (final);
}
