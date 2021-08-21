/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 19:16:40 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/21 19:16:48 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Initializes the stack to zero.
*/

void	init_stack(t_stack *stack)
{
	stack->a = 0x0;
	stack->b = 0x0;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->special_arg = 0x0;
}
