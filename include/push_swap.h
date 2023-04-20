/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:20:40 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/20 11:08:08 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <unistd.h>
# include <limits.h>
# include <math.h>

/* t_stack struct typedef */
typedef struct s_stack{
	int		*data;
	int		top;
	int		size;
}	t_stack;

/* t_radix_data struct typedef */
typedef struct s_radix_data{
	int	i;
	int	j;
	int	max_bits;
	int	top_number;
	int	size_a;
	int	size_b;
	int	size_original;
}	t_radix_data;

/* Stack initialization */
void	ft_stacks(t_stack *stack_a, t_stack *stack_b, int size);

/* Operations - swap */
void	ft_swap(t_stack *stack);
void	ft_sa(t_stack *stack_a);
void	ft_sb(t_stack *stack_b);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);

/* Operations - push */
void	ft_push(t_stack *stack, int num);
int		ft_pop(t_stack *stack);
void	ft_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_pb(t_stack *stack_a, t_stack *stack_b);

/* Operations - rotate */
void	ft_rotate(t_stack *stack);
void	ft_ra(t_stack *stack_a);
void	ft_rb(t_stack *stack_b);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);

/* Operations - reverse rotate */
void	ft_reverse_rotate(t_stack *stack);
void	ft_rra(t_stack *stack_a);
void	ft_rrb(t_stack *stack_b);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);

/* Stack initialization + utilities */
int		ft_stackinit_string(t_stack *stack_a, t_stack *stack_b, char *argv);
int		ft_stackinit_numbers(t_stack *s_a, t_stack *s_b, char *v[], int c);

int		ft_splitted_test(char *splitted[]);
int		ft_array_filler(int **array, char *splitted[]);
void	ft_stacks(t_stack *stack_a, t_stack *stack_b, int size);
int		ft_duplicate_limits_tester(int array[], int size);
void	ft_free_stacks(t_stack *stack_a, t_stack *stack_b);
int		ft_get_size(char *splitted[]);
long long	ft_atoi_sort(const char *str);
int		ft_limit_test(char *test);


/* Sorting crossroad */
void	ft_sortstack(t_stack *stack_a, t_stack *stack_b);

/* Sorting algorithms */
void	ft_sort2(t_stack *stack_a);
void	ft_sort3(t_stack *stack_a);
void	ft_sort4(t_stack *stack_a, t_stack *stack_b);
void	ft_sort5(t_stack *stack_a, t_stack *stack_b);
void	ft_sort10(t_stack *stack_a, t_stack *stack_b);
void	ft_radix(t_stack *stack_a);
void	ft_radix_sort(t_stack *indexes_a, t_stack *indexes_b);

/* Sorting utilities */
int		ft_findminindex(t_stack *stack_a);
void	ft_mintotop(t_stack *stack_a);
int		ft_findmaxindex(t_stack *stack_b);
void	ft_maxtotop(t_stack *stack_b);
void	ft_sort_descending(t_stack *stack_a, t_stack *stack_b);
void	ft_radix_data_init(t_radix_data *data, t_stack *ind_a, t_stack *ind_b);
void	ft_count_bits(t_radix_data *data, t_stack *indexes_a);
void	ft_radix_pushback(t_radix_data *data, t_stack *ind_a, t_stack *ind_b);

/* Utility functions */
int		*ft_bubble_sort(int array[], int size);
void	ft_printstacks(t_stack *stack_a, t_stack *stack_b);

#endif