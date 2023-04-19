/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:20:40 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/19 15:17:38 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <unistd.h>
# include <limits.h>
# include <math.h>

/* s_stack struct typedef */
typedef struct {
	int		*data;
	int		top;
	int		size;
}	s_stack;

/* Stack initialization */
void	ft_stackinit(s_stack *stack_a, s_stack *stack_b, char *argv);
//void 	ft_stackinit(s_stack *stack_a, s_stack *stack_b, int size); //OLD

/* Operations - swap */
void	ft_swap(s_stack *stack);
void	ft_sa(s_stack *stack_a);
void	ft_sb(s_stack *stack_b);
void	ft_ss(s_stack *stack_a, s_stack *stack_b);

/* Operations - push */
void	ft_push(s_stack *stack, int num);
int		ft_pop(s_stack *stack);
void	ft_pa(s_stack *stack_a, s_stack *stack_b);
void	ft_pb(s_stack *stack_a, s_stack *stack_b);

/* Operations - rotate */
void	ft_rotate(s_stack *stack);
void	ft_ra(s_stack *stack_a);
void	ft_rb(s_stack *stack_b);
void	ft_rr(s_stack *stack_a, s_stack *stack_b);

/* Operations - reverse rotate */
void	ft_reverse_rotate(s_stack *stack);
void	ft_rra(s_stack *stack_a);
void	ft_rrb(s_stack *stack_b);
void	ft_rrr(s_stack *stack_a, s_stack *stack_b);

/* Stack initialization + utilities */
int		ft_stackinit_string(s_stack *stack_a, s_stack *stack_b, char *argv);
int		ft_stackinit_numbers(s_stack *stack_a, s_stack *stack_b, char *argv[], int argc);

int		ft_splitted_test(char *splitted[]);
int		ft_array_filler(int **array, char *splitted[]);
void	ft_stacks(s_stack *stack_a, s_stack *stack_b, int size);
int		ft_duplicate_limits_tester(int array[], int size);
void	ft_free_stacks(s_stack *stack_a, s_stack *stack_b);
int		ft_get_size(char *splitted[]);


/* Sorting crossroad */
void	ft_sortstack(s_stack *stack_a, s_stack *stack_b);

/* Sorting algorithms */
void	ft_sort2(s_stack *stack_a);
void	ft_sort3(s_stack *stack_a);
void	ft_sort4(s_stack *stack_a, s_stack *stack_b);
void	ft_sort5(s_stack *stack_a, s_stack *stack_b);
void	ft_sort10(s_stack *stack_a, s_stack *stack_b);
void	ft_radix_sort(s_stack *indexes_a, s_stack *indexes_b);

/* Sorting utilities */
int		ft_findminindex(s_stack *stack_a);
void	ft_mintotop(s_stack *stack_a);
int		ft_findmaxindex(s_stack *stack_b);
void	ft_maxtotop(s_stack *stack_b);
void	ft_sort_descending(s_stack *stack_a, s_stack *stack_b);


/* Utility functions */
int		*ft_bubble_sort(int array[], int size);
void	ft_printstacks(s_stack *stack_a, s_stack *stack_b);

/* Sort big experiments */
//void ft_doctor_strange(s_stack *stack_a, s_stack *stack_b);
void	ft_radix(s_stack *stack_a);



#endif