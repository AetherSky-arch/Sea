/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/21 12:06:34 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/21 17:48:35 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "includes/header.h"

void	do_op(int val1, int val2, char op)
{
	if (op == '/')
		div(val1, val2);
	else if (op == '%')
		mod(val1, val2);
	else if (op == '+')
		add(val1, val2);
	else if (op == '*')
		mult(val1, val2);
	else
		sub(val1, val2);
}

int	main(int argc, char **argv)
{
	int		value1;
	int		value2;
	char	operator;

	if (argc != 4)
		return (1);
	if (ft_strlen(argv[2]) != 1)
	{
		ft_putstr("0\n", 1);
		return (1);
	}
	operator = argv[2][0];
	if ((operator != '+') && (operator != '-') && (operator != '/')
		&& (operator != '*') && (operator != '%'))
	{
		ft_putstr("0\n", 1);
		return (1);
	}
	value1 = ft_atoi(argv[1]);
	value2 = ft_atoi(argv[3]);
	do_op(value1, value2, operator);
	ft_putchar('\n', 1);
	return (0);
}
