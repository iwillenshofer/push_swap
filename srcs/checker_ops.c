/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:58:40 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/20 18:30:54 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_exec_op(char *s, t_stack *stack)
{
	if (ft_strcmp(s, "sa"))
		swap_a(stack, FALSE);
	else if (ft_strcmp(s, "sb"))
		swap_b(stack, FALSE);
	else if (ft_strcmp(s, "ss"))
		swap_s(stack, FALSE);
	else if (ft_strcmp(s, "pa"))
		push_a(stack, FALSE);
	else if (ft_strcmp(s, "pb"))
		push_b(stack, FALSE);
	else if (ft_strcmp(s, "ra"))
		rotate_a(stack, FALSE);
	else if (ft_strcmp(s, "rb"))
		rotate_b(stack, FALSE);
	else if (ft_strcmp(s, "rr"))
		rotate_r(stack, FALSE);
	else if (ft_strcmp(s, "rra"))
		rev_rotate_a(stack, FALSE);
	else if (ft_strcmp(s, "rrb"))
		rev_rotate_b(stack, FALSE);
	else if (ft_strcmp(s, "rrr"))
		rev_rotate_r(stack, FALSE);
}

void	checker_exec_ops(char **ops, t_stack *stack)
{
	int	i;

	i = 0;
	while (ops[i])
	{
		checker_exec_op(ops[i], stack);
		i++;
	}
}
