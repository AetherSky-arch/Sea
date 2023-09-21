/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/07 10:41:17 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/09 16:15:41 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_len;
	unsigned int	i;

	dest_len = 0;
	while (dest[dest_len])
		dest_len++;
	i = 0;
	while ((i < nb) && (src[i] != '\0'))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
