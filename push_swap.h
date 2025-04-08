/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulgonz <paulgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:39:34 by paulgonz          #+#    #+#             */
/*   Updated: 2025/03/31 11:48:18 by paulgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}					t_stack;

void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstlast(t_stack *lst);
t_stack				*ft_lstnew(int num);
int					ft_lstsize(t_stack *a);
void				free_stack(t_stack *stack);
void				print_stack(t_stack *stack);

t_stack				*list_is_string(char **argv, int k);
t_stack				*list_is_argv(char **argv, int argc);
int					is_string(char *argv);
int					create_stack(int argc, char **argv, t_stack *a, t_stack *b);
int					*stack_to_string(t_stack *a);

void				error(void);
int					is_num_repeat(t_stack *a);
int					is_only_num(char **argv);
int is_order(t_stack *a);
int					check_arguments(char **argv);

void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);

int					*bubble_sort(int *ordennums);
int					*is_sorter(int *ordennums);
void				k_sort(t_stack *a, t_stack *b);
t_stack				*ksort_normal(t_stack *a, t_stack *b, int len);
t_stack				*ksort_reverse(t_stack *a, t_stack *b, int len);

int					square(int len);
int					counter(t_stack *b, int pos);
t_stack				*set_index(t_stack *a, int *ordernums);
void				freematrix(char **p);
long int			ft_atol(char *str);

t_stack *sort_three(t_stack *a);
t_stack *sort_five(t_stack *stack_a, t_stack *stack_b);
int get_min(t_stack *a);
int get_max(t_stack *a);
void sort_less(t_stack *a, t_stack *b, int counter);

#endif
