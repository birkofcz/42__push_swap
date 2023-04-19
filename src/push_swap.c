/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:38:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/19 15:09:10 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	s_stack	stack_a;
	s_stack	stack_b;

	if (argc < 2)
	{
		return (1);
	}
	else if (argc == 2)
	{
		if ((ft_stackinit_string(&stack_a, &stack_b, argv[1])) == 0)
		{
			ft_sortstack(&stack_a, &stack_b);
			ft_free_stacks(&stack_a, &stack_b);
		}
	}
	else if (argc > 2)
	{
		if ((ft_stackinit_numbers(&stack_a, &stack_b, argv, argc)) == 0)
		{
			ft_sortstack(&stack_a, &stack_b);
			ft_free_stacks(&stack_a, &stack_b);
		}
	}
	return (0);
}