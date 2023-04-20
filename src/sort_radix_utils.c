/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 07:59:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/20 09:18:40 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_radix_data_init(t_radix_data *data, t_stack *indexes_a, t_stack *indexes_b)
{
	data->size_original = indexes_a->size;
	data->size_a = indexes_a->size;
	data->size_b = indexes_b->size;
	data->max_bits = 0;
}

void	ft_count_bits(t_radix_data *data, t_stack *indexes_a)
{
	while ((indexes_a->size >> data->max_bits) != 0)
		data->max_bits++;
}

void	ft_radix_pushback(t_radix_data *data, t_stack *indexes_a, t_stack *indexes_b)
{
			ft_pa(indexes_a, indexes_b);
			data->size_b--;
}