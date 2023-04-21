/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 07:59:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/21 14:21:04 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Utilities for RADIX SORT	- initialising data to struct, counting
bits and pushing the numbers back from stack_b to stack_a */

void	ft_radix_data_init(t_radix_data *d, t_stack *ind_a, t_stack *ind_b)
{
	d->size_original = ind_a->size;
	d->size_a = ind_a->size;
	d->size_b = ind_b->size;
	d->max_bits = 0;
}

void	ft_count_bits(t_radix_data *data, t_stack *indexes_a)
{
	while ((indexes_a->size >> data->max_bits) != 0)
		data->max_bits++;
}

void	ft_radix_pushback(t_radix_data *d, t_stack *ind_a, t_stack *ind_b)
{
	ft_pa(ind_a, ind_b);
	d->size_b--;
}
