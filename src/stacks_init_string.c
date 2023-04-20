/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:28:27 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/20 10:24:26 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* STACK INITILIZATOR - initiates stack_a and stack_b with 
parsed string */

/* int ft_stackinit_string(t_stack *stack_a, t_stack *stack_b, char *argv)
{
	int		size;
	char	**splitted;
	int		*array = NULL;
	int		pushed;

	splitted = ft_split(argv, ' ');
	if (ft_splitted_test(splitted) == 0)
	{
		size = ft_array_filler(&array, splitted);
		ft_stacks(stack_a, stack_b, size);
		pushed = size;
		while (pushed > 0)
		{
			ft_push(stack_a, array[pushed - 1]);
			pushed--;
		}
		ft_bubble_sort(array, size);
		if ((ft_duplicate_limits_tester(array, size)) == 1)
		{
			ft_free_stacks(stack_a, stack_b);
			return (1);
		}
		free(array);
		free(splitted);
		return (0);
	}
	else
		return (1);
} */

/* Shorter version - NORM friendly */
int	ft_stackinit_string(t_stack *stack_a, t_stack *stack_b, char *argv)
{
	int		size;
	char	**splitted;
	int		*array;
	int		pushed;

	splitted = ft_split(argv, ' ');
	if (ft_splitted_test(splitted) == 0)
	{
		size = ft_array_filler(&array, splitted);
		ft_stacks(stack_a, stack_b, size);
		pushed = size;
		while (pushed--)
			ft_push(stack_a, array[pushed]);
		ft_bubble_sort(array, size);
		if ((ft_duplicate_limits_tester(array, size)) == 1)
		{
			ft_free_stacks(stack_a, stack_b);
			return (1);
		}
		free(array);
		free(splitted);
		return (0);
	}
	else
		return (1);
}
