/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/21 15:06:40 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/21 15:10:09 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		find;
	char	*tmp;

	find = 1;
	while (find != 0)
	{
		find = 0;
		i = 0;
		while (tab[i + 1] != 0)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				find = 1;
			}
			i++;
		}
	}	
}
