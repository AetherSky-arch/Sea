/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:44:42 by arguez            #+#    #+#             */
/*   Updated: 2023/09/12 21:54:16 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_chars(char **strs, int size)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

char	*concaten(int size, char **strs, char *sep, char *str_join)
{
	int	j;
	int	i;
	int	k;

	i = -1;
	k = -1;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			str_join[++k] = strs[i][j];
		if (i < (size - 1))
		{
			j = -1;
			while (sep[++j])
				str_join[++k] = sep[j];
		}
	}
	return (str_join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		chars;
	char	*str_join;

	if (size == 0)
	{
		str_join = malloc(sizeof(*str_join));
		str_join[0] = '\0';
		return (str_join);
	}
	chars = count_chars(strs, size) + ((size - 1) * ft_strlen(sep)) + 1;
	str_join = (char *) malloc (sizeof(**strs) * chars);
	str_join = concaten(size, strs, sep, str_join);
	str_join[chars - 1] = '\0';
	return (str_join);
}
