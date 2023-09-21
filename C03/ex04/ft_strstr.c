/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/20 22:06:53 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/20 22:08:17 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

char	*find(char *str, char *to_find)
{
	int		i;
	int		i2;
	int		j;
	char	*ptr;

	i = -1;
	while (str[++i])
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			i2 = i;
			while (str[i2] == to_find[j] && to_find[j] && str[i2])
			{
				i2++;
				j++;
			}
			if (!to_find[j])
			{
				ptr = str + i;
				return (ptr);
			}
		}
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (!to_find[0])
		return (str);
	return (find(str, to_find));
}
