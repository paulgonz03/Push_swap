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

t_stack				*liststring(char **argv, int k);
t_stack				*listargv(char **argv, int argc);
int					isastring(char *argv);
int					createstack(int argc, char **argv, t_stack *a, t_stack *b);
int					*stacktostring(t_stack *a);

void				error(void);
int					numrepeat(t_stack *a);
int					onlynum(char **argv);
int					checkarguments(char **argv);

void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rrb(t_stack **b);

int					*bubble_sort(int *ordennums);
int					*issorter(int *ordennums);
void				k_sort(t_stack *a, t_stack *b);
void				*ksort_normal(t_stack *a, t_stack *b, int len);
void				*ksort_reverse(t_stack *a, t_stack *b, int len);

int					square(int len);
int					counter(t_stack *b, int pos);
t_stack				*setindex(t_stack *a, int *ordernums);
void				freematrix(char **p);
long int			ft_atol(char *str);

#endif
