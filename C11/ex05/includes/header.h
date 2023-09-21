/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/21 12:35:36 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/21 14:53:21 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

void	div(int val1, int val2);
void	mod(int val1, int val2);
void	add(int val1, int val2);
void	sub(int val1, int val2);
void	mult(int val1, int val2);
void	ft_putchar(char c, int output);
void	ft_putstr(char *str, int output);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
int		ft_atoi(char *str);

#endif
