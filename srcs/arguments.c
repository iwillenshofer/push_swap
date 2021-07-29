/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:50:50 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/25 12:42:00 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/*
** returns the position of an element by calculating
** how many numbers are smaller than it
*/

int index_position(int *list, int size, int nb)
{
	int i;
	int pos;

	i = 0;
	pos = 0;
	while (i < size)
	{
		if (list[i] < nb)
			pos++;
		i++;
	}
	return (pos);
}

/*
** generates index from list A
*/
int *index_list(int *list, int size)
{
	int i;
	int *index;

	index = duplicate_array(list, size);
	i = 0;
	while (i < size)
	{
		index[i] = index_position(list, size, list[i]);
		i++; 
	}
	free(list);
	return(index);
}

/*
** navigates through all elements searching for a duplicate
** value.
*/

void duplicate_checker(t_stack *stack)
{
	int i;
	int j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->a[j] == stack->a[i])
				ex_quit(stack, TRUE);
			j++;
		}
		i++;
	}
}

/*
* gets the command line arguments and returns them into a stack.
* atoi will check if all items are numbers
* then we check for duplicates
*/

t_stack *get_arguments(int argc, char **argv)
{
	int i;
	t_stack *stack;

	i = 0;
	stack = malloc(sizeof(t_stack));
	stack->size = argc - 1;
	stack->size_a = stack->size;
	stack->size_b = 0;
	stack->a = (int*)malloc(sizeof(int) * stack->size);
	stack->b = (int*)malloc(sizeof(int) * stack->size);
	while (i < stack->size)
	{
		stack->a[i] = ft_atoi(argv[i + 1], stack);
		stack->b[i] = 0;
		i++;
	}
	duplicate_checker(stack);
	stack->a = index_list(stack->a, stack->size_a);
	return (stack);
}
