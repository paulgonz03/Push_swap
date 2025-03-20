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
		printf("Content: %d\n", stack->num);
		stack = stack->next;
	}
}
