#include "push_swap.h"
#include "libft/libft.h"

void sa(t_stack **a)
{
    t_stack *first;
    t_stack *second;

    if (a == NULL || *a == NULL || (*a)->next == NULL)
        return;
    first = *a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *a = second;
    ft_putstr_fd("sa\n", 1);
}
void sb(t_stack **b)
{
    t_stack *first;
    t_stack *second;

    if (b == NULL || *b == NULL || (*b)->next == NULL)
        return;
    first = *b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *b = second;
    ft_putstr_fd("sb\n", 1);
}

void ss(t_stack **a, t_stack **b)
{
    sa(a);
    sb(b);
    ft_putstr_fd("ss\n", 1);
}

void pa(t_stack **a, t_stack **b)
{   
    t_stack *first_b;

    if (b == NULL || *b == NULL)
        return;

    first_b = *b;
    *b = first_b->next;
    first_b->next =*a;
    *a =first_b;
    ft_putstr_fd("pa\n", 1);
}

void pb(t_stack **a, t_stack **b)
{   
    t_stack *first_a;

    if (a == NULL || *a == NULL)
        return;
    first_a = *a;
    *a = first_a->next;
    first_a->next = *b;
    *b = first_a;    
    ft_putstr_fd("pb\n", 1);
}
