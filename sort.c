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

int	*bubble_sort(int *ordennums)
{
	int	i;
	int	aux;

	i = 0;
	aux = 0;
	while (ordennums[i] && ordennums[i + 1])
	{
		if (ordennums[i] > ordennums[i + 1])
		{
			aux = ordennums[i];
			ordennums[i] = ordennums[i + 1];
			ordennums[i + 1] = aux;
		}
		i++;
	}
	return (ordennums);
}

int	*issorter(int *ordernums)
{
	int	i;

	i = 0;
	while (ordernums[i] && ordernums[i + 1])
	{
		if (ordernums[i] < ordernums[i + 1])
			i++;
		else
		{
			ordernums = bubble_sort(ordernums);
			i = 0;
		}
	}
	return (ordernums);
}

void	*ksort_normal(t_stack *a, t_stack *b, int len)
{
	int	range;
	int	i;

	i = 1;
	if (len > 7)
		range = square(len) * 14 / 10;
	else
		range = len / 2;
	while (a)
	{
		if (a->index <= i++)
		{
			pb(&a, &b);
			rb(&b);
		}
		else if (a->index <= i + range)
		{
			pb(&a, &b);
			i++;
		}
		else
			ra(&a);
	}
	ksort_reverse(a, b, len);
	return (0);
}

void	*ksort_reverse(t_stack *a, t_stack *b, int len)
{
	int	rb_num;
	int	rrb_num;

	while (len - 1 >= 0)
	{
		rb_num = counter(b, len - 1);
		rrb_num = (len + 3) - rb_num;
		if (rb_num <= rrb_num)
		{
			while (b->index != len - 1 && b->next)
				rb(&b);
			pa(&a, &b);
			len--;
		}
		else
		{
			while (b->index != len - 1)
				rrb(&b);
			pa(&a, &b);
			len--;
		}
	}
	ra(&a);
	return (a);
}

void	k_sort(t_stack *a, t_stack *b)
{
	int	*numsinstring;
	int	*ordernums;
	int	len;

	len = ft_lstsize(a);
	numsinstring = stacktostring(a);
	ordernums = issorter(numsinstring);
	a = setindex(a, ordernums);
	free(ordernums);
	ksort_normal(a, b, len);
}
