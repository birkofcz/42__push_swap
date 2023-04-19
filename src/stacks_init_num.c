/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:28:27 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/19 16:33:08 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* STACK INITILIZATOR (NUMBERS AS ARGUMENTS)- initiates stack_a and stack_b with 
size = (argc - 1) (number of arguments, numbers) */

int	*ft_array_from_num(int *array, char *argv[], int argc)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	array = (int *)malloc(argc * sizeof(int));
	while (argv[i] != NULL)
	{
		array[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (array);
}

/* int	ft_stackinit_numbers(t_stack *stack_a, t_stack *stack_b, char *argv[], int argc)
{
	int	size;
	int	num;
	int	*array = NULL;

	size = argc - 1;
	num = 0;
	if (ft_splitted_test(argv + 1) == 0)
	{
		array = ft_array_from_num(array, argv, argc - 1);
		ft_bubble_sort(array, size);
		if ((ft_duplicate_limits_tester(array, size)) == 0)
		{
			free(array);
			ft_stacks(stack_a, stack_b, size);
			while (size > 0)
			{
				num = ft_atoi(argv[size]);
				ft_push(stack_a, num);
				size--;
			}
			return (0);
		}
		else
		{
			free(array);
			return (1);
		}
	}
	else
		return (1);
} */

/* shorter version - NORM friendly */
int	ft_stackinit_numbers(t_stack *stack_a, t_stack *stack_b, char *argv[], int argc)
{
	int size;
	int num;
	int *array;

    if (ft_splitted_test(argv + 1) != 0)
        return (1);
    size = argc - 1;
    array = ft_array_from_num(NULL, argv, size);
    if (array == NULL)
        return (1);
    ft_bubble_sort(array, size);
    if (ft_duplicate_limits_tester(array, size) != 0)
    {
        free(array);
        return (1);
    }
    ft_stacks(stack_a, stack_b, size);
	num = 0;
    while (size--)
	{
		num = ft_atoi(argv[size + 1]);
        ft_push(stack_a, num);
	}
    free(array);
    return (0);
}
