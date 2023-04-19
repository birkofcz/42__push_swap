/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array_with_size_imoplementation.c.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:15:39 by sbenes            #+#    #+#             */
/*   Updated: 2023/03/25 17:07:11 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Stack implemenation using int array - this version is using stack[0] index as a holder for array size information*/
#include "../include/push_swap.h"
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
int	*ft_push(int *stack, int num, int argc)
{
	static int index = 1; // initialize index to 1 to store the size at stack[0]

	if (index == argc) // check if stack is full
	{
		printf("Stack overflow!\n");
		return (0);
	}
	stack[0] = argc - 1; // store the size of the array
	stack[index] = num; // push the number onto the stack
	index++; // increment the index
	return (stack); // returns the modified stack
}

void	ft_printstack(int *stack)
{
	int size;
	int i;

	i = 1;
	size = stack[0];
	while (size > 0)
	{
		printf("%d\n", stack[i]);
		size--;
		i++;
	}
	printf("--\nStack A\n");
}

int main(int argc, char *argv[])
{
	int *stack_a;
	int i;
	int num;

	stack_a = (int *)malloc(argc * sizeof(int));
	i = 1;
	if (argc < 2)
	{
		printf("Error. Please provide some numbers to sort!\n");
		return (1);
	}
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		ft_push(stack_a, num, argc);
		i++;
	}
	ft_printstack(stack_a);
	ft_sa(stack_a);
	ft_printstack(stack_a);
	free(stack_a);
	return (0);
}

/* TEST OPERATIONS */

int	*ft_sa(int *stack)
{
	int temp;
	
	temp = stack[1];
	stack[1] = stack[2];
	stack[2] = temp;
	return (stack);
}
