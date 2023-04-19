/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_doctor_strange.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 09:44:10 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/16 14:10:51 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_find_price_a(s_stack *stack_a, int index)
{
	int half;
	int count;

	count = 0;
	half = (stack_a->top + 1) / 2;
	if (index == stack_a->top)
		count = 1;
	if (index >= half)
		count = (stack_a->top - index) + 1;
	else if (index < half)
		count = index + 2;
	return (count);
}

int ft_findmaxnum(s_stack *stack_b)
{
	int index;
	int max_number;

	max_number = INT_MIN;
	index = stack_b->top;
	while (index >= 0)
	{
		if (stack_b->data[index] > max_number)
			max_number = stack_b->data[index];
		index--;
	}
	return (max_number);
}

int	ft_findminnum(s_stack *stack_b)
{
	int min_number;
	int index;

	min_number = ft_findmaxnum(stack_b);
	index = stack_b->top;
	while (index >= 0)
	{
		if (stack_b->data[index] < min_number)
			min_number = stack_b->data[index];
		index--;
	}
	return (min_number);
}

int	ft_findproperindex(s_stack *stack_b, int number)
{
	int index;
	int insert_index;

	insert_index = -1;
	index = stack_b->top;
	while (index >= 0)
	{
		if (stack_b->data[index] > number)
			insert_index = index;
		index--;
	}
	return (insert_index);
} 

/* FINDING PRICE FOR B
	Here, we need more information, thus returning int array of size 3.
	if number_a < min || > max - number is GREATER or LESSER than min and max. 
	It should be place above max number.

	price[0] = 0;
	price[1] = 1, rb - rotating up, 2 - rrb, rotating down
	price[2] = actual price (number of moves)

	else if number is somewhere inside, we need to rotate proper index up,
	it needs to be placed above the proper index.
	
	price[0] = 1;
	price[1] = 1, rb - rotate up, 2 - rrb - rotating down
	price[2] = actual price (number of moves)
 */
int	*ft_find_price_b(s_stack *stack_b, int number_a)
{
	int *price;
	int max_number;
	int max_index;
	int min_number;
	int proper_index;

	price = malloc(3 * sizeof(int));
	max_number = ft_findmaxnum(stack_b);
	min_number = ft_findminnum(stack_b);
	max_index = ft_findmaxindex(stack_b);
	if (number_a > max_number || number_a < min_number)
	{
		price[0] = 0;
		if (max_index >= (stack_b->top + 1) / 2)
		{
			price[1] = 1;
			price[2] = stack_b->top - max_index;
		}
		else if (max_index < (stack_b->top + 1 / 2))
		{
			price[1] = 2;
			price[2] = max_index + 1;
		}
	}
	else if (number_a < max_number && number_a > min_number)
	{
		price[0] = 1;
		proper_index = ft_findproperindex(stack_b, number_a);
		if (proper_index >= (stack_b->top + 1) / 2)
		{
			price[1] = 1;
			price[2] = stack_b->top - proper_index;
		}
		else if (proper_index < (stack_b->top + 1 / 2))
		{
			price[1] = 2;	
			price[2] = proper_index + 1;
		}
	}
	return (price);
}

/* Total price calculation - takes prices for a and b and in there are possible moves 
for both stack in one move; it will substract it from the price */
int	ft_total_price(s_stack *stack_a, s_stack *stack_b, int index, int number_a)
{
	int price_a;
	int *price_b;
	int price_both;
	int total_price;

	price_both = 0;
	price_a = ft_find_price_a(stack_a, index);
	price_b = ft_find_price_b(stack_b, number_a);
	while (/* price_a > 1 ||  */price_b[2] > 0)
	{
		price_both++;
		price_a--;
		price_b[2]--;
	}
	price_a = ft_find_price_a(stack_a, index);
	price_b = ft_find_price_b(stack_b, number_a); 
	total_price = (price_a + price_b[2]) - price_both;
	free(price_b);
	return (total_price);
}

/* FT_MOVE_NUMBER - move the cheapest number to stack_b, into its proper place,
using cheapest way - doing rotation for both if possible */
void	ft_move_number(s_stack *stack_a, s_stack *stack_b, int cheapest_index, int number_a)
{
	int	price_a;
	int *price_b;
	int proper_index_b;
	int max_number;
	int min_number;

	price_a = ft_find_price_a(stack_a, cheapest_index);
	price_b = ft_find_price_b(stack_b, number_a);
	max_number = ft_findmaxnum(stack_b);
	min_number = ft_findminnum(stack_b);
	while (price_a > 1 && price_b[2] > 0)
	{
		if (cheapest_index >= (stack_a->top + 1) / 2 && price_b[1] == 1)
			ft_rr(stack_a, stack_b);
		else if (cheapest_index < (stack_a->top + 1) / 2 && price_b[1] == 2)
			ft_rrr(stack_a, stack_b);
	}
	while (cheapest_index != stack_a->top)
	{
		if (cheapest_index >= (stack_a->top + 1) / 2)
			ft_ra(stack_a);
		else if (cheapest_index < (stack_a->top + 1) / 2)
			ft_rra(stack_a);
	}
	if (number_a > max_number || number_a < min_number)
			ft_maxtotop(stack_b);
	else if (number_a < max_number && number_a > min_number)
	{
		proper_index_b = ft_findproperindex(stack_b, number_a);
		while (proper_index_b != stack_b->top)
		{
			ft_printf("Proper number index is %d\n", proper_index_b);
			if (proper_index_b >= (stack_b->top + 1) / 2)
				ft_rb(stack_b);
			else if (proper_index_b < (stack_b->top + 1) / 2)
				ft_rrb(stack_b);
			proper_index_b = ft_findproperindex(stack_b, number_a);
		} 
	}
	ft_pb(stack_a, stack_b);
	free(price_b);
}
/* FT_DOCTOR_STRANGE
	My variation on Mechanical Turk algorithm, which calculates the price of 
	moving to proper place in stack_b for every number in stack_a. Same as
	Doctor Strange, who can see all the possible futures. It starts with pushing 
	first two numbers to b. After it calculates, it moves the selected number 
	to stack_b - using the most optimal way (I certainly hope so!). Doing so, until 
	there is only 3 numbers left in stack_a (they can be sorted in-place very effectively
	using ft_sort3 algorithm).
 */
void	ft_doctor_strange(s_stack *stack_a, s_stack *stack_b)
{
	int index;
	int total_price;
	int price_temp;
	int number_a;
	int cheapest_index;

	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	index = stack_a->top;
	cheapest_index = stack_a->top;
	price_temp = INT_MAX;
	while (index >= 0)
	{
		number_a = stack_a->data[index];
		//total_price = (ft_find_price_a(stack_a, index) + ft_find_price_b(stack_b, number_a));
		total_price = ft_total_price(stack_a, stack_b, index, number_a);
		if (total_price < price_temp)
		{
			cheapest_index = index;
			price_temp = total_price;
		}
		ft_printf("Price for number %d: %d\n", stack_a->data[index], total_price);
		ft_printf("The proper index is %d\n", ft_findproperindex(stack_b, number_a));
		index--;  
	}
	ft_printf("Cheapest number to move is %d on index %d\n", stack_a->data[cheapest_index], cheapest_index);
	ft_move_number(stack_a, stack_b, cheapest_index, stack_a->data[cheapest_index]);
	ft_printstacks(stack_a, stack_b);
	/* round  2 */
		index = stack_a->top;
	cheapest_index = stack_a->top;
	price_temp = INT_MAX;
	while (index >= 0)
	{
		number_a = stack_a->data[index];
		//total_price = (ft_find_price_a(stack_a, index) + ft_find_price_b(stack_b, number_a));
		total_price = ft_total_price(stack_a, stack_b, index, number_a);
		if (total_price < price_temp)
		{
			cheapest_index = index;
			price_temp = total_price;
		}
		ft_printf("Price for number %d: %d\n", stack_a->data[index], total_price);
		ft_printf("The proper index is %d\n", ft_findproperindex(stack_b, number_a));
		index--;  
	}
	ft_printf("Cheapest number to move is %d on index %d\n", stack_a->data[cheapest_index], cheapest_index);
	ft_move_number(stack_a, stack_b, cheapest_index, stack_a->data[cheapest_index]);
	ft_printstacks(stack_a, stack_b);
	/* Round 3 */
	index = stack_a->top;
	cheapest_index = stack_a->top;
	price_temp = INT_MAX;
	while (index >= 0)
	{
		number_a = stack_a->data[index];
		//total_price = (ft_find_price_a(stack_a, index) + ft_find_price_b(stack_b, number_a));
		total_price = ft_total_price(stack_a, stack_b, index, number_a);
		if (total_price < price_temp)
		{
			cheapest_index = index;
			price_temp = total_price;
		}
		ft_printf("Price for number %d: %d\n", stack_a->data[index], total_price);
		ft_printf("The proper index is %d\n", ft_findproperindex(stack_b, number_a));
		index--;  
	}
	ft_printf("Cheapest number to move is %d on index %d\n", stack_a->data[cheapest_index], cheapest_index);
	ft_move_number(stack_a, stack_b, cheapest_index, stack_a->data[cheapest_index]);
	ft_printstacks(stack_a, stack_b);
	
}