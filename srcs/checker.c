/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:58:40 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/08 21:36:42 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main(int argc, char *argv[])
{
	char *ops[4];
	
	ops[0] = "ra";
	ops[1] = "ra";
	ops[2] = "ra";
	ops[3] = NULL;

	t_stack *stack;

	if (argc <= 1)
		exit(0);
	stack = get_arguments(argc, argv);
	

	// Then Get ops here
	// with a read function
	read_stdin();
	if (!(checker_validate_ops(ops)))
	{
		//must free ops here
		ex_quit(stack, TRUE);
	}
	checker_exec_ops(ops, stack);
	if (!(is_sorted(stack, stack->a, stack->size_a) || stack->size_b))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	//must free ops here too
	ex_quit(stack, FALSE);
}