/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotatus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:37:00 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/13 16:02:43 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_is_sorted(int array[], int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if(array[i] < array[i + 1])
		{
			printf("\033[31mArray is NOT sorted\033[0m\n");
			return ;
		}
		i++;
	}
	printf("\033[32mArray IS sorted\033[0m\n");
}

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

int	*ft_reference_array(s_stack *stack_a, int size_a)
{
	int	*array;
	int	i;
	int	j;

	i = 0;
	j = 0;
	array = (int *)malloc(size_a * sizeof(int));
	if (!array)
	{
		ft_printf("Error allocating reference array\n");
		return (0);
	}
	while (i < size_a)
		array[i++] = stack_a->data[j++];
	/* for reference */
	for (int s = 0; s < size_a ; s++) {
        ft_printf("%d ", array[s]);  // print each element of the array
    	}
	ft_bubble_sort(array, size_a);
	ft_printf("\nThe size of array is: %d\n", size_a);
	return (array);
}

int ft_findindex(s_stack *stack_a, int number)
{
	int index;
	int i;
	
	index = -1;
	i = stack_a->top;
	while (i >= 0)
	{
		if (stack_a->data[i] == number)
		{
			index = i;
			break;
		}
		i--;
	}
	return (index);
}

int	ft_calculate(int array[], s_stack *stack_a)
{
	int	index_first;
	int index_second;
	int num_one;
	int num_second;
	int half_stack;

	num_one = array[0];
	num_second = array[1];
	ft_printf("\nthe first number is: %d\n", num_one);
	ft_printf("the second number is: %d\n", num_second);
	ft_printf("stack_a top is : %d", stack_a->top);
	half_stack = stack_a->size / 2;
	index_first = ft_findindex(stack_a, num_one);
	index_second = ft_findindex(stack_a, num_second);
	if (index_first == 0)
		return (index_first);
	else if (index_second == 0)
		return (index_second);
	else if (index_first >= half_stack && index_first > index_second)
		return (index_first);
	else if (index_second >= half_stack && index_second >= index_first)
		return (index_second);
	else if (index_first < half_stack && index_first < index_second)
		{ft_printf("index_first < half_stack && index_first < index_second");
		return (index_first);}
	else if (index_second < half_stack && index_second <= index_first)
		{ft_printf("halfstack is %d", half_stack);
		ft_printf("index_second < half_stack && index_second <= index_first");
		return (index_second);}
	else
		return (0);
}

/* Check the number being pushed adn rotate minimum number from stack_b to the top */
void	ft_adjust_b(s_stack *stack_b)
{
	ft_findminindex(stack_b);
	ft_mintotop(stack_b);
}

/* void	ft_push_a(s_stack *stack_a, s_stack *stack_b, int index_to_push)
{
	int half_stack;

	while (index_to_push != stack_a->top)
	{
		half_stack = (stack_a->top + 1) / 2; 
		if (index_to_push >= half_stack) 
			ft_ra(stack_a);
		else if (index_to_push < half_stack)
			ft_rra(stack_a);
	}
	ft_pb(stack_a, stack_b);
} */

/* void	ft_indextotop(s_stack *stack_a, int index_to_push)
{
	int half_stack;

	while (index_to_push != stack_a->top)
	{
		half_stack = (stack_a->top + 1) / 2; 
		if (index_to_push >= half_stack)
		{
			ft_ra(stack_a);
			index_to_push++;
		}
		else if (index_to_push < half_stack)
		{
			if (index_to_push == 0)
			{
				ft_rra(stack_a);
				index_to_push = stack_a->top;
			}
			else
			{
				ft_rra(stack_a);
				index_to_push--;
			}

		}
	}
}
 */

void	ft_indextotop(s_stack *stack_a, int index_to_push)
{
    int half_stack;

	half_stack = (stack_a->top + 1) / 2;
	if (index_to_push == stack_a->top)
		return ;
	else
	{
        	if (index_to_push >= half_stack)
        	{
            	ft_ra(stack_a);
            	index_to_push++;
        	}
        	else if (index_to_push < half_stack)
        	{
            	ft_rra(stack_a);
            	if (index_to_push == 0 && stack_a->top > 0)
                	index_to_push = stack_a->top;
            	else
                	index_to_push--;
        }
    }
}



void	ft_sort_rotatus(s_stack *stack_a, s_stack *stack_b)
{
	int *reference_array;
	int index_to_push;
	int size_a;
	int size_b;

	ft_printstacks(stack_a, stack_b);
	size_a = stack_a->size;
	size_b = 0;
	while (size_a != 0)
	{
		ft_printf("Stack size: %d\n", stack_a->size);
		reference_array = ft_reference_array(stack_a, size_a);
		ft_printf("ref array created\n");
		ft_printf("The array is: ");
    	for (int i = 0; i < size_a; i++) {
        ft_printf("%d ", reference_array[i]);  // print each element of the array
    	}
		index_to_push = ft_calculate(reference_array, stack_a);
		ft_printf("\nIndex to push calculated: %d\n", index_to_push);
		ft_adjust_b(stack_b); //ajust b
		ft_printf("B adjusted before push\n");
		ft_indextotop(stack_a, index_to_push);
		ft_printf("index is pushed to top\n");
		ft_printstacks(stack_a, stack_b); //push a
		ft_pb(stack_a, stack_b);
		size_a--;
		size_b++;
		ft_printstacks(stack_a, stack_b);
		free(reference_array); //adjust reference array
	}

		/* second run */
		/* ft_printf("Stack size: %d\n", stack_a->size);
		reference_array = ft_reference_array(stack_a);
		ft_printf("ref array created\n");
		ft_printf("The array is: ");
    	for (int i = 0; i < stack_a->size; i++) {
        ft_printf("%d ", reference_array[i]);  // print each element of the array
    	}
		index_to_push = ft_calculate(reference_array, stack_a);
		ft_printf("\nIndex to push calculated: %d\n", index_to_push);
		ft_adjust_b(stack_b); //ajust b
		ft_printf("B adjusted before push\n");
		ft_indextotop(stack_a, index_to_push);
		ft_printf("index is pushed to top\n");
		ft_printstacks(stack_a, stack_b); //push a
		ft_pb(stack_a, stack_b);
		pushed_number = stack_b->top;
		ft_printstacks(stack_a, stack_b);
		free(reference_array); */

		/* third run */
		/* ft_printf("Stack size: %d\n", stack_a->size);
		reference_array = ft_reference_array(stack_a);
		ft_printf("ref array created\n");
		ft_printf("The array is: ");
    	for (int i = 0; i < stack_a->size; i++) {
        ft_printf("%d ", reference_array[i]);  // print each element of the array
    	}
		index_to_push = ft_calculate(reference_array, stack_a);
		ft_printf("\nIndex to push calculated: %d\n", index_to_push);
		ft_adjust_b(stack_b); //ajust b
		ft_printf("B adjusted before push\n");
		ft_indextotop(stack_a, index_to_push);
		ft_printf("index is pushed to top\n");
		ft_printstacks(stack_a, stack_b); //push a
		ft_pb(stack_a, stack_b);
		pushed_number = stack_b->top;
		ft_printstacks(stack_a, stack_b);
		free(reference_array);  */
	//}//repeat;
	while (size_b != 0)
	{
		ft_findmaxindex(stack_b);
		ft_maxtotop(stack_b);
		ft_pa(stack_a, stack_b);
		size_b--;
		size_a++;
	}
	ft_printstacks(stack_a, stack_b);
	ft_is_sorted(stack_a->data, size_a);
	ft_printf("stack_a size: %d\n", size_a);
	ft_printf("stack_b size: %d\n", size_b);

}
