/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulgonz <paulgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:05:26 by paulgonz          #+#    #+#             */
/*   Updated: 2025/04/08 13:05:51 by paulgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*last_a;
	t_stack	*penul_a;

	last_a = *a;
	while (last_a->next)
	{
		penul_a = last_a;
		last_a = last_a->next;
	}
	penul_a->next = NULL;
	last_a->next = *a;
	*a = last_a;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	t_stack	*last_b;
	t_stack	*penul_b;

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

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_putstr_fd("rrr\n", 1);
}
