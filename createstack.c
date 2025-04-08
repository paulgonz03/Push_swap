/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulgonz <paulgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:37:35 by paulgonz          #+#    #+#             */
/*   Updated: 2025/04/08 14:17:43 by paulgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

// void print_stack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		printf("Index: %d, num: %d\n", stack->index, stack->num);
// 		stack = stack->next;
// 	}
// }

t_stack	*list_is_string(char **argv, int k)
{
	char	**matrixnum;
	t_stack	*newnode;
	int		j;
	t_stack	*temp;

	j = 0;
	matrixnum = ft_split(argv[k], ' ');
	if (!matrixnum[0])
		return (freematrix(matrixnum), NULL);
	temp = ft_lstnew(ft_atol(matrixnum[j]));
	j++;
	while (matrixnum[j])
	{
		newnode = ft_lstnew(ft_atol(matrixnum[j]));
		if (!newnode)
		{
			freematrix(matrixnum);
			free_stack(temp);
			return (0);
		}
		ft_lstadd_back(&temp, newnode);
		j++;
	}
	freematrix(matrixnum);
	return (temp);
}

int	is_string(char *argv)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (argv[i] != '\0')
	{
		while ((argv[i]) == 32)
			i++;
		while (((argv[i] >= '0' && argv[i] <= '9') || argv[i] == '-'))
			i++;
		while ((argv[i]) == 32)
			i++;
		if (argv[i] >= '0' && argv[i] <= '9')
		{
			counter++;
			i++;
		}
	}
	return (counter);
}

t_stack	*list_is_argv(char **argv, int argc)
{
	t_stack		*newnode;
	t_stack		*temp;
	int			k;
	long int	counter;

	k = 1;
	temp = 0;
	while (argv[k] && k < argc)
	{
		counter = is_string(argv[k]);
		if (counter > 0)
			newnode = list_is_string(&argv[k], 0);
		else
			newnode = ft_lstnew(ft_atol(argv[k]));
		if (newnode->num < INT_MIN || newnode->num > INT_MAX)
		{
			free_stack(newnode); 
			return(0);
		}
		if (!newnode)
		{
			free_stack(newnode);
			free_stack(temp);
			return (0);
		}
		ft_lstadd_back(&temp, newnode);
		k++;
	}
	return (temp);
}

int	*stack_to_string(t_stack *a)
{
	int		*array;
	int		longstack;
	t_stack	*aux;
	int		i;

	i = 0;
	aux = a;
	longstack = 1;
	while (aux->next)
	{
		aux = aux->next;
		longstack++;
	}
	array = ft_calloc(longstack + 1, sizeof(int));
	if (!array)
		return (0);
	while (a)
	{
		array[i] = a->num;
		a = a->next;
		i++;
	}
	return (array);
}

int	create_stack(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	counter;

	if (argc == 2)
	{
		a = list_is_string(argv, 1);
		if (!a)
			return (free_stack(a), 0);
	}
	else
	{
		a = list_is_argv(argv, argc);
		if (!a)
			return (free_stack(a), 0);
	}
	if (!is_num_repeat(a))
		return (free_stack(a), 0);
	if (!is_order(a))
		return (free_stack(a), 1);
	counter = ft_lstsize(a);
	if (counter < 6)
		return (sort_less(a, b, counter), 1);
	else
		return (k_sort(a, b), 1);
}
