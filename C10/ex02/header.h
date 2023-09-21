/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/16 20:56:46 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/16 21:52:51 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <libgen.h>
# include <errno.h>

void	ft_putstr(char *str, int output);
void	reader(void);
int		lines_counter(int file);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
int		check_digits(char *str);
int		chars_counter(int file);

#endif
