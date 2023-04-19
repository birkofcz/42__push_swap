/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:08:18 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/19 15:54:33 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* SWAP operations - switching first two numbers on top of the stack */

void	ft_swap(t_stack *stack)
{
	int	temp;

	if (stack->top > 0)
	{
		temp = stack->data[stack->top];
		stack->data[stack->top] = stack->data[stack->top - 1];
		stack->data[stack->top - 1] = temp;
	}
}

void	ft_sa(t_stack *stack_a)
{
	ft_printf("sa\n");
	ft_swap(stack_a);
}

void	ft_sb(t_stack *stack_b)
{
	ft_printf("sb\n");
	ft_swap(stack_b);
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("ss\n");
	ft_swap(stack_a);
	ft_swap(stack_b);
}
