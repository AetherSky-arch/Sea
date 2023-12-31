/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/19 13:16:47 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/23 00:28:09 by ae7th            ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

void	ohbabyitsadouble(int file, char *ascii, char *hexa);
char	*hexa_converter(int n, char *res);
void	offset_printer(int *offset);
void	ft_puterror(int errno);
void	ft_putstr(char *str, int output);
void	ft_strcat(char *str, char c);
void	ft_catstr(char *dest, char *src);
int		ft_strlen(char *str);
void	ft_puterror(int errno);
void	ft_putchar(char c, int output);
void	ft_printer_twobytwo(char *str);
void	ft_printer_onebyone(char *str);
int		file_len(int file);
void	ascii_printer(char *str);
char	*byte_converter(int n, char *res);
int		ft_strcmp(char *s1, char *s2);
void	ft_strcpy(char *dest, char *src);
int		file_catter(int n, char **argv, int is_option);

#endif
