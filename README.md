# 42 project: push_swap

My score:  **84/125** (using a Radix sort implementation which is not - in this particular case - the most efficient algorithm. On the other hand, it is clear and easily managable, predicatable).

Push_swap is a program that sorts a stack of integers using a limited set of operations. The primary goal is to sort the stack with the least number of operations possible, also only use the limited set of operations. The program takes a list of integers as input and outputs the sequence of operations required to sort the stack.

Contrary to usual solutions involving linked list to simulate stack behaviour, my approach is using a typedef struct holding and integer array, size and top index of the stack.

The program first checks if the stack is already sorted. If it is, no sorting is performed, and memory is freed. Otherwise, the sorting process begins. The program initializes two stacks, stack_a (the main stack) and stack_b (the auxiliary stack), and performs error management (input of non-number, limits of integers and duplicates) before starting the sorting process.

Depending on the number of integers to be sorted, the program uses different sorting algorithms:

- For 2 integers, it simply swaps them if needed.
- For 3 integers, it uses a sequence of rotations and swaps to sort them.
- For 4 or 5 integers, it utilizes the auxiliary stack and a combination of push, rotate, and swap operations.
- For up to 10 integers, it uses a more optimized approach involving multiple cases.

For more than 10 integers, it employs the radix sort algorithm, which is based on sorting the integer's binary representation.This implementation of the **Radix sort** is a non-comparison-based sorting algorithm designed for sorting integers in linear time. The idea behind Radix sort is to process the input numbers digit by digit, starting from the least significant bit (LSB) and moving towards the most significant bit (MSB). In this specific implementation, it uses binary representation and bitwise operations to achieve efficient sorting.

The Radix sort used in the Push_swap project is customized to work with stacks instead of the traditional arrays or lists. The main purpose of the project is to sort a stack of integers using the smallest possible number of operations. Radix sort is an excellent choice for this task due to its linear time complexity.

In the implementation, the original stack of integers (stack_a) is first converted into a "shadow stack" containing the indexes of the integers in their sorted order. The shadow stack (indexes_a) is then sorted using Radix sort, and the operations performed during the sorting process are mirrored onto the original stack (stack_a). This approach ensures that the original stack is sorted using the same sequence of operations as the shadow stack.

The Radix sort implementation in this project consists of the following key steps:

- Initialization: The shadow stacks (indexes_a and indexes_b) are created and initialized with the indexes of the integers in their sorted order.

- Bit counting: The maximum number of bits required to represent the integers in binary form is calculated. This determines the number of iterations required for the Radix sort algorithm.

- Sorting process: The sorting process is carried out in a loop, iterating through each bit from LSB to MSB. During each iteration, the integers are divided into two groups based on the value of the current bit (0 or 1). Those with a 0 are pushed to stack_b, while those with a 1 are rotated in stack_a. After completing the iteration for the current bit, all elements from stack_b are pushed back to stack_a, ensuring that the stack is sorted based on the bits processed so far.

The program uses various helper functions to perform the stack operations, such as push, pop, rotate, reverse rotate, and swap. These operations are performed on both stack_a and stack_b to ensure the optimal sorting sequence. It also uses a lot of utility functions to ensure the process of sortimg is on the right track.

