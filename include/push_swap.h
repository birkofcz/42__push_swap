/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:20:40 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/19 15:53:48 by sbenes           ###   ########.fr       */
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
int		ft_stackinit_numbers(t_stack *stack_a, t_stack *stack_b, char *argv[], int argc);

int		ft_splitted_test(char *splitted[]);
int		ft_array_filler(int **array, char *splitted[]);
void	ft_stacks(t_stack *stack_a, t_stack *stack_b, int size);
int		ft_duplicate_limits_tester(int array[], int size);
void	ft_free_stacks(t_stack *stack_a, t_stack *stack_b);
int		ft_get_size(char *splitted[]);


/* Sorting crossroad */
void	ft_sortstack(t_stack *stack_a, t_stack *stack_b);

/* Sorting algorithms */
void	ft_sort2(t_stack *stack_a);
void	ft_sort3(t_stack *stack_a);
void	ft_sort4(t_stack *stack_a, t_stack *stack_b);
void	ft_sort5(t_stack *stack_a, t_stack *stack_b);
void	ft_sort10(t_stack *stack_a, t_stack *stack_b);
void	ft_radix_sort(t_stack *indexes_a, t_stack *indexes_b);

/* Sorting utilities */
int		ft_findminindex(t_stack *stack_a);
void	ft_mintotop(t_stack *stack_a);
int		ft_findmaxindex(t_stack *stack_b);
void	ft_maxtotop(t_stack *stack_b);
void	ft_sort_descending(t_stack *stack_a, t_stack *stack_b);


/* Utility functions */
int		*ft_bubble_sort(int array[], int size);
void	ft_printstacks(t_stack *stack_a, t_stack *stack_b);

/* Sort big experiments */
//void ft_doctor_strange(t_stack *stack_a, t_stack *stack_b);
void	ft_radix(t_stack *stack_a);



#endif