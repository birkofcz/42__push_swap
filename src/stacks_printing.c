/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_printing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:31:23 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/21 14:32:45 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Just a helper function to print the stacks */

void	ft_printstacks(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	ft_printf("\n");
	while (i < stack_a->size || i < stack_b->size)
	{
		if (i <= stack_a->top)
			ft_printf("  %d", stack_a->data[stack_a->top - i]);
		else
			ft_printf("   ");
		ft_printf("\t\t");
		if (i <= stack_b->top)
			ft_printf(" %d", stack_b->data[stack_b->top - i]);
		else
			ft_printf("  ");
		ft_printf("\n");
		i++;
	}
	ft_printf(" ---\t\t---\n");
	ft_printf(" stack_a\tstack_b\n");
	ft_printf("\n");
}
