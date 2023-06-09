/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:22:05 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/21 14:32:20 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Utility functions for stack initilaization - splitting, filling arrays, 
checking for wrong input an duplicates, creating and freeing stacks */

/* Test the splitted array - are there only "numeric" strings? If not, 
return error */

int	ft_splitted_test(char *splitted[])
{
	int	i;
	int	j;

	i = 0;
	while (splitted[i] != NULL)
	{
		j = 0;
		if (splitted[i][j] == '-')
			j++;
		while (splitted[i][j])
		{
			if (splitted[i][j] < '0' || splitted[i][j] > '9')
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}	
		i++;
	}
	i = 0;
	while (splitted[i] != NULL)
		if (ft_limit_test(splitted[i++]) == 1)
			return (1);
	return (0);
}

int	ft_array_filler(int **array, char *splitted[])
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = ft_get_size(splitted);
	*array = (int *)malloc(size * sizeof(int));
	while (splitted[i] != NULL)
	{
		(*array)[j] = ft_atoi(splitted[i]);
		i++;
		j++;
	}
	return (size);
}

/* Creating the actual stack_a and stack_b */

void	ft_stacks(t_stack *stack_a, t_stack *stack_b, int size)
{
	stack_a->data = (int *)malloc(size * sizeof(int));
	if (!stack_a->data)
	{
		write(2, "Error\n", 6);
		return ;
	}
	stack_a->top = -1;
	stack_a->size = size;
	stack_b->data = (int *)malloc(size * sizeof(int));
	if (!stack_b->data)
	{
		write(2, "Error\n", 6);
		return ;
	}
	stack_b->top = -1;
	stack_b->size = size;
}

/* Testing for duplicate numbers */

int	ft_duplicate_limits_tester(int array[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == array[i + 1])
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

/* Measuring the size of *splitted[] */

int	ft_get_size(char *splitted[])
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (splitted[i++] != NULL)
		size++;
	return (size);
}
