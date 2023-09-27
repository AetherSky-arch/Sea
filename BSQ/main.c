/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:57:39 by arguez            #+#    #+#             */
/*   Updated: 2023/09/26 22:44:47 by arguez           ###   ########.fr       */
/*                                                                            */
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

struct s_point	*algo(int numof_lines, char *conditions, char *path)
{
	char			**tab;
	struct s_point	square;
	struct s_point	offset;
	struct s_point	*res;
	int	llen;

	res = (struct s_point *) malloc (2 * sizeof(struct s_point));
	square = initializer(0, 0);
	offset = initializer(0, 0);
	tab = file_to_strs(path);
	filler(tab, path);
	llen = ft_strlen(tab[0]);
	while (((square.x < llen) && (square.y < numof_lines))
		&& ((offset.x < llen) && (offset.y < numof_lines)))
	{
		if (tab[offset.y][offset.x] == '\n')
                {
                        offset.x = offset.x - square.x;
                        square.x = 0;
                        offset.y++;
                        square.y++;
                }

		if (is_square_empty(offset, square, tab, conditions[1]))
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
	printf("%d, %d\n%d, %d\n", res[0].x, res[0].y, res[1].x, res[1].y);
	freeer(tab);
	return (res);
}

int	parser(char *path, int file)
{
	algo(is_numof_lines(path, file), ft_conditions(file, path), path);
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
				printf("%s\n", "map error");
			else
			{
				printf("conditions: %s\nnumof: %d\nlen_line: %d\n",
					ft_conditions(file, argv[i]), is_numof_lines(argv[i], file),
					get_line_len(argv[i]));
				parser(argv[i], file);
				close(file);
			}
			i++;
		}
	}
	else
		printf("%s\n", "[reading stdrin]");
}
