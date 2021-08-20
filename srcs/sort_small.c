/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:46:09 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/30 19:49:18 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** returns the minimum element of minimum value;
*/
int min_list_value(int *list, int size)
{
	int i;
	int min_element;
	
	i = 0;
	min_element = INT_MAX; 
	while (i < size)
	{
		if (list[i] < min_element)
			min_element = list[i];
		i++;
	}
	return (min_element);
}

void rotate_ab(t_stack *s)
{
	if ((s->size_a > 1) && (s->size_b > 1) && (s->a[0] > s->a[1]) && (s->b[0] < s->b[1]) && (!(is_sorted(s, s->a, s->size_a)) && (!(rev_is_sorted(s->b, s->size_b)))))
		rev_rotate_r(s, TRUE);
	else if ((s->size_a > 1) && (s->a[0] < s->a[1]) && (!(is_sorted(s, s->a, s->size_a))))
		rev_rotate_a(s, TRUE);
	else if ((s->size_b > 1) && (s->b[0] > s->b[1]) && (!(rev_is_sorted(s->b, s->size_b))))
		rev_rotate_b(s, TRUE);
}

void swap_ab(t_stack *s)
{
	if ((s->size_a > 1) && (s->size_b > 1) && (s->a[0] < s->a[1]) && (s->b[0] > s->b[1]) && (!(is_sorted(s, s->a, s->size_a)) && (!(rev_is_sorted(s->b, s->size_b)))))
		swap_s(s, TRUE);
	else if ((s->size_a > 1) && (s->a[0] > s->a[1]) && (!(is_sorted(s, s->a, s->size_a))))
		swap_a(s, TRUE);
	else if ((s->size_b > 1) && (s->b[0] < s->b[1]) && (!(rev_is_sorted(s->b, s->size_b))))
		swap_b(s, TRUE);
}

void ft_smallsort(t_stack *stack)
{
	int median_value;

	median_value =  median(stack->a, stack->size_a);
	if ((!(is_sorted(stack, stack->a, stack->size_a))) && stack->size_a > 3)
	{
		while (min_list_value(stack->a, stack->size_a) < median_value)
		{
			if(stack->a[0] >= median_value)
				rotate_a(stack, TRUE);
			else
				push_b(stack, TRUE);
		}
	}
	while (!(is_sorted(stack, stack->a, stack->size_a)) || (stack->size_b > 1 && !(rev_is_sorted( stack->b, stack->size_b))))
	{
		swap_ab(stack);
		rotate_ab(stack);
	}
	while (stack->size_b)
		push_a(stack, TRUE);
}
