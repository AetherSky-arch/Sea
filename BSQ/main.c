/* ************************************************************************** */
/*										   */
/*								:::	   ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*							   +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>				 +#+  +:+	   +#+	      */
/*							+#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/26 19:57:39 by arguez		    #+#    #+#	      */
/*   Updated: 2023/09/27 23:21:36 by lmoran           ###   ########.fr       */
/*										   */
/* ************************************************************************** */

#include "header.h"

int	is_square_empty(struct s_point bright, struct s_point tleft, char **tab,
		char obstacle)
{
	int	i;
	int	j;

	j = tleft.y;
	while (j <= bright.y)
	{
		i = tleft.x;
		while (i <= bright.x)
		{
			if (tab[j][i] == obstacle)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

struct s_point	*algo(int numof_lines, char obstacle, char **tab)
{
	struct s_point	square;
	struct s_point	offset;
	struct s_point	*res;
	int				llen;

	res = (struct s_point *)malloc(2 * sizeof(struct s_point));
	square = initializer(0, 0);
	offset = initializer(0, 0);
	llen = ft_strlen(tab[0]);
	while (((square.x < llen) && (square.y < numof_lines)) && ((offset.x < llen)
			&& (offset.y < numof_lines)))
	{
		checknextline(tab, offset, square);
		if (is_square_empty(offset, square, tab, obstacle))
		{
			res[0] = square;
			res[1] = offset;
			offset.x++;
			offset.y++;
		}
		else
		{
			square.x++;
			offset.x++;
		}
	}
	return (res);
}

int	parser(char *path, int file)
{
	char			**tab;
	char			*conds;
	struct s_point	*res;
	int				numof_lines;

	conds = ft_conditions(file, path);
	close(file);
	if (!check_conditions(path, conds) || !test_numoflines(is_numof_lines(path,
				file), get_line_len(path), path))
	{
		ft_putstr("map error");
		return (0);
	}
	numof_lines = is_numof_lines(path, file);
	tab = file_to_strs(path);
	filler(tab, path);
	res = algo(numof_lines, conds[1], tab);
	map_filler(res, tab, conds[2]);
	printer(tab, numof_lines);
	free(conds);
	return (1);
}

int	main(int argc, char **argv)
{
	int	file;
	int	i;

	i = 1;
	if (argc != 1)
	{
		while (i < argc)
		{
			file = open(argv[i], O_RDONLY);
			if (file == -1)
				ft_putstr("map error");
			else
				parser(argv[i], file);
			i++;
		}
	}
	else
	{
		reader();
	}
}
