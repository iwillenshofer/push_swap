/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:53:14 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/21 18:22:06 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define FALSE	0
# define TRUE	1

# define SMALLER	0
# define LARGER		1

typedef	struct s_stack
{
	int *a;
	int	*b;
	int size;
	int size_a;
	int size_b;
	char **special_arg;
}	t_stack;

/*
** exit.c
** handles program exit.
*/
void ex_quit(t_stack *stack, int error);


/*
** libft_basics.c
** implements basic functions from libft.
*/
int	ft_strlen(char *str);
void	ft_putstr(char *str);
int ft_isnumber (char c);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

/*
** libft_atoi.c
** modified implementation of atoi
*/
int ft_atoi(char *str, t_stack *stack);

/*
** arguments.c
** handles initial argument checking and conversion into the stacks.
*/
t_stack *get_arguments(int argc, char **argv);

/*
** stack_print.c
*/
void stk_print(t_stack *stack);

/*
** Operations
*/

void swap(int *a, int *b);
void swap_a(t_stack *stack, int print);
void swap_b(t_stack *stack, int print);
void swap_s(t_stack *stack, int print);

void rotate(int *list, int size);
void rotate_a(t_stack *stack, int print);
void rotate_b(t_stack *stack, int print);
void rotate_r(t_stack *stack, int print);

void rev_rotate(int *list, int size);
void rev_rotate_a(t_stack *stack, int print);
void rev_rotate_b(t_stack *stack, int print);
void rev_rotate_r(t_stack *stack, int print);

void push_a(t_stack *stack, int print);
void push_b(t_stack *stack, int print);


int is_sorted(t_stack *stack, int *list, int size);
int rev_is_sorted(int *list, int size);
void print_operation(char *name, int print);

/*
** quicksort
*/
int median(int *list, int size);
void quicksort(t_stack *stack, int start, int end);
void bitsort(t_stack *stack, int end);
void ft_radixsort(t_stack *stack);
int *duplicate_array(int *list, int size);
int max(int a, int b);

void ft_smallsort(t_stack *stack);

/*
** arguments helper
*/
int		ft_isspace(char c);
char	*ft_addchar(char *s1, char c);
char	**add_item(char **ops, char *item, size_t size);
char	**string_to_operators(char *string);
int	array_lenght(char **s);
void	free_ops(char **ss);



#endif