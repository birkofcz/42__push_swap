#include "../include/push_swap.h"

// Radix sort

static int	get_maxbits_lst(s_stack *stack_a)
{
	int	max;
	int	max_b;
	int	size;

	size = stack_a->size;
	max = 0;
	max_b = 0;
	while (size > 0)
	{
		if (stack_a->data[size - 1] > max)
			max = stack_a->data[size - 1];
		size--;
	}
	while ((max >> max_b) != 0)
		max_b++;
	return (max_b);
}

int	lst_size(s_stack *stack_a)
{
	int		i;
	int size;

	i = 0;
	size = stack_a->size;
	while (size > 0)
	{
		i++;
		size--;
	}
	return (i);
}

void	radix_sort(s_stack *stack_a, s_stack *stack_b)
{
	int		i;
	int		j;
	int k;
	int		size;
	int		max_b;

	size = lst_size(stack_a);
	max_b = get_maxbits_lst(stack_a);
	i = -1;
	while (++i < max_b)
	{
		j = -1;
		while (++j < size)
		{
			if (((stack_a->data[k++] >> i) & 1) == 0)
				ft_pb(stack_a, stack_b);
			else
				ft_ra(stack_a);
		}
		while (lst_size(stack_b) != 0)
			ft_pa(stack_a, stack_b);
	}
}
