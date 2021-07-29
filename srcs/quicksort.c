/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 23:33:56 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/25 14:34:45 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
//sources
//https://en.wikipedia.org/wiki/Median_of_medians

int *duplicate_array(int *list, int size)
{
	int i;
	int *dup;

	i = 0;
	dup = (int*)malloc(sizeof(int) * size);
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
int median(int *list, int size)
{
	int i;
	int j;
	int ret;

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
	return(ret);
}


int qs_swap(t_stack *stack)
{
	if (stack->size_a > 1 && stack->size_b > 1 && stack->a[0] > stack->a[1] && stack->b[0] > stack->b[1])
		swap_s(stack, TRUE);
	else if (stack->size_a > 1 && stack->a[0] > stack->a[1])
		swap_a(stack, TRUE);
	else if (stack->size_b > 1 && stack->b[0] > stack->b[1])
		swap_b(stack, TRUE);
	else
		return (FALSE);
	return (TRUE);
}

int qs_rotate(t_stack *stack)
{
	if (stack->size_a > 1 && stack->size_b > 1 && stack->a[0] > stack->a[stack->size_a - 1] && stack->b[0] > stack->size_b - 1)
		rotate_r(stack, TRUE);
	else if (stack->size_a > 1 && stack->a[0] > stack->a[stack->size_a - 1])
		rotate_a(stack, TRUE);
	else if (stack->size_b > 1 && stack->b[0] > stack->b[stack->size_b - 1])
		rotate_b(stack, TRUE);
	else
		return (FALSE);
	return (TRUE);
}

int qs_rev_rotate(t_stack *stack)
{
	if (stack->size_a > 1 && stack->size_b > 1 && stack->a[0] > stack->a[stack->size_a - 1] && stack->b[0] > stack->size_b - 1)
		rotate_r(stack, TRUE);
	else if (stack->size_a > 1 && stack->a[0] > stack->a[stack->size_a - 1])
		rotate_a(stack, TRUE);
	else if (stack->size_b > 1 && stack->b[0] > stack->b[stack->size_b - 1])
		rotate_b(stack, TRUE);
	else
		return (FALSE);
	return (TRUE);
}

/*
** strategy:
** divide into smaller and smaller chunks sending it from a to B and 
** returning to A
*/

int z = 0;

/*
** returns the position of the number immediately smaller/larger
** -1 if it does not find it.
** kind accepts SMALLER, LARGER (0/1)
*/
int find_immediate(int *list, int size, int nb, int kind)
{
	int i;
	int pos;
	int last_saved_nb;

	i = 0;
	pos = -1;
	last_saved_nb = INT_MIN;
	if (kind == LARGER)
		last_saved_nb = INT_MAX;
	while (i < size)
	{
		if ((kind == SMALLER && nb > list[i] && list[i] > last_saved_nb)
		|| (kind == LARGER && nb < list[i] && list[i] < last_saved_nb))
		{
			pos = i;
			last_saved_nb = list[i];
		}
		i++;
	}
	return(pos);
}

int min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void rotate_b_list(t_stack *stack, int amount, int reverse)
{
	int i;

	i = 0;
	while (i < amount - 1)
	{
		if (reverse)
			rev_rotate_b(stack, TRUE);
		else
			rotate_b(stack, TRUE);
		i++;
	}
}

void send_to_b(t_stack *stack)
{
	int large;
	int small;
	int pos;
	int rev;

	large = find_immediate(stack->b, stack->size_b, stack->a[0], LARGER);
	small = find_immediate(stack->b, stack->size_b, stack->a[0], SMALLER);
	rev = FALSE;
	if (stack->size_b)
	{
		if (large >= 0 && small >= 0)
			pos = min(large, small);
		else if (large)
			pos = large >= 0;
		else
			pos = small;
		if (pos > stack->size_b - pos)
		{
			pos = stack->size_b - pos;
			rev = TRUE;
		}
		printf("pos: %d, rev: %d\n", pos, rev);
		fflush(stdout);
		rotate_b_list(stack, pos, rev);
	}
	push_b(stack, TRUE);
}


void quicksort3(t_stack *stack, int start, int size)
{
		int i;
		int pivot;
		pivot = (start + size) / 2;
		i = 0;
		while (i < size)
		{
			if (stack->a[0] < pivot)
				push_b(stack, TRUE);
			else
			{
				rotate_a(stack, TRUE);
			}
			i++;
		}
		(void)start;
		(void)size;

}










void quicksort2(t_stack *stack, int start, int size)
{
		int i;
		int med;


		// then we get the median of that chunk.
		med = median(stack->a, size);
		// every value below that median goes to B
		i = 0;
		while (i < size)
		{
			if (stack->a[0] < med)
				push_b(stack, TRUE);
			else
				rotate_a(stack, TRUE);
			i++;
		}
		i = 0;
		while (i < stack->size_b)
		{
			rev_rotate_a(stack, TRUE);
			i++;
		}
		printf("Returned: %d\n", i);		
		int f1 = start;
		int s1 = stack->size_b;
		int f2 = start + f1;
		int s2 = size - s1;
		while (stack->size_b)
		{
			push_a(stack, TRUE);
		}
		if (s1 > 1)
			quicksort(stack, f1, s1);
		printf("Start: %d, Size: %d\n", f1, s1);


		(void)start;
		(void)size;
		(void)f2;
		(void)s2;
		}




/*
** returns the position of the element of minimum value;
*/
int min_list(int *list, int size)
{
	int i;
	int pos;
	int min_element;
	
	i = 0;
	pos = 0;
	min_element = INT_MAX; 
	while (i < size)
	{
		if (list[i] < min_element)
		{
			min_element = list[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void rotate_to_element(t_stack *stack, int pos)
{
	int value;
	int reverse;

	reverse = FALSE;
	value = stack->a[pos];
	if (pos > (stack->size_a / 2))
		reverse = TRUE;
	while (stack->a[0] != value)
	{
		if (reverse)
			rev_rotate_a(stack, TRUE);
		else
			rotate_a(stack, TRUE);
	}
}

void quicksort(t_stack *stack, int start, int size)
{
	while (stack->size_a)
	{
		rotate_to_element(stack, min_list(stack->a, stack->size_a));
		push_b(stack, TRUE);
	}
	while (stack->size_b)
		push_a(stack, TRUE);
	(void)stack;
	(void)start;
	(void)size;	
}
