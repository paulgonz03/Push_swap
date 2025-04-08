/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulgonz <paulgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:38:14 by paulgonz          #+#    #+#             */
/*   Updated: 2025/04/08 15:52:00 by paulgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!check_arguments(argv))
		error();
	if (!create_stack(argc, argv, a, b))
		error();
	exit(EXIT_SUCCESS);
}
