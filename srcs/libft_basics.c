/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:27:36 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/23 20:56:58 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * returns string lenght
 */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
 * prints the string 'all at once' to do it faster 
 */
void	ft_putstr(char *str)
{
	int	size;

	size = ft_strlen(str);
	write(1, str, size);
}

/*
** prints a single char
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
** check if a char is numeric 
*/

int	ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

/*
** recursive function to write numbers to strdout.
*/

void	ft_putnbr(int nb)
{
	char		c;
	long long	number;

	number = (long long)nb;
	if (number < 0)
	{
		ft_putchar('-');
		number = number * -1;
	}
	c = (number % 10) + '0';
	number = (number / 10);
	if (number)
		ft_putnbr(number);
	ft_putchar(c);
}
