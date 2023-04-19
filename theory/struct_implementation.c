/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_implementation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:02:36 by sbenes            #+#    #+#             */
/*   Updated: 2023/03/26 15:26:36 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Implementation of stack using struct */

#include "../include/push_swap.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int		*data;
	int		top;
	int		size;
} s_stack;

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

void	ft_stackinit(s_stack *stack_a, s_stack *stack_b, int size)
{
	stack_a->data = (int*) malloc(size * sizeof(int));
	stack_a->top = -1;
	stack_a->size = size;
	stack_b->data = (int*) malloc(size * sizeof(int));
	stack_b->top = -1;
	stack_b->size = size;
}

void	ft_push(s_stack *stack, int num)
{
	if (stack->top == stack->size - 1)
	{
		printf("Stack overflow!\n");
		return;
	}
	stack->data[++stack->top] = num;
}

int	ft_pop(s_stack *stack)
{
	if (stack->top == -1)
	{
		printf("Stack underflow!\n");
		return -1;
	}
	return (stack->data[stack->top--]);
}


void ft_printstacks(s_stack *stack_a, s_stack *stack_b)
{
    int i;

    i = 0;
    printf("\n");
    while (i < stack_a->size || i < stack_b->size)
    {
        if (i <= stack_a->top)
        {
            printf("%d", stack_a->data[stack_a->top - i]);
        }
        else
        {
            printf(" ");
        }
        printf("\t\t");
        if (i <= stack_b->top)
        {
            printf("%d", stack_b->data[stack_b->top - i]);
        }
        else
        {
            printf(" ");
        }
        printf("\n");
        i++;
    }
    printf("---\t\t---\nstack_a\t\tstack_b\n");
    printf("\n");
}

void ft_printstackshor(s_stack *stack_a, s_stack *stack_b)
{
    int i;

    printf("\nstack_a = [");
    for (i = 0; i < stack_a->size; i++)
    {
        if (i <= stack_a->top)
        {
            printf("%d", stack_a->data[stack_a->top - i]);
        }
        else
        {
            printf(" ");
        }

        if (i < stack_a->size - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");

    printf("stack_b = [");
    for (i = 0; i < stack_b->size; i++)
    {
        if (i <= stack_b->top)
        {
            printf("%d", stack_b->data[stack_b->top - i]);
        }
        else
        {
            printf(" ");
        }

        if (i < stack_b->size - 1)
        {
            printf(", ");
        }
    }
    printf("]\n\n");
}




int	main(int argc, char *argv[])
{
	s_stack	stack_a;
	s_stack	stack_b;
	int i;
	int num;

	i = argc -1;
	if (argc < 2)
	{
		printf("Error. Please provide some numbers to sort!\n");
		return (1);
	}
	ft_stackinit(&stack_a, &stack_b, (argc -1));
	while (i > 0)
	{
		num = ft_atoi(argv[i]);
		ft_push(&stack_a, num);
		i--;
	}
	ft_printstacks(&stack_a, &stack_b); //for visualisation control
	ft_pop(&stack_a);
	ft_push(&stack_b, 1);
	ft_printstacks(&stack_a, &stack_b); //for visualisation control
	ft_pop(&stack_b);
	ft_push(&stack_a, 1);
	ft_printstacks(&stack_a, &stack_b); //for visualisation control
	ft_printstackshor(&stack_a, &stack_b);

	return (0);
}
