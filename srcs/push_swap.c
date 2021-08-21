/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:51:35 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/21 19:03:30 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Initializes the stack to zero.
*/

void	init_stack(t_stack *stack)
{
	stack->a = 0x0;
	stack->b = 0x0;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->special_arg = 0x0;
}

void	run_sorting(t_stack *stack)
{
	if (stack->size <= 6)
		ft_smallsort(stack);
	else
		ft_radixsort(stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	if (argc <= 1)
		exit(0);
	stack = get_arguments(argc, argv);
	run_sorting(stack);
	ex_quit(stack, FALSE);
}
