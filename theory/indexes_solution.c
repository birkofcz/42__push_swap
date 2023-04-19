#include <stdio.h>
#include <stdlib.h>

int* convert_to_indexes(int stack_a[], int size) {
    int* indexes = (int*) malloc(size * sizeof(int));
    int* temp = (int*) malloc(size * sizeof(int));

    int i = 0;
    while (i < size) {
        temp[i] = stack_a[i];
        i++;
    }

    // Sort temp array
    i = 0;
    while (i < size - 1) {
        int j = i + 1;
        while (j < size) {
            if (temp[i] > temp[j]) {
                int temp_var = temp[i];
                temp[i] = temp[j];
                temp[j] = temp_var;
            }
            j++;
        }
        i++;
    }

    // Map stack_a elements to their indexes in temp array
    i = 0;
    while (i < size) {
        int j = 0;
        while (j < size) {
            if (stack_a[i] == temp[j]) {
                indexes[i] = j + 1;
                break;
            }
            j++;
        }
        i++;
    }

    free(temp);
    return indexes;
}

int main() {
    int stack_a[] = {-1, -2, -3, 1, 2, 3};
    int size = sizeof(stack_a) / sizeof(stack_a[0]);
    int *indexes = convert_to_indexes(stack_a, size);

    printf("Original array: ");
    int i = 0;
    while (i < size) {
        printf("%d ", stack_a[i]);
        i++;
    }
    printf("\n");

    printf("Indexes: ");
    i = 0;
    while (i < size) {
        printf("%d ", indexes[i]);
        i++;
    }

    free(indexes);
    return 0;
}