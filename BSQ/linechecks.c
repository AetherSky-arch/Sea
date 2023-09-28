/* ************************************************************************** */
/*										   */
/*								:::	   ::::::::   */
/*   linechecks.c                                       :+:      :+:    :+:   */
/*							   +:+ +:+	      +:+     */
/*   By: lmoran <marvin@42.fr>				 +#+  +:+	   +#+	      */
/*							+#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/26 15:28:16 by lmoran		    #+#    #+#	      */
/*   Updated: 2023/09/27 23:38:45 by lmoran           ###   ########.fr       */
/*										   */
/* ************************************************************************** */

#include "header.h"

int	test_numoflines(int numof_lines, int len, char *path)
{
	int	line_num;
	int	line_len;
	int	c;
	int	file;

	line_num = 0;
	line_len = 0;
	file = open(path, O_RDONLY);
	while (read(file, &c, 1))
	{
		if (c == '\n')
			break ;
	}
	while (read(file, &c, 1))
	{
		line_len++;
		if ((c == '\n') && (line_len == len) && (line_num++ != numof_lines))
			line_len = 0;
		else if ((c == '\n') && !(line_len == len))
			return (0);
	}
	close(file);
	if (line_num == numof_lines)
		return (1);
	return (0);
}

int	check_conditions(char *path, char *conditions)
{
	int		file;
	char	c;
	char	space;
	char	obs;

	space = conditions[0];
	obs = conditions[1];
	file = open(path, O_RDONLY);
	read(file, &c, 1);
	while (read(file, &c, 1))
	{
		if (c == '\n')
			break ;
	}
	while (read(file, &c, 1) != 0)
		if (!(c == space || c == obs || c == '\n'))
			return (0);
	close(file);
	return (1);
}
