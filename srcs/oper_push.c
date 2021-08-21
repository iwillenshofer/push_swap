/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:39:12 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/24 20:21:17 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack, int print)
{
	print_operation("pa", print);
	if (stack->size_b)
	{
		stack->size_a += 1;
		rev_rotate_a(stack, FALSE);
		stack->a[0] = stack->b[0];
		rotate_b(stack, FALSE);
		stack->size_b -= 1;
	}
}

void	push_b(t_stack *stack, int print)
{
	print_operation("pb", print);
	if (stack->size_a)
	{
		stack->size_b += 1;
		rev_rotate_b(stack, FALSE);
		stack->b[0] = stack->a[0];
		rotate_a(stack, FALSE);
		stack->size_a -= 1;
	}
}
