/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: arguez <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/11 22:45:31 by arguez	       #+#    #+#	      */
/*   Updated: 2023/09/11 22:45:44 by arguez           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>
# define SUCCESS 0
# define FALSE 0
# define TRUE 1
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

typedef int	t_bool;

# define EVEN(var) (var % 2 == 0)
#endif
