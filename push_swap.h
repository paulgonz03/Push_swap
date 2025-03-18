#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				num;
	int				pos;
	struct s_stack	*next;
}					t_stack;

int checkarguments(char **argv);
int onlynum(char **argv);
int createstack(int argc, char **argv, t_stack *a);
void print_stack(t_stack *stack);
t_stack	*ft_lstnew(int num);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);

#endif