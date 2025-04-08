/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulgonz <paulgonz@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:38:59 by paulgonz          #+#    #+#             */
/*   Updated: 2025/03/31 11:39:00 by paulgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int get_max(t_stack *a)
{
    int max;

    max = a->num;
    while(a)
    {
        if (a->num > max)
            max = a->num;
        a = a->next; 
    }
    return(max);
}

int get_min(t_stack *a)
{
    int min;

    min = a->num;
    while(a)
    {
        if (a->num < min)
            min = a->num;
        a = a->next; 
    }
    return(min);
}

t_stack *sort_three(t_stack *a)
{
    int max;
    int min;

    max = get_max(a);
    min = get_min(a);
    if (a->num == max && a->next->num != min)
    {
        ra(&a);
        sa(&a);
    }
    else if (a->num == min && a->next->num == max)
    {
        sa(&a);
        ra(&a);
    }
    else if (a->num == max && a->next->num == min)
        ra(&a);
    else if (a->next->num == min && a->next->next->num == max)
        sa(&a);
    else if (a->next->num == max && a->next->next->num  == min)
        rra(&a);
    return(a);
}

t_stack *sort_five(t_stack *a, t_stack *b)
{
    while (ft_lstsize(a) > 3 && a && a->next)
    {
        if (a->num == get_min(a))
            pb(&a, &b);
        else
            ra(&a);
    }
    if (is_order(a) == 0)
        return (a);
    a = sort_three(a);
    while (b)
        pa(&a, &b);
    return(a);
}

void sort_less(t_stack *a, t_stack *b, int counter)
{
    if (counter <= 3)
	{
		a = sort_three(a);
		return(free_stack(a), free_stack(b));
	}
	if (counter > 3 && counter < 6)
	{
		a = sort_five(a, b);
		return(free_stack(a), free_stack(b));
	}
}
