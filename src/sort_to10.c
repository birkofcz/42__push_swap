/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:48:22 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/19 15:19:23 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Functions to sort up to 10 numbers - optimized*/

void	ft_sort2(s_stack *stack_a)
{
	int	a;
	int	b;

	a = stack_a->data[1];
	b = stack_a->data[0];
	if (a > b)
		ft_sa(stack_a);
}

void	ft_sort3(s_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->data[2];
	b = stack_a->data[1];
	c = stack_a->data[0];
	if (a > b && b > c)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
	}
	else if (a > b && b < c && a > c)
		ft_ra(stack_a);
	else if (a < b && b > c && a > c)
		ft_rra(stack_a);
	else if (a > b && b < c)
		ft_sa(stack_a);
	else if (a < b && b > c)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
}

void	ft_sort4(s_stack *stack_a, s_stack *stack_b)
{
	ft_mintotop(stack_a);
	ft_pb(stack_a, stack_b);
	ft_sort3(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort5(s_stack *stack_a, s_stack *stack_b)
{
	ft_mintotop(stack_a);
	ft_pb(stack_a, stack_b);
	ft_mintotop(stack_a);
	ft_pb(stack_a, stack_b);
	ft_sort3(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_sort10(s_stack *stack_a, s_stack *stack_b)
{
	int	i;
	int	half;
	int	is_odd;

	i = stack_a->top + 1;
	half = i / 2;
	is_odd = i % 2;
	while (i != half)
	{
		ft_mintotop(stack_a);
		ft_pb(stack_a, stack_b);
		i--;
	}
	if (half == 3)
		ft_sort3(stack_a);
	else if (half == 4)
		ft_sort4(stack_a, stack_b);
	else if (half == 5)
		ft_sort5(stack_a, stack_b);
	while (half-- != 0)
		ft_pa(stack_a, stack_b);
	if (is_odd)
		ft_pa(stack_a, stack_b);
}
