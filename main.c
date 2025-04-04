/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulgonz <paulgonz@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:38:14 by paulgonz          #+#    #+#             */
/*   Updated: 2025/03/31 11:38:16 by paulgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = NULL;
	if (argc < 2)
		error();
	if (!checkarguments(argv))
		error();
	if (!createstack(argc, argv, a, b))
		error();
	exit(EXIT_SUCCESS);
}
