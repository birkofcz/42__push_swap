#include "../include/push_swap.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int get_insertion_index(s_stack *stack, int value) {
    int index = 0;
    for (int i = stack->top; i >= 0; i--) {
        if (stack->data[i] < value) {
            break;
        }
        index++;
    }
    return index;
}

/* int calculate_cost(s_stack *stack_a, s_stack *stack_b, int index) {
    int value = stack_a->data[index];
    int insert_index = get_insertion_index(stack_b, value);
    
    int cost_to_top = (index < stack_a->top / 2) ? index + 1 : stack_a->top - index + 1;
    int cost_to_insert = (insert_index < stack_b->top / 2) ? insert_index + 1 : stack_b->top - insert_index + 1;
    
    int simultaneous_rotations = (cost_to_top < cost_to_insert) ? cost_to_top - 1 : cost_to_insert - 1;
    
    int total_cost = cost_to_top + cost_to_insert - simultaneous_rotations;
    
    return total_cost;
} */

int calculate_cost(s_stack *stack_a, s_stack *stack_b, int index) {
    int value = stack_a->data[index];
    int insert_index = get_insertion_index(stack_b, value);
    
    int cost_to_top = (index < stack_a->top / 2) ? index + 1 : stack_a->top - index + 1;
    int cost_to_insert = (insert_index < stack_b->top / 2) ? insert_index + 1 : stack_b->top - insert_index + 1;
    
    int simultaneous_rotations = (cost_to_top < cost_to_insert) ? cost_to_top - 1 : cost_to_insert - 1;
    
    int total_cost = cost_to_top + cost_to_insert - simultaneous_rotations;
    
    return total_cost;
}





int main() {
    int data_a[] = {7, 1, 6, 3, 9, 4, 8};
    int data_b[] = {2, 5};
    s_stack stack_a = {data_a, sizeof(data_a) / sizeof(int) - 1, sizeof(data_a) / sizeof(int)};
    s_stack stack_b = {data_b, sizeof(data_b) / sizeof(int) - 1, sizeof(data_b) / sizeof(int)};
    
    for (int i = 0; i <= stack_a.top; i++) {
        int cost = calculate_cost(&stack_a, &stack_b, i);
        printf("Cost for moving number %d to stack_b: %d\n", stack_a.data[i], cost);
    }
    
    return 0;
}


