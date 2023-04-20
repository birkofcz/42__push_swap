/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:28:27 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/20 11:05:42 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* STACK INITILIZATOR (NUMBERS AS ARGUMENTS)- initiates stack_a and stack_b 
with size = (argc - 1) (number of arguments, numbers) */

long long	ft_atoi_sort(const char *str)
{
	int	sign;
	long long	output;

	sign = 1;
	output = 0;
	while (*str == '\f' || *str == '\n' || *str == '\r' || *str == '\t'
		|| *str == '\v' || *str == ' ')
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		output = output * 10 + (*str - '0');
		str++;
	}
	return (output * sign);
}

int	ft_limit_test(char *test)
{
	long long 	x;

	x = ft_atoi_sort(test);
	if (x < INT_MIN || x > INT_MAX)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	*ft_array_from_num(int *array, char *argv[], int argc)
{
	int	i;
	int	j;
	long long int	x;

	i = 1;
	j = 0;
	array = (int *)malloc(argc * sizeof(int));
	while (argv[i] != NULL)
	{
		x = ft_atoi_sort(argv[i]);
		if (x < INT_MIN || x > INT_MAX)
		{
			write(2, "Error", 6);
			return (NULL);
		}
		else
		{
			array[j] = ft_atoi(argv[i]);
			i++;
			j++;
		}
	}
	return (array);
}

/* shorter version - NORM friendly */
int	ft_stackinit_numbers(t_stack *s_a, t_stack *s_b, char *v[], int c)
{
	int	size;
	int	num;
	int	*array;

	if (ft_splitted_test(v + 1) != 0)
		return (1);
	size = c - 1;
	array = ft_array_from_num(NULL, v, size);
	if (array == NULL)
		return (1);
	ft_bubble_sort(array, size);
	if (ft_duplicate_limits_tester(array, size) != 0)
	{
		free(array);
		return (1);
	}
	ft_stacks(s_a, s_b, size);
	num = 0;
	while (size--)
	{
		num = ft_atoi(v[size + 1]);
		ft_push(s_a, num);
	}
	free(array);
	return (0);
}
