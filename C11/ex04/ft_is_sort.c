/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/21 10:47:51 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/21 17:33:13 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	order;

	i = 0;
	order = 0;
	while ((i + 1) < length)
	{
		if (f(tab[i], tab[i + 1]) < 0)
		{
			if (order == 0)
				order = -1;
			else if (order == 1)
				return (0);
		}
		if (f(tab[i], tab[i + 1]) > 0)
		{
			if (order == 0)
				order = 1;
			else if (order == -1)
				return (0);
		}
		i++;
	}
	return (1);
}
