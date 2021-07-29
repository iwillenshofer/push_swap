/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:51:35 by iwillens          #+#    #+#             */
/*   Updated: 2021/07/24 11:42:53 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void tests(t_stack *stack)
{
//	ft_putstr("\nMedian: ");
//	ft_putnbr(median(stack->a, stack->size_a));
//	ft_putstr("\nSize A: ");
//	ft_putnbr( stack->size_a);
//	ft_putstr("\nSize B: ");
//	ft_putnbr( stack->size_b);
//	ft_putstr("\n");
	quicksort(stack, 0, stack->size);
//	stk_print(stack);


}

int	main(int argc, char *argv[])
{
	t_stack *stack;
	
	stack = get_arguments(argc, argv);
	tests(stack);
	ex_quit(stack, FALSE);
}


//int	main2(void)
//{
//	char *str = malloc(10 * sizeof(char));
//	read(1, str, 10);
//	write(1, str, 10);
//	free(str);
//	exit(0);
//	return (0);
//}