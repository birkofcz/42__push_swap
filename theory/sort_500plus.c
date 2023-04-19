/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:31:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/09 11:31:50 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_sort500(s_stack *stack_a, s_stack *stack_b)
{
    int i;
    int half;
    int is_odd;

    i = stack_a->top + 1;
    if (i <= 250)
        ft_sort250(stack_a, stack_b);
    else
    {
        half = i / 2;
        is_odd = i % 2;
        while (i != half)
        {
            ft_mintotop(stack_a);
            ft_pb(stack_a, stack_b);
            i--;
        }
        ft_sort500(stack_a, stack_b);
        ft_sort_descending(stack_a, stack_b);
        while (half-- != 0)
            ft_pa(stack_a, stack_b);
        if (is_odd)
            ft_pa(stack_a, stack_b);
    }
}