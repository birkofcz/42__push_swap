/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_crossroad.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:49:58 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/20 08:40:01 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Just a crossroads to various sorting functions depending on input*/

#include "../include/push_swap.h"

void	ft_sortstack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top == 0)
		return ;
	else if (stack_a->top == 1)
		ft_sort2(stack_a);
	else if (stack_a->top == 2)
		ft_sort3(stack_a);
	else if (stack_a->top == 3)
		ft_sort4(stack_a, stack_b);
	else if (stack_a->top == 4)
		ft_sort5(stack_a, stack_b);
	else if (stack_a->top > 4 && stack_a->top < 10)
		ft_sort10(stack_a, stack_b);
	else if (stack_a->top > 9)
		ft_radix(stack_a);
}