/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:21:25 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/19 15:54:13 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* REVERSE ROTATE operations - basic reverse rotate + reverse 
rotate a, b and both (rrr) */

void	ft_reverse_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	i = 0;
	if (stack->top > 0)
	{
		temp = stack->data[0];
		while (i < stack->top)
		{
			stack->data[i] = stack->data[i + 1];
			i++;
		}
		stack->data[stack->top] = temp;
	}
}

void	ft_rra(t_stack *stack_a)
{
	ft_printf("rra\n");
	ft_reverse_rotate(stack_a);
}

void	ft_rrb(t_stack *stack_b)
{
	ft_printf("rrb\n");
	ft_reverse_rotate(stack_b);
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rrr\n");
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}
