/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/09 12:17:54 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/09 17:37:25 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);

void	line(int len)
{
	int	i;

	i = 0;
	ft_putchar('A');
	while (i < len - 2)
	{
		ft_putchar('B');
		i++;
	}
	ft_putchar('C');
	ft_putchar('\n');
}

void	body(int len, int y)
{
	int	i;

	while (y > 2)
	{
		ft_putchar('B');
		i = 0;
		while (i < len - 2)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('B');
		ft_putchar('\n');
		y--;
	}
}

void	column(int height)
{
	int	i;

	i = 0;
	ft_putchar('A');
	while (i < height - 2)
	{
		ft_putchar('\n');
		ft_putchar('B');
		i++;
	}
	ft_putchar('\n');
	ft_putchar('A');
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if ((x < 1) || (y < 1))
	{
		ft_putstr("Error : expected positive non-null arguments\n");
		return ;
	}
	if ((x == 1) && (y == 1))
	{
		ft_putchar('A');
		ft_putchar('\n');
		return ;
	}
	if (y == 1)
	{
		line(x);
		return ;
	}
	if (x == 1)
	{
		column(y);
		return ;
	}
	line(x);
	body(x, y);
	line(x);
	return ;
}
