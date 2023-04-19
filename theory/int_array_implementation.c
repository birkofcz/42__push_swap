/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array_implementation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:15:39 by sbenes            #+#    #+#             */
/*   Updated: 2023/03/27 14:31:02 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Stack implemenation using int array */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int	*ft_sa(int *stack);

int	ft_atoi(const char *str)
{
	int	sign;
	int	output;

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

int	ft_push(int *stack, int num, int argc)
{
	static int index = -1; // initialize top to -1 for the first push operation
	
	if (index == argc - 2) // check if stack is full
	{
		printf("Stack overflow!\n");
		return (0);
	}
	index++;
	stack[index] = num; // push the number onto the top of the stack
	return (index); //returns index of the last number
}

void	ft_printstack(int *stack, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		printf("%d\n", stack[i]);
		i++;
	}
	printf("--\nStack A\n");
}

int main(int argc, char *argv[])
{
	int *stack_a;
	int i;
	int num;
	int	size;

	stack_a = (int *)malloc((argc - 1) / sizeof(int));
	i = 1;
	if (argc < 2)
	{
		printf("Error. Please provide some numbers to sort!\n");
		return (1);
	}
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		size = ft_push(stack_a, num, argc);
		i++;
	}
	ft_printstack(stack_a, size);
	ft_sa(stack_a);
	ft_printstack(stack_a, size);
	printf("size of stack: %d\n", size + 1);
	free(stack_a);
	return (0);
}

/* TEST OPERATIONS */

int	*ft_sa(int *stack)
{
	int temp;
	
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	return (stack);
}
