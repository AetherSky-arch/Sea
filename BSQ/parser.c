/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:20:59 by arguez            #+#    #+#             */
/*   Updated: 2023/09/26 20:21:11 by arguez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_line_len(char *path)
{
	int		file;
	int		len;
	char	c;

	len = 0;
	file = open(path, O_RDONLY);
	while (read(file, &c, 1))
	{
		if (c == '\n')
			break ;
	}
	while ((read(file, &c, 1)) && (c != '\n'))
		len++;
	len++;
	close(file);
	return (len);
}

char	**file_to_strs(char *path)
{
	int		i;
	int		line_len;
	int		file;
	char	**tab;
	char	c;

	line_len = get_line_len(path);
	i = 0;
	c = '0';
	file = open(path, O_RDONLY);
	tab = (char **)malloc((is_numof_lines(path, file)) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab[(is_numof_lines(path, file) + 1)] = NULL;
	while (i < is_numof_lines(path, file) + 1)
	{
		tab[i] = (char *)malloc(line_len * sizeof(char));
		if (tab[i] == NULL)
			return (NULL);
		i++;
	}
	return (tab);
}

int	is_numof_lines(char *path, int file)
{
	int		file_params;
	int		param_limit;
	int		i;
	char	*numof_lines;
	char	c;

	i = 0;
	file_params = 0;
	param_limit = -1;
	numof_lines = (char *)malloc(sizeof(char) * (10));
	if (numof_lines == NULL)
		return (-1);
	file = open(path, O_RDONLY);
	while ((read(file, &c, 1)) && (c != '\n'))
		file_params++;
	close(file);
	file = open(path, O_RDONLY);
	while ((++param_limit < file_params - 3) && (read(file, &c, 1)) && (c >= '0'
			&& c <= '9'))
		numof_lines[i++] = c;
	close(file);
	if (param_limit == (file_params - 3))
		return (ft_atoi(numof_lines));
	return (-1);
}

char	*ft_conditions(int file, char *path)
{
	char	*str;
	char	c;
	int		file_params;

	file_params = 0;
	file = open(path, O_RDONLY);
	while ((read(file, &c, 1)) && (c != '\n'))
		file_params++;
	close(file);
	file = open(path, O_RDONLY);
	while (file_params > 3)
	{
		file_params--;
		read(file, &c, 1);
	}
	str = (char *)malloc(3);
	if (str == NULL)
		return (NULL);
	read(file, &c, 1);
	str[0] = c;
	read(file, &c, 1);
	str[1] = c;
	read(file, &c, 1);
	str[2] = c;
	return (str);
}
