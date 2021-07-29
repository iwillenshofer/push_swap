/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 22:49:08 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/29 20:21:05 by iwillens         ###   ########.fr       */
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

int is_sorted(t_stack *stack, int *list, int size)
{
	int i;
	int sorted;

	i = 0;
	sorted = TRUE;	
	while (i < size - 1)
	{
		if (list[i] == list[i + 1])
			ex_quit(stack, TRUE);
		if (list[i] > list[i + 1])
			sorted = FALSE;
		i++;
	}
	return (sorted);
}

int rev_is_sorted(int *list, int size)
{
	int i;
	int sorted;

	i = 0;
	sorted = TRUE;	
	while (i < size - 1)
	{
		if (list[i] < list[i + 1])
			sorted = FALSE;
		i++;
	}
	return (sorted);
}