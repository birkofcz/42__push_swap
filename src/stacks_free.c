/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:25:43 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/19 15:22:12 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Freeing the stacks - where the malloc was used */

void	ft_free_stacks(s_stack *stack_a, s_stack *stack_b)
{
	free(stack_a->data);
	free(stack_b->data);
}
