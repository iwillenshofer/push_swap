/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:58:40 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/21 20:40:22 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	char	**ops;

	if (argc <= 1)
		exit(0);
	stack = get_arguments(argc, argv);
	ops = read_stdin();
	if (!(checker_validate_ops(ops)))
	{
		free_ops(ops);
		ex_quit(stack, TRUE);
	}
	checker_exec_ops(ops, stack);
	if (!(is_sorted(stack, stack->a, stack->size_a)) || stack->size_b)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	free_ops(ops);
	ex_quit(stack, FALSE);
}
