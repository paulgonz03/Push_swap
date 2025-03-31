#include "push_swap.h"
#include "libft/libft.h"

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

void ra(t_stack **a)
{
    t_stack *first_a;
    t_stack *last_a;

    if (a == NULL || *a == NULL || (*a)->next == NULL)
        return;
    first_a = *a;
    last_a = *a;
    *a= first_a->next;
    while(last_a->next)
        last_a = last_a->next;
    last_a->next = first_a;
    first_a->next = NULL;
    ft_putstr_fd("ra\n", 1);
}

void rb(t_stack **b)
{
    t_stack *first_b;
    t_stack *last_b;

    if (b == NULL || *b == NULL || (*b)->next == NULL)
        return;
    first_b = *b;
    last_b = *b;
    *b= first_b->next;
    while(last_b->next)
        last_b = last_b->next;
    last_b->next = first_b;
    first_b->next = NULL;
    ft_putstr_fd("rb\n", 1);
}

void rrb(t_stack **b)
{
    t_stack *last_b;
    t_stack *penul_b;

    last_b = *b;
    while (last_b->next)
    {
        penul_b = last_b;
        last_b = last_b->next;
    }
    penul_b->next = NULL;
    last_b->next = *b;
	*b = last_b;
    ft_putstr_fd("rrb\n", 1);
}
