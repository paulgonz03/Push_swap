/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulgonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:05:18 by paulgonz          #+#    #+#             */
/*   Updated: 2025/04/08 13:05:19 by paulgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*first_a;
	t_stack	*last_a;

	first_a = *a;
	*a = first_a->next;
	last_a = *a;
	while (last_a->next)
		last_a = last_a->next;
	last_a->next = first_a;
	first_a->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b)
{
	t_stack	*first_b;
	t_stack	*last_b;

	first_b = *b;
	*b = first_b->next;
	last_b = *b;
	while (last_b->next)
		last_b = last_b->next;
	last_b->next = first_b;
	first_b->next = NULL;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_putstr_fd("rr\n", 1);
}
