/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/20 21:52:07 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/20 21:52:21 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

unsigned int	strlength(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size)
	{
		i = 0;
		while (i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		while (i < size)
			dest[i++] = '\0';
	}
	return (strlength(src));
}
