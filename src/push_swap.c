/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:38:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/21 13:59:31 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>

int	ft_is_sorted(t_stack *stack_a)
{
	int i;

	i = 1;
	if (stack_a->top == 0)
		return 1;
	while (i <= stack_a->top)
	{
		if (stack_a->data[i-1] < stack_a->data[i])
		{
			return (1);
			break;
		}
		i++;
	}
	return (0);
}

void	ft_run_process(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_sorted(stack_a) == 1)
	{
		ft_sortstack(stack_a, stack_b);
		ft_free_stacks(stack_a, stack_b);
	}
	else
		ft_free_stacks(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		if ((ft_stackinit_string(&stack_a, &stack_b, argv[1])) == 0)
			ft_run_process(&stack_a, &stack_b);
	}
	else if (argc > 2)
	{
		if ((ft_stackinit_numbers(&stack_a, &stack_b, argv, argc)) == 0)
			ft_run_process(&stack_a, &stack_b);
	}
	return (0);
}

