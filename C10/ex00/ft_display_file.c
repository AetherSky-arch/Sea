/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:34:48 by arguez            #+#    #+#             */
/*   Updated: 2023/09/14 10:53:44 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

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

int	main(int argc, char **argv)
{
	int		file;
	char	c;

	c = 'a';
	if (argc == 1)
	{
		ft_putstr("File name missing.\n", 2);
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n", 2);
		return (1);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		ft_putstr("Cannot read file.\n", 2);
		return (1);
	}
	while (read(file, &c, 1))
		ft_putchar(c, 1);
	close(file);
}
