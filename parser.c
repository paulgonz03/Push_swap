/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulgonz <paulgonz@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:38:36 by paulgonz          #+#    #+#             */
/*   Updated: 2025/03/31 11:38:38 by paulgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	error(void)
{
	ft_printf("Error.\n");
	exit(EXIT_FAILURE);
}

int	numrepeat(t_stack *a)
{
	t_stack	*aux;

	while (a)
	{
		aux = a->next;
		while (aux)
		{
			if (aux->num == a->num)
				return (0);
			aux = aux->next;
		}
		a = a->next;
	}
	return (1);
}

int	onlynum(char **argv)
{
	int	j;
	int	i;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (!((argv[j][i] >= '0' && argv[j][i] <= '9') || (argv[j][i] == 32)
					|| (argv[j][i] == '-')))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	checkarguments(char **argv)
{
	if (!onlynum(argv))
		return (0);
	return (1);
}
