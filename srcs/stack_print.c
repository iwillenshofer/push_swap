/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:29:03 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/25 13:51:01 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stk_print(t_stack *stack)
{
	int i;
	int size;

	i = 0;
	size = max(stack->size_a, stack->size_b);
	while (i < size)
	{
		if (stack->size_a > i)
			ft_putnbr(stack->a[i]);
		else
			ft_putstr(" ");
		ft_putstr(" ");
		if (stack->size_b > i)
			ft_putnbr(stack->b[i]);
		else
			ft_putstr(" ");
		ft_putstr("\n");
		i++;
	}
	ft_putstr("- -\n");
	ft_putstr("a b");
}