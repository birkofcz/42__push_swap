/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_double_bubble.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 07:41:19 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/13 09:47:30 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


static int	*ft_bubble_sort(int array[], int size)
{
   int i;
   int j;
   int temp;
   int swapped;

	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < (size - i - 1))
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break;
		i++;
	}
	return (array);
}

int	ft_findpivot(s_stack *stack_a)
{
	int *temp_array;
	int i;
	int	j;

	i = 0;
	j = 0;
	temp_array = (int *)malloc(stack_a->size * sizeof(int));
	while (i < stack_a->size)
		temp_array[i++] = stack_a->data[j++];
	ft_bubble_sort(temp_array, stack_a->size);
	i = stack_a->size / 2;
	j = temp_array[i];
	free(temp_array);
	return (j);
}

int	ft_splitstacks(s_stack *stack_a, s_stack *stack_b, int pivot)
{
	int count;
    int pushed;
	int i;

	count = 0;
	pushed = 0;
	i = stack_a->top;

	while (i >= 0)
	{
		if (stack_a->data[i] < pivot)
			count++;
		i--;
	}
    while (pushed != count)
    {
        if (stack_a->data[stack_a->top] < pivot)
        {
            ft_pb(stack_a, stack_b);
            pushed++;
        }
        else
        {
            ft_ra(stack_a);
        }
    }
    return (pushed);
}

int ft_is_sorted_a(s_stack *stack_a)
{
	int	i;
	
	i = stack_a->top;
	while (i > 0)
	{
		if (stack_a->data[i] > stack_a->data[i - 1])
			return (0);
		i--;
	}
	return (1);
} 

int ft_is_sorted_b(s_stack *stack_b)
{
	int	i;

	i = stack_b->top;
	while (i > 0)
	{
		if (stack_b->data[i] < stack_b->data[i - 1])
			return (0);
		i--;
	}
	return (1);
} 

void ft_sorting_both(s_stack *stack_a, s_stack *stack_b)
{
	if (stack_a->data[stack_a->top] < stack_a->data[stack_a->top - 1] && stack_b->data[stack_b->top] < stack_b->data[stack_b->top - 1])
	{
		ft_sb(stack_b);
		ft_rr(stack_a, stack_b);
		ft_rb(stack_b);
	}
	else if (stack_a->data[stack_b->top] > stack_a->data[stack_a->top - 1] && stack_b->data[stack_b->top] < stack_b->data[stack_b->top - 1])
	{
		ft_sa(stack_a);
		ft_sb(stack_b);
		ft_rr(stack_a, stack_b);
		ft_rr(stack_a, stack_b);
	}
	else if (stack_b->data[stack_b->top] > stack_b->data[stack_b->top - 1] && stack_b->data[stack_b->top] > stack_b->data[stack_b->top - 1])
	{
		ft_sa(stack_a);
		ft_rr(stack_a, stack_b);
		ft_ra(stack_a);
	}
	else if (stack_b->data[stack_b->top] < stack_b->data[stack_b->top - 1] && stack_b->data[stack_b->top] > stack_b->data[stack_b->top - 1])
	{
		ft_rr(stack_a, stack_b);
		ft_rr(stack_a, stack_b);
	}
} 

void ft_sorting_a(s_stack *stack_a)
{
	int sorted;

	sorted = ft_is_sorted_a(stack_a);
	while (sorted == 0)
	{
		if (stack_a->data[stack_a->top] > stack_a->data[stack_a->top - 1])
		{
			ft_sa(stack_a);
			ft_ra(stack_a);
			ft_ra(stack_a);
			sorted = ft_is_sorted_a(stack_a);
		}
		else if (stack_a->data[stack_a->top] < stack_a->data[stack_a->top - 1])
		{
			ft_ra(stack_a);
			sorted = ft_is_sorted_a(stack_a);
		}
	}
}

/* void ft_sorting_b(s_stack *stack_b)
{
	if (stack_b->data[stack_b->top] < stack_b->data[stack_b->top - 1])
	{
		ft_sb(stack_b);
		ft_rb(stack_b);
		ft_rb(stack_b);
	}
	else if (stack_b->data[stack_b->top] > stack_b->data[stack_b->top - 1])
		ft_rb(stack_b);
} */
void ft_sorting_b(s_stack *stack_b)
{
	int sorted;

	sorted = ft_is_sorted_b(stack_b);
	while (sorted == 0)
	{
		if (stack_b->data[stack_b->top] > stack_b->data[stack_b->top - 1])
		{
			ft_sb(stack_b);
			ft_rb(stack_b);
			ft_rb(stack_b);
			sorted = ft_is_sorted_b(stack_b);
		}
		else if (stack_b->data[stack_b->top] < stack_b->data[stack_b->top - 1])
		{
			ft_rb(stack_b);
			sorted = ft_is_sorted_a(stack_b);
		}
	}
}
void ft_rotatus_maximus(s_stack *stack_a, s_stack *stack_b)
{
	if (ft_is_sorted_a(stack_a) == 0 && ft_is_sorted_b(stack_b) == 0)
			ft_sorting_both(stack_a, stack_b);
	else if (ft_is_sorted_a(stack_a) == 0 && ft_is_sorted_b(stack_b) == 1)
			ft_sorting_a(stack_a);
	else if (ft_is_sorted_a(stack_a) == 1 && ft_is_sorted_b(stack_b) == 0)
		ft_sorting_b(stack_b); 
	//else if (ft_is_sorted_b(stack_b) == 0)
		//ft_sorting_b(stack_b);
/* 	if (sorted == 0)
	{
		if (ft_is_sorted_b(stack_b) == 0)
			ft_sorting_b(stack_b);
		else
			sorted = 1;
	}
	ft_mintotop(stack_a);
	ft_pb(stack_a, stack_b);
	if (sorted == 1)
	{
		if(ft_is_sorted_b(stack_b) == 0)
			ft_sorting_a(stack_a);
		else
			sorted = 2;
	} */
		
	
}

/* 	i = 0;
	while (i < b_size)
	{
		ft_pa(stack_a, stack_b);
		i++;
	}
}  */



void	ft_double_bubble(s_stack *stack_a, s_stack *stack_b)
{
	int pivot;
	int a_size;
	int b_size;

	pivot = ft_findpivot(stack_a);
	ft_printf("%d\n", pivot);
	ft_printstacks(stack_a, stack_b);
	b_size = ft_splitstacks(stack_a, stack_b, pivot);
	a_size = b_size + 1;
	ft_printf("%d .... %d\n", a_size, b_size);
	ft_printstacks(stack_a, stack_b);
	ft_rotatus_maximus(stack_a, stack_b);
	ft_printstacks(stack_a, stack_b);
	
}

