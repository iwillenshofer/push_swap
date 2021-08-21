/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:59:21 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/31 09:32:00 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

# define VALID_OPS "sa\0,sb\0,ss\0,pa\0,pb\0,ra\0,rb\0,rr\0,rra,rrb,rrr\0"

int checker_validate_ops(char **ops);
int	ft_strcmp(char *s1, char *s2);
void checker_exec_op(char *s, t_stack *stack);
void checker_exec_ops(char **ops, t_stack *stack);
char **read_stdin(void);


#endif