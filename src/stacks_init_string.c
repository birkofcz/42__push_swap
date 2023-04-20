/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:28:27 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/20 11:55:52 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* STACK INITILIZATOR - initiates stack_a and stack_b with 
parsed string */

void	ft_free_splitted(char *splitted[])
{
	int	i;

	i = 0;
	while (splitted[i] != NULL)
		free(splitted[i++]);
	free(splitted);
}

void	ft_free_all(char *splitted[], t_stack *s_a, t_stack *s_b, int *array)
{
	int	i;

	i = 0;
	while (splitted[i] != NULL)
		free(splitted[i++]);
	free(splitted);
	free(array);
	ft_free_stacks(s_a, s_b);
}

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
			ft_free_all(splitted, stack_a, stack_b, array);
			return (1);
		}
		free(array);
		ft_free_splitted(splitted);
		return (0);
	}
	ft_free_splitted(splitted);
	return (1);
}
