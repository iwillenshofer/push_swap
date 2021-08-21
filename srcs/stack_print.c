/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:29:03 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/29 16:45:33 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putbyte(int nb)
{
	int	nbcpy;
	int	count;
	int	whitespaces;

	whitespaces = 0;
	nbcpy = nb;
	count = 0;
	while (nbcpy)
	{
		nbcpy = nbcpy >> 1;
		count++;
	}
	whitespaces = (int)(sizeof(int)) - count;
	while (whitespaces)
	{
		ft_putchar('0');
		whitespaces--;
	}
	while (count)
	{
		ft_putchar(((nb >> (count - 1)) & 1) + '0');
		count--;
	}
}

void	stk_print(t_stack *stack)
{
	int	i;
	int	size;

	i = 0;
	size = max(stack->size_a, stack->size_b);
	while (i < size)
	{
		if (stack->size_a > i)
			ft_putbyte(stack->a[i]);
		else
			ft_putstr(" ");
		ft_putstr(" ");
		if (stack->size_b > i)
			ft_putbyte(stack->b[i]);
		else
			ft_putstr(" ");
		ft_putstr("\n");
		i++;
	}
	ft_putstr("- -\n");
	ft_putstr("a b");
}
