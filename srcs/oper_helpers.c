/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 22:49:08 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/24 10:22:21 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_operation(char *name, int print)
{
	if (print)
	{
		ft_putstr(name);
		ft_putchar('\n');
	}
}

int is_sorted(t_stack *stack)
{
	int i;
	int sorted;

	i = 0;
	sorted = TRUE;	
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] == stack->a[i + 1])
			ex_quit(stack, TRUE);
		if (stack->a[i] > stack->a[i + 1])
			sorted = FALSE;
		i++;
	}
	return (sorted);
}