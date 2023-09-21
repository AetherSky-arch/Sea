/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/09 12:13:02 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/09 17:34:34 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

void	rush(int x, int y);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);

int	checkfor_int(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == '+') || (str[i] == '-') || (str[i] == ' '))
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] < 48) || (str[i] > 57))
		{
			ft_putstr("Error : expected only arguments of type 'int'\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("Error : received ");
		ft_putchar(argc - 1 + 48);
		ft_putstr(" arguments, expected 2\n");
		return (1);
	}
	if (checkfor_int(argv[1]) == 0)
		return (1);
	if (checkfor_int(argv[2]) == 0)
		return (1);
	rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
