/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:10:09 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/24 14:44:02 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** simple int swap function.
*/

void swap(int *a, int *b)
{
	int swp;

	swp = *a;
	*a = *b;
	*b = swp;
}

/*
** sa operation
*/
void swap_a(t_stack *stack, int print)
{
	print_operation("sa", print);
	if (stack->size_a > 1)
		swap(&(stack->a[0]), &(stack->a[1]));
}

/*
** sb operation
*/
void swap_b(t_stack *stack, int print)
{
	print_operation("sb", print);
	if (stack->size_b > 1)
		swap(&(stack->b[0]), &(stack->b[1]));
}


/*
** ss operation
*/
void swap_s(t_stack *stack, int print)
{
	print_operation("ss", print);
	swap_a(stack, FALSE);
	swap_b(stack, FALSE);
}
