#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_RECTANGLES 3

// Structure
struct Rectangle {
    double length;
    double width;
};


struct ThreadData {
    int threadID;
    struct Rectangle rectangle;
};

// Calculate area and perimeter for a rectangle
void* calculateRectangle(void* arg) {
    struct ThreadData* threadData = (struct ThreadData*)arg;

    double area = threadData->rectangle.length * threadData->rectangle.width;
    double perimeter = 2 * (threadData->rectangle.length + threadData->rectangle.width);

    printf("Thread %d: Rectangle with length %.2f and width %.2f\n", threadData->threadID,
           threadData->rectangle.length, threadData->rectangle.width);
    printf("Thread %d: Area = %.2f, Perimeter = %.2f\n", threadData->threadID, area, perimeter);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_RECTANGLES];
    struct ThreadData threadData[NUM_RECTANGLES];

    // Dimensions of rectangles
    struct Rectangle rectangles[NUM_RECTANGLES] = {
        {5.0, 3.0},
        {8.0, 4.0},
        {6.0, 2.5}
    };

    // Create threads
    for (int i = 0; i < NUM_RECTANGLES; ++i) {
        threadData[i].threadID = i + 1;
        threadData[i].rectangle = rectangles[i];

        if (pthread_create(&threads[i], NULL, calculateRectangle, (void*)&threadData[i]) != 0) {
            fprintf(stderr, "Error creating thread\n");
            exit(EXIT_FAILURE);
        }
    }

    // Join threads
    for (int i = 0; i < NUM_RECTANGLES; ++i) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

