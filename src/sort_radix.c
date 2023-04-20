/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:53:59 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/20 09:17:49 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* int	*ft_create_indexes(t_stack *stack_a)
{
	int	*indexes;
	int	*temp;
	int	i;
	int	j;

	indexes = (int *)malloc(stack_a->size * sizeof(int));
	temp = (int *)malloc(stack_a->size * sizeof(int));
	i = 0;
	j = 0;
	while (i < stack_a->size)
		temp[i++] = stack_a->data[j++];
	ft_bubble_sort(temp, stack_a->size);
	i = 0;
	while (i < stack_a->size)
	{
		j = 0;
		while (j < stack_a->size)
		{
			if (stack_a->data[i] == temp[j]) 
			{
				indexes[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
	free(temp);
	print_indexes(indexes, stack_a->size);
	return (indexes);
} */

/* Shorter version - NIRM friendly */

int	*ft_create_indexes(t_stack *stack_a)
{
	int	*indexes;
	int	*temp;
	int	i;
	int	j;

	indexes = (int *)malloc(stack_a->size * sizeof(int));
	temp = (int *)malloc(stack_a->size * sizeof(int));
	i = 0;
	j = 0;
	while (i < stack_a->size)
		temp[i++] = stack_a->data[j++];
	ft_bubble_sort(temp, stack_a->size);
	i = -1;
	while (++i < stack_a->size)
	{
		j = -1;
		while (++j < stack_a->size)
			if (stack_a->data[i] == temp[j]) 
				indexes[i] = j + 1;
	}
	free(temp);
	return (indexes);
} 

void	ft_sort_radix(t_stack *indexes_a, t_stack *indexes_b)
{
	t_radix_data	data;

	ft_radix_data_init(&data, indexes_a, indexes_b);
	ft_count_bits(&data, indexes_a);
	data.i = 0;
	while (data.i < data.max_bits)
	{
		data.j = 0;
		while (data.j < data.size_original)
		{
			data.top_number = indexes_a->data[indexes_a->top];
			if (((data.top_number >> data.i) & 1) == 1)
				ft_ra(indexes_a);
			else
			{
				ft_pb(indexes_a, indexes_b);
				data.size_a--;
				data.size_b++;
			}
			data.j++;
		}
		while (data.size_b != 0)
			ft_radix_pushback(&data, indexes_a, indexes_b);
		data.i++;
	}
}

void	ft_radix(t_stack *stack_a)
{
	int		*indexes;
	t_stack	indexes_a;
	t_stack	indexes_b;
	int		i;
	int		j;

	indexes = ft_create_indexes(stack_a);
	indexes_a.data = malloc(stack_a->size * sizeof(int));
	indexes_a.size = stack_a->size;
	indexes_a.top = stack_a->top;
	indexes_b.data = malloc(stack_a->size * sizeof(int));
	indexes_b.size = stack_a->size;
	indexes_b.top = -1;
	i = 0;
	j = 0;
	while (i < stack_a->size)
		indexes_a.data[i++] = indexes[j++];
	ft_sort_radix(&indexes_a, &indexes_b);
	ft_free_stacks(&indexes_a, &indexes_b);
}