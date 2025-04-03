/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulgonz <paulgonz@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:38:51 by paulgonz          #+#    #+#             */
/*   Updated: 2025/03/31 11:38:52 by paulgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	square(int len)
{
	int	n;

	n = 2;
	if (len < 4)
		return (1);
	else
	{
		while (n * n <= len)
		{
			if (n * n == len)
				return (n);
			n++;
		}
		return (n - 1);
	}
}

int	counter(t_stack *b, int pos)
{
	int	counter;

	counter = 0;
	while (b)
	{
		if (pos == b->index)
			return (counter);
		counter++;
		b = b->next;
	}
	return (0);
}

t_stack	*setindex(t_stack *a, int *ordernums)
{
	int		i;
	t_stack	*head;
	int size;

	size = ft_lstsize(a);
	head = a;
	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (ordernums[i] == a->num)
			{
				a->index = i + 1;
				break ;
			}
			i++;
		}
		a = a->next;
	}
	return (head);
}

void	freematrix(char **p)
{
	int	i;

	i = -1;
	while (p[++i])
		free(p[i]);
	free(p);
}

long int	ft_atol(char *str)
{
	int			i;
	long int	sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (sign * res);
}
