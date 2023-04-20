/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:34:45 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/20 09:40:22 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_findminindex(t_stack *stack_a)
{
	int	index;
	int	i;
	int	min;

	i = stack_a->top;
	index = i;
	min = stack_a->data[i];
	while (i >= 0)
	{
		if (stack_a->data[i] < min)
		{
			min = stack_a->data[i];
			index = i;
		}
		i--;
	}
	return (index);
}

void	ft_mintotop(t_stack *stack_a)
{
	int	min_index;
	int	half_stack;

	while (ft_findminindex(stack_a) != stack_a->top)
	{
		min_index = ft_findminindex(stack_a);
		half_stack = (stack_a->top + 1) / 2;
		if (min_index >= half_stack)
			ft_ra(stack_a);
		else if (min_index < half_stack)
			ft_rra(stack_a);
	}
}

int	ft_findmaxindex(t_stack *stack_b)
{
	int	index;
	int	i;
	int	max;

	i = stack_b->top;
	index = i;
	max = stack_b->data[i];
	while (i >= 0)
	{
		if (stack_b->data[i] > max)
		{
			max = stack_b->data[i];
			index = i;
		}
		i--;
	}
	return (index);
}

void	ft_maxtotop(t_stack *stack_b)
{
	int	max_index;
	int	half_stack;

	while (ft_findmaxindex(stack_b) != stack_b->top)
	{
		max_index = ft_findmaxindex(stack_b);
		half_stack = (stack_b->top + 1) / 2;
		if (max_index >= half_stack)
			ft_rb(stack_b);
		else if (max_index < half_stack)
			ft_rrb(stack_b);
	}
}
