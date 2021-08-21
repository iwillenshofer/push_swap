/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 23:33:56 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/30 19:49:42 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	*duplicate_array(int *list, int size)
{
	int	i;
	int	*dup;

	i = 0;
	dup = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		dup[i] = list[i];
		i++;
	}
	return (dup);
}

/*
** returns the median of a list of integers.
*/
int	median(int *list, int size)
{
	int	i;
	int	j;
	int	ret;

	list = duplicate_array(list, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (list[j] > list[j + 1])
				swap(&list[j], &list[j + 1]);
			j = j + 1;
		}
		i++;
	}
	ret = list[(size / 2)];
	free(list);
	return (ret);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

/*
** RADIX SORT
** returns the qtd of bits of the max number among the elements of a list;
*/
int	bits_amount(t_stack *stack)
{
	int	size;
	int	bits;

	bits = 0;
	size = stack->size;
	while (size)
	{
		size = size >> 1;
		bits++;
	}
	return (bits);
}

void	ft_radixsort(t_stack *stack)
{
	int	bit;
	int	mbit;
	int	i;

	bit = 0;
	mbit = bits_amount(stack);
	while (bit < mbit && !(is_sorted(stack, stack->a, stack->size_a)))
	{
		i = 0;
		while (i < stack->size)
		{
			if (!((stack->a[0] >> bit) & 1))
				push_b(stack, TRUE);
			else
				rotate_a(stack, TRUE);
			i++;
		}
		bit++;
		while (stack->size_b)
			push_a(stack, TRUE);
	}
}
