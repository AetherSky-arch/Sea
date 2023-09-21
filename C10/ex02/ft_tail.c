/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/14 21:47:57 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/16 22:07:35 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "header.h"

void	read_last_10(char *path, int file, int lines, int headers)
{
	char	c;

	if (headers == 1)
	{
		ft_putstr("==> ", 1);
		ft_putstr(basename(path), 1);
		ft_putstr(" <==\n", 1);
	}
	close(file);
	file = open(path, O_RDONLY);
	while (lines > 10)
	{
		read(file, &c, 1);
		if (c == '\n')
			lines--;
	}
	while (read(file, &c, 1))
		write(1, &c, 1);
}

void	read_last_bytes(char *path, int file, int headers, int bytes)
{
	char	c;
	int		chars;

	chars = chars_counter(file);
	if (headers == 1)
	{
		ft_putstr("==> ", 1);
		ft_putstr(basename(path), 1);
		ft_putstr(" <==\n", 1);
	}
	close(file);
	file = open(path, O_RDONLY);
	while (chars > bytes)
	{
		read(file, &c, 1);
		chars--;
	}
	while (read(file, &c, 1))
		write(1, &c, 1);
}

void	factory(char **argv, int headers)
{
	int	file;
	int	lines;
	int	i;

	i = 0;
	while (argv[++i])
	{
		file = open(argv[i], O_RDONLY);
		if (file == -1)
		{
			ft_putstr(strerror(errno), 2);
			return ;
		}
		lines = lines_counter(file);
		if (i != 1)
			ft_putstr("\n", 1);
		read_last_10(argv[i], file, lines, headers);
	}
	close(file);
}

void	cutter(char **argv, int headers, int bytes)
{
	int	file;
	int	i;

	i = 2;
	while (argv[++i])
	{
		file = open(argv[i], O_RDONLY);
		if (file == -1)
		{
			ft_putstr(strerror(errno), 2);
			return ;
		}
		if (i != 3)
			ft_putstr("\n", 1);
		read_last_bytes(argv[i], file, headers, bytes);
	}
	close(file);
}

int	main(int argc, char **argv)
{
	int	headers;
	int	i;

	headers = 0;
	if (argc == 1)
		reader();
	if (argc > 2)
		headers = 1;
	i = 0;
	while (i < argc - 1)
	{
		if (strcmp(argv[i], "-c") == 0)
		{
			if (check_digits(argv[i + 1]))
			{
				argc = argc - 2;
				if (argc <= 2)
					headers = 0;
				cutter(argv, headers, ft_atoi(argv[i + 1]));
				return (0);
			}
		}
		i++;
	}
	factory(argv, headers);
}
