#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}					t_stack;

void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int num);
int	ft_lstsize(t_stack *a);


void	freematrix(char **p);
t_stack *liststring(char **argv, int k);
t_stack *listargv(char **argv, int argc);
int isastring(char *argv);
int createstack(int argc, char **argv, t_stack *a, t_stack *b);
int numrepeat(t_stack *a);
int onlynum(char **argv);
int checkarguments(char **argv);
int *stacktostring(t_stack *a);
long int ft_atol(char *str);


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


int *bubble_sort(int *ordennums);
int *issorter(int *ordennums);
t_stack *setindex(t_stack *a, int *ordernums);
void k_sort(t_stack *a, t_stack *b);
void	*ksort_normal(t_stack *a, t_stack *b, int len);
void	*ksort_reverse(t_stack *a, t_stack *b, int len);


void print_stack(t_stack *stack);
int square(int len);
int counter (t_stack *b, int pos);






#endif