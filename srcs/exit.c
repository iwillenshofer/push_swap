/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:50:28 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/21 19:16:12 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This file handles the program exit, either on error or on completion.
*/

/*
** Free operators (for checker) and special_arg (for push_swap)
*/
void	free_ops(char **ss)
{
	int	i;

	i = 0;
	while (ss[i])
	{
		free(ss[i]);
		i++;
	}
	free(ss);
}

/*
** Frees both stacks
*/

void	free_stacks(t_stack *stack)
{
	if (stack->special_arg)
		free_ops(stack->special_arg);
	free(stack->a);
	free(stack->b);
	free(stack);
}

/*
** quits the program. If error is true, prints the error message.
** exit code also depends on content of error (true or false, 1/0 )
*/

void	ex_quit(t_stack *stack, int error)
{
	if (error)
		ft_putstr("Error\n");
	free_stacks(stack);
	exit(error);
}
