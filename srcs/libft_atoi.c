/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:54:53 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/23 20:57:45 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** atoi helper to check if a string might be a negative/positive number.
** it returns (-1/+1) if the position of the cursor is at the first element,
** the first character of a string is '-' or '+', and
** the following character is a number.
*/

int	ft_issignal(char *str, int pos)
{
	if (!(pos) && str[pos] == '-' && ft_isnumber(str[pos + 1]))
		return (-1);
	if (!(pos) && str[pos] == '+' && ft_isnumber(str[pos + 1]))
		return (1);
	return (FALSE);
}

/*
** check if there is an int over/underflow.
** receive stack to free it (calling quit) if true.
** returns nb if ok.
*/

long long	check_intsize(long long nb, t_stack *stack)
{
	if (nb > INT_MAX || nb < INT_MIN)
		ex_quit(stack, TRUE);
	return (nb);
}

/*
** modified version of libft atoi, converts string into numbers.
** receives t_stack so it can free it in case of error.
*/
int	ft_atoi(char *str, t_stack *stack)
{
	int			i;
	long long	nb;
	int			signal;

	i = 0;
	nb = 0;
	signal = 1;
	while (str[i])
	{
		if (!(ft_isnumber(str[i])))
		{
			signal = ft_issignal(str, i);
			if (signal)
			{
				i++;
				continue ;
			}
			ex_quit(stack, TRUE);
		}
		else
			nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb = check_intsize(nb * signal, stack);
	return ((int)(nb));
}
