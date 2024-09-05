#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3   
#define MATRIX_ROWS 4   

int matrix[MATRIX_ROWS][NUM_THREADS] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 11, 12}
};

int columnSum[NUM_THREADS] = {0};
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// sum of a column in the matrix
void* computeColumnSum(void* arg) {
    int col = *((int*)arg);
    int sum = 0;

    for (int row = 0; row < MATRIX_ROWS; ++row) {
        sum += matrix[row][col];
    }

    // Lock
    pthread_mutex_lock(&mutex);
    columnSum[col] = sum;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    // Create thread
    for (int col = 0; col < NUM_THREADS; ++col) {
        thread_args[col] = col;
        if (pthread_create(&threads[col], NULL, computeColumnSum, (void*)&thread_args[col]) != 0) {
            fprintf(stderr, "Error creating thread\n");
            exit(EXIT_FAILURE);
        }
    }

    // Join thread
    for (int col = 0; col < NUM_THREADS; ++col) {
        if (pthread_join(threads[col], NULL) != 0) {
            fprintf(stderr, "Error joining thread\n");
            exit(EXIT_FAILURE);
        }
    }

    // cumulative sum of each column
    printf("Cumulative sum of each column:\n");
    for (int col = 0; col < NUM_THREADS; ++col) {
        printf("Column %d: %d\n", col + 1, columnSum[col]);
    }

    return 0;
}

