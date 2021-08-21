/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:22:39 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/24 15:14:21 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *list, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		swap(&list[i], &list[i + 1]);
		i++;
	}
}

void	rotate_a(t_stack *stack, int print)
{
	print_operation("ra", print);
	if (stack->size_a > 1)
		rotate(stack->a, stack->size_a);
}

void	rotate_b(t_stack *stack, int print)
{
	print_operation("rb", print);
	if (stack->size_b > 1)
		rotate(stack->b, stack->size_b);
}

void	rotate_r(t_stack *stack, int print)
{
	print_operation("rr", print);
	rotate_a(stack, FALSE);
	rotate_b(stack, FALSE);
}
