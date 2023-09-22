/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:32:13 by lmahe             #+#    #+#             */
/*   Updated: 2023/09/23 00:23:50 by ae7th            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_left_row(int tab[4])
{
	int	count;
	int	i;
	int	max;

	i = -1;
	max = 0;
	count = 0;
	while (++i < 4)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			count++;
		}
	}
	return (count);
}

int	ft_check_row(int tab[4], int x, int y)
{
	int	left;
	int	right;
	int	max;
	int	i;

	max = 0;
	right = 0;
	left = ft_check_left_row(tab);
	i = 3;
	max = 0;
	while (i > -1)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			right++;
		}
		i--;
	}
	if ((left != x) || (right != y))
		return (0);
	return (1);
}

int	ft_check_up_col(int tab[8][4], int col)
{
	int	count;
	int	i;
	int	max;

	max = 0;
	count = 0;
	i = -1;
	while (++i < 4)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			count++;
		}
	}
	return (count);
}

int	ft_check_col(int tab[8][4], int col, int x, int y)
{
	int	up;
	int	down;
	int	max;
	int	i;

	down = 0;
	i = -1;
	max = 0;
	up = ft_check_up_col(tab, col);
	i = 4;
	max = 0;
	while (--i > -1)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			down++;
		}
	}
	if ((up != x) || (down != y))
		return (0);
	return (1);
}

int	ft_check_sudoku(int tab[8][4], int x)
{
	int	col;
	int	i;

	col = 0;
	i = x - 1;
	if (x == 0)
		return (1);
	while (col < 4)
	{
		while (i >= 0)
		{
			if (tab[i][col] == tab [x][col])
				return (0);
			i--;
		}
		col++;
	}
	return (1);
}
