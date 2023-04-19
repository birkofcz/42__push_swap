#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void divide_into_buckets(int *array, int size, int ***buckets, int *bucket_count) {
    int base_bucket_size = size / 10;
    int extra_buckets = size % 10;

    if (extra_buckets > 0) {
        *bucket_count = 11;
    } else {
        *bucket_count = 10;
    }

    *buckets = (int **)malloc(*bucket_count * sizeof(int *));
    int i = 0;
    while (i < *bucket_count) {
        int current_bucket_size = base_bucket_size;
        if (i < extra_buckets) {
            current_bucket_size += 1;
        }
        (*buckets)[i] = (int *)malloc(current_bucket_size * sizeof(int));
        i++;
    }

    int current_bucket = 0;
    int current_element = 0;
    i = 0;
    while (i < size) {
        int current_bucket_size = base_bucket_size;
        if (current_bucket < extra_buckets) {
            current_bucket_size += 1;
        }
        (*buckets)[current_bucket][current_element++] = array[i];

        if (current_element == current_bucket_size) {
            current_bucket++;
            current_element = 0;
        }
        i++;
    }
}


void generate_random_array(int *array, int size, int lower, int upper) {
    int i = 0;
    while (i < size) {
        array[i] = rand() % (upper - lower + 1) + lower;
        i++;
    }
}

int main() {
    int size = 100;
    int *array = (int *)malloc(size * sizeof(int));
    int lower = 1;
    int upper = 100;

    srand(time(NULL)); // Seed the random number generator
    generate_random_array(array, size, lower, upper);

    printf("Generated array:\n");
    int i = 0;
    while (i < size) {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");

    int **buckets;
    int bucket_count;

    divide_into_buckets(array, size, &buckets, &bucket_count);

    i = 0;
    while (i < bucket_count) {
        printf("Bucket %d:", i);
        int current_bucket_size = size / 10;
        if (i < (size % 10)) {
            current_bucket_size += 1;
        }

        int j = 0;
        while (j < current_bucket_size) {
            printf(" %d", buckets[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

    i = 0;
    while (i < bucket_count) {
        free(buckets[i]);
        i++;
    }
    free(buckets);
    free(array);

    return 0;
}
