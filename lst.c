#include "push_swap.h"
#include "libft/libft.h"


void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lstnew(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (0);
	new->num = num;
	new->next = NULL;
	return (new);
}
void print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("Index: %d, Content: %d\n", stack->pos, stack->num);
		stack = stack->next;
	}
}
t_stack *liststring(char **argv) 
{
	char **matrixnum = NULL;
	t_stack *newnode;
    int j = 0;
	t_stack *temp = 0;

    matrixnum = ft_split(argv[1], ' ');
    if (!matrixnum)
        return(0);
    temp = ft_lstnew(ft_atoi(matrixnum[j]));
    j++;
    while (matrixnum[j])
    {
	    newnode = ft_lstnew(ft_atoi(matrixnum[j]));
        if (!newnode)
            return (0);
        ft_lstadd_back (&temp, newnode);
        j++;
    }
	return(temp);
}

t_stack *listargv(char **argv) 
{
	t_stack *newnode;
	t_stack *temp = 0;
    int k = 1;

	temp = ft_lstnew(ft_atoi(argv[k]));
	while (argv[++k])
	{
		newnode = ft_lstnew(ft_atoi(argv[k]));
        if (!newnode)
            return (0);
        ft_lstadd_back (&temp, newnode);
	}

	return(temp);
}

int createstack(int argc, char **argv, t_stack *a)
{
	if (argc == 2)
	{
		a = liststring(argv);
		if (!a)
			return(0);
	}
	else 
	{
		a = listargv(argv);
		if (!a)
			return(0);
	}
	print_stack(a);
    return (1);
}
