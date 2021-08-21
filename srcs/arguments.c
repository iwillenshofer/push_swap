/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:50:50 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/21 18:26:15 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** returns the position of an element by calculating
** how many numbers are smaller than it
*/

int	index_position(int *list, int size, int nb)
{
	int	i;
	int	pos;

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
int	*index_list(int *list, int size)
{
	int	i;
	int	*index;

	index = duplicate_array(list, size);
	i = 0;
	while (i < size)
	{
		index[i] = index_position(list, size, list[i]);
		i++;
	}
	free(list);
	return (index);
}

/*
** navigates through all elements searching for a duplicate
** value.
*/

void	duplicate_checker(t_stack *stack)
{
	int	i;
	int	j;

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
** arguments special case:
** in case only one argument is passed, separating numbers
** by spaces, it is parsed by this function. In that case, 
** the new argv must be freed on exit.
*/

char **special_arguments(t_stack *stack, char **argv)
{
	int i;
	int numeric;

	i = 0;
	numeric = TRUE;
	while (argv[1][i])
	{
		if(!(ft_isnumber(argv[1][i])))
			numeric = FALSE;
		i++;
	}
	if (numeric)
		return (argv);
	stack->special_arg = string_to_operators(argv[1]);
	stack->size = array_lenght(stack->special_arg);
	return (stack->special_arg);
}

/*
** Initializes the stack to zero.
*/

void init_stack(t_stack *stack)
{
	stack->a = 0x0;
	stack->b = 0x0;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->special_arg = 0x0;
}

/*
* gets the command line arguments and returns them into a stack.
* atoi will check if all items are numbers
* then we check for duplicates
*/

t_stack	*get_arguments(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	int		initial_arg;

	i = 0;
	initial_arg = 1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	init_stack(stack);
	stack->size = argc - 1;
	if (argc == 2)
		argv = special_arguments(stack, argv);
	stack->size_a = stack->size;
	stack->a = (int *)malloc(sizeof(int) * stack->size);
	stack->b = (int *)malloc(sizeof(int) * stack->size);
	if (stack->special_arg)
		initial_arg = 0;
	while (i < stack->size)
	{
		stack->a[i] = ft_atoi(argv[i + initial_arg], stack);
		stack->b[i] = 0;
		i++;
	}
	duplicate_checker(stack);
	stack->a = index_list(stack->a, stack->size_a);
	return (stack);
}
