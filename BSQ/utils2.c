/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/26 22:45:25 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/27 13:50:14 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c, int output)
{
	write(output, &c, 1);
}

void	freeer(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	checknextline(char **tab, struct s_point offset, struct s_point square)
{
	if (tab[offset.y][offset.x] == '\n')
	{
		offset.x = offset.x - square.x;
		square.x = 0;
		offset.y++;
		square.y++;
	}
}

void	map_filler(struct s_point *res, char **tab, char obstacle)
{
	int	i;
	int	j;

	j = res[0].y;
	while (j <= res[1].y)
	{
		i = res[0].x;
		while (i <= res[1].x)
		{
			tab[j][i] = obstacle;
			i++;
		}
		j++;
	}
	free(res);
}

void	printer(char **tab, int numof_lines)
{
	int	i;
	int	j;
	int	llen;

	llen = ft_strlen(tab[0]);
	j = 0;
	while (j <= numof_lines)
	{
		i = 0;
		while (i <= llen)
		{
			ft_putchar(tab[j][i], 1);
			i++;
		}
		j++;
	}
}
