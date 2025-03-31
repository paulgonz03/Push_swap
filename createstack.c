/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulgonz <paulgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:37:35 by paulgonz          #+#    #+#             */
/*   Updated: 2025/03/31 11:48:31 by paulgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_stack	*liststring(char **argv, int k)
{
	char	**matrixnum;
	t_stack	*newnode;
	int		j;
	t_stack	*temp;
	int		i;

	j = 0;
	i = 0;
	matrixnum = ft_split(argv[k], ' ');
	while (matrixnum[i])
		i++;
	if (!matrixnum)
		return (0);
	temp = ft_lstnew(ft_atol(matrixnum[j]));
	j++;
	while (matrixnum[j])
	{
		newnode = ft_lstnew(ft_atol(matrixnum[j]));
		if (!newnode)
			return (0);
		ft_lstadd_back(&temp, newnode);
		j++;
	}
	freematrix(matrixnum);
	return (temp);
}

int	isastring(char *argv)
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

t_stack	*listargv(char **argv, int argc)
{
	t_stack		*newnode;
	t_stack		*temp;
	int			k;
	long int	counter;

	k = 1;
	temp = 0;
	while (argv[k] && k < argc)
	{
		counter = isastring(argv[k]);
		if (counter > 0)
			newnode = liststring(&argv[k], 0);
		else
			newnode = ft_lstnew(ft_atol(argv[k]));
		if (!newnode)
			return (0);
		ft_lstadd_back(&temp, newnode);
		k++;
	}
	return (temp);
}

int	*stacktostring(t_stack *a)
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

int	createstack(int argc, char **argv, t_stack *a, t_stack *b)
{
	if (argc == 2)
	{
		a = liststring(argv, 1);
		if (!a)
			return (0);
	}
	else
	{
		a = listargv(argv, argc);
		if (!a)
			return (0);
	}
	if (!numrepeat(a))
		return (0);
	k_sort(a, b);
	return (1);
}
