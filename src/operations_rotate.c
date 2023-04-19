/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:16:18 by sbenes            #+#    #+#             */
/*   Updated: 2023/03/27 14:30:14 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* ROTATE operations - basic rotate operation + rotate a, b and both (rr) */

void	ft_rotate(s_stack *stack)
{
	int	temp;
	int	i;

	i = stack->top;
	if (stack->top > 0)
	{
		temp = stack->data[stack->top];
		while (i > 0)
		{
			stack->data[i] = stack->data[i - 1];
			i--;
		}
		stack->data[0] = temp;
	}
}

void	ft_ra(s_stack *stack_a)
{
	ft_printf("ra\n");
	ft_rotate(stack_a);
}

void	ft_rb(s_stack *stack_b)
{
	ft_printf("rb\n");
	ft_rotate(stack_b);
}

void	ft_rr(s_stack *stack_a, s_stack *stack_b)
{
	ft_printf("rr\n");
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
