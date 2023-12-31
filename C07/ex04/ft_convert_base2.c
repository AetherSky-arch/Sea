/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/20 22:17:49 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/23 00:24:52 by ae7th            ###   ########.fr       */
/*									      */
/* ************************************************************************** */

void	ft_putstr(char *str, int output);

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

int	check_base(char *base)
{
	int	base_size;
	int	i;
	int	j;

	base_size = ft_strlen(base);
	if (base_size < 2)
	{
		ft_putstr("Error : invalid base\n", 2);
		return (0);
	}
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' '
			|| base[i] == '\t' || base[i] == '\v' || base[i] == '\f'
			|| base[i] == '\r' || base[i] == '\n' || base[i] > '~')
		{
			ft_putstr("Error : invalid base\n", 2);
			return (0);
		}
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
			{
				ft_putstr("Error : invalid base\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	convert_and_add(char c, char *base, int result)
{
	int	j;

	j = 0;
	while (base[j])
	{
		if (base[j] == c)
		{
			result *= ft_strlen(base);
			result += j;
		}
		j++;
	}
	return (result);
}

int	analyse(char *str, int i, char *base, int sign)
{
	int	j;
	int	result;
	int	stop;

	result = 0;
	stop = 0;
	while (str[i])
	{
		j = 0;
		while (base[j] && base[j] != str[i] && !stop)
			j++;
		if (!base[j] || stop)
			stop = 1;
		else
			result = convert_and_add(str[i], base, result);
		i++;
	}
	result *= sign;
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (analyse(str, i, base, sign));
}
