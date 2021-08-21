/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:51:35 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/30 22:00:09 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
