/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:11:16 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/20 09:38:24 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* PUSH operations - basic push and pop + push a and push_b */

void	ft_push(t_stack *stack, int num)
{
	if (stack->top == stack->size - 1)
	{
		ft_printf("Stack overflow!\n");
		return ;
	}
	stack->data[++stack->top] = num;
}

int	ft_pop(t_stack *stack)
{
	if (stack->top == -1)
	{
		ft_printf("Stack underflow!\n");
		return (-1);
	}
	return (stack->data[stack->top--]);
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	int	num;

	if (stack_b->top != -1)
	{
		num = ft_pop(stack_b);
		ft_push(stack_a, num);
		ft_printf("pa\n");
	}
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	int	num;

	if (stack_a->top != -1)
	{
		num = ft_pop(stack_a);
		ft_push(stack_b, num);
		ft_printf("pb\n");
	}
}
