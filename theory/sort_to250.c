/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to250.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:49:09 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/09 11:34:52 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 

*/

#include "../include/push_swap.h"


void ft_sort_descending(s_stack *stack_a, s_stack *stack_b)
{
	int	i;

	i = stack_a->top + 1;
	while (i-- != 0)
	{
		ft_maxtotop(stack_b);
		ft_pa(stack_a, stack_b);
	}
}


void ft_sort20(s_stack *stack_a, s_stack *stack_b)
{
    int i;
    int half;
    int is_odd;

    i = stack_a->top + 1;
    if (i <= 10)
		ft_sort10(stack_a, stack_b);
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
        ft_sort20(stack_a, stack_b);
        ft_sort_descending(stack_a, stack_b);
        while (half-- != 0)
            ft_pa(stack_a, stack_b);
        if (is_odd)
            ft_pa(stack_a, stack_b);
    }
}

void ft_sort50(s_stack *stack_a, s_stack *stack_b)
{
    int i;
    int half;
    int is_odd;

    i = stack_a->top + 1;
    if (i <= 20)
        ft_sort20(stack_a, stack_b);
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
        ft_sort50(stack_a, stack_b);
        ft_sort_descending(stack_a, stack_b);
        while (half-- != 0)
            ft_pa(stack_a, stack_b);
        if (is_odd)
            ft_pa(stack_a, stack_b);
    }
}

void ft_sort100(s_stack *stack_a, s_stack *stack_b)
{
    int i;
    int half;
    int is_odd;

    i = stack_a->top + 1;
    if (i <= 50)
        ft_sort50(stack_a, stack_b);
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
        ft_sort100(stack_a, stack_b);
        ft_sort_descending(stack_a, stack_b);
        while (half-- != 0)
            ft_pa(stack_a, stack_b);
        if (is_odd)
            ft_pa(stack_a, stack_b);
    }
}

void ft_sort250(s_stack *stack_a, s_stack *stack_b)
{
    int i;
    int half;
    int is_odd;

    i = stack_a->top + 1;
    if (i <= 100)
        ft_sort100(stack_a, stack_b);
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
        ft_sort250(stack_a, stack_b);
        ft_sort_descending(stack_a, stack_b);
        while (half-- != 0)
            ft_pa(stack_a, stack_b);
        if (is_odd)
            ft_pa(stack_a, stack_b);
    }
}
