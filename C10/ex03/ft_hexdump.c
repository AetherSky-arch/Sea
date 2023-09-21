/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/19 13:15:57 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/21 15:55:24 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	line_victorhugo(int *offset, char *hexa, char *ascii)
{
	offset_printer(offset);
	ft_putstr("  ", 1);
	ft_printer_onebyone(hexa);
	ft_putchar(' ', 1);
	ascii_printer(ascii);
	ft_putchar('\n', 1);
}

void	last_line(int *offset, int file)
{
	char	*ascii;
	char	*hexa;
	char	*doublet;
	char	c;
	int		old;

	ascii = (char *) malloc (15 * sizeof(char));
	hexa = (char *) malloc (30 * sizeof(char));
	doublet = (char *) malloc (2 * sizeof(char));
	offset_printer(offset);
	while (read(file, &c, 1))
	{
		ft_strcat(ascii, c);
		ft_catstr(hexa, byte_converter(c, doublet));
		*offset = *offset + 1;
	}
	old = *offset;
	while (++old % 16 != 0)
		ft_catstr(hexa, "  ");
	ft_putstr("  ", 1);
	ft_printer_onebyone(hexa);
	ft_putstr("  ", 1);
	ascii_printer(ascii);
}

char	*line_reader(int file, int *offset, char *prev, int *flag)
{
	char	*ascii;
	char	*hexa;

	ascii = (char *) malloc (16 * sizeof(char));
	hexa = (char *) malloc (32 * sizeof(char));
	ohbabyitsadouble(file, ascii, hexa);
	if (strcmp(prev, ascii) == 0)
	{
		if (*flag == 0)
		{
			ft_putstr("*\n", 1);
			*flag = 1;
		}
		*offset += 16;
	}
	else
	{
		line_victorhugo(offset, hexa, ascii);
		*flag = 0;
	}
	ft_strcpy(prev, ascii);
	return (ascii);
}

void	file_reader(int file)
{
	int		offset;
	int		f_len;
	int		flag;
	char	*prev;

	flag = 0;
	prev = (char *) malloc (16 * sizeof(char));
	offset = 0;
	f_len = file_len(file);
	file = open("big", O_RDONLY);
	if (file == -1)
	{
		ft_puterror(0);
		return ;
	}
	while (f_len - offset >= 16)
		line_reader(file, &offset, prev, &flag);
	last_line(&offset, file);
	ft_putchar('\n', 1);
	offset = offset - 16;
}

int	main(int argc, char **argv)
{
	int	file;
	int	is_option;

	is_option = 0;
	if (strcmp("-C", argv[1]) == 0)
		is_option = 1;
	file = file_catter(argc, argv, is_option);
	file_reader(file);
	return (0);
}
