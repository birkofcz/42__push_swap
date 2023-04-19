/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:32:03 by sbenes            #+#    #+#             */
/*   Updated: 2023/04/05 15:43:54 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Implementation of Bubble sort algorithm */

#include <stdio.h>
//#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>

int	*ft_bubble_sort(int array[], int size)
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

void	ft_is_sorted(int array[], int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if(array[i] > array[i + 1])
		{
			printf("\033[31mArray is NOT sorted\033[0m\n");
			return ;
		}
		i++;
	}
	printf("\033[32mArray IS sorted\033[0m\n");
}

int main(void)
{
    int i = 0;
    srand(time(NULL));
    int n = rand() % 100; // Random array size between 0 and 100
    int array[100];

    while (i < n)
	{
       array[i] = rand() % (499 + 1 - (-500)) + (-500);
	   i++;
	}
    printf("\n\033[97;42m[[FT_BUBBLE_SORT test]]\033[0m\n");
    printf("\n\033[97;42mGenerating random array size with random numbers between -500 and 500.\033[0m\n");
	printf("\033[97;42mGenerated array size: %d\033[0m\n", n);
    i = 0;
    printf("\nArray before sorting: [");
    while (i < n - 1)
        printf("%d, ", array[i++]);
    printf("%d]\n", array[i]);
	printf("Test: ");
	ft_is_sorted(array, n);
	ft_bubble_sort(array, n);
	i = 0;
    printf("\nArray after sorting: [");
    while (i < n - 1)
        printf("%d, ", array[i++]);
    printf("%d]\n", array[i]);
	printf("Test: ");
	ft_is_sorted(array, n);
	printf("\n");
    return (0);
}

