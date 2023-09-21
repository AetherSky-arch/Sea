/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:57:44 by arguez            #+#    #+#             */
/*   Updated: 2023/09/14 20:11:59 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putchar(char c, int output)
{
	write(output, &c, 1);
}

void	ft_putstr(char *str, int output)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], output);
		i++;
	}
}

void	copycat(void)
{
	char	c;

	while (1)
	{
		while (read(0, &c, 1))
			ft_putchar(c, 1);
	}
}

void	print_file(char *path)
{
	int		file;
	char	c;

	file = open(path, O_RDONLY);
	if (file == -1)
	{
		ft_putstr("Cannot read file.\n", 2);
		return ;
	}
	while (read(file, &c, 1))
		ft_putchar(c, 1);
	close(file);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		copycat();
	i = 1;
	while (i < argc)
	{
		print_file(argv[i]);
		i++;
	}
	return (0);
}
