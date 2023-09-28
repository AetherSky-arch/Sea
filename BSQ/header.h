/* ************************************************************************** */
/*										   */
/*								:::	   ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*							   +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>				 +#+  +:+	   +#+	      */
/*							+#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/26 20:36:09 by arguez		    #+#    #+#	      */
/*   Updated: 2023/09/27 23:30:54 by lmoran           ###   ########.fr       */
/*										   */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int				is_digit(char c);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
int				get_line_len(char *path);
int				test_numoflines(int numof_lines, int len, char *path);
int				check_conditions(char *path, char *conditions);
int				parser(char *path, int file);
char			**file_to_strs(char *path);
int				is_numof_lines(char *path, int file);
char			*ft_conditions(int file, char *path);
struct s_point	initializer(int x, int y);
void			filler(char **tab, char *path);
void			freeer(char **tab);
void			checknextline(char **tab, struct s_point offset,
					struct s_point square);
void			map_filler(struct s_point *res, char **tab, char obstacle);
void			printer(char **tab, int numof_lines);
void			ft_putchar(char c, int output);
void			ft_putstr(char *str);
void			reader(void);
void			freeer(char **tab);

typedef struct s_point
{
	int			x;
	int			y;
	int			original_x;
	int			original_y;
}				t_point;

#endif
