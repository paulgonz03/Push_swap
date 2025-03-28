#include "push_swap.h"
#include "libft/libft.h"

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

void rr(t_stack **a, t_stack **b)
{
    ra(a);
    rb(b);
    ft_putstr_fd("rr\n", 1);
}