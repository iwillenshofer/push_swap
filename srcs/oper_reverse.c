/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:41:41 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/24 15:33:27 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rev_rotate(int *list, int size)
{
	int i;

	i = size - 1;
	while (i > 0)
	{
		swap(&list[i], &list[i - 1]);
		i--;
	}
}

void rev_rotate_a(t_stack *stack, int print)
{
	print_operation("rra", print);
	if (stack->size_a > 1)
		rev_rotate(stack->a, stack->size_a);
}

void rev_rotate_b(t_stack *stack, int print)
{
	print_operation("rrb", print);
	if (stack->size_b > 1)
		rev_rotate(stack->b, stack->size_b);
}

void rev_rotate_r(t_stack *stack, int print)
{
	print_operation("rrr", print);
	rev_rotate_a(stack, FALSE);
	rev_rotate_b(stack, FALSE);
}