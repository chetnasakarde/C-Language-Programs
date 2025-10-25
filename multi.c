// File: matrix_mult_threaded.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 3
int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

typedef struct {
    int row, col;
} ThreadData;

void* multiply(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int sum = 0;
    for (int k = 0; k < SIZE; k++)
        sum += A[data->row][k] * B[k][data->col];
    C[data->row][data->col] = sum;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[SIZE * SIZE];
    ThreadData data[SIZE * SIZE];
    int count = 0;

    printf("Enter matrix A (%dx%d):\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B (%dx%d):\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &B[i][j]);

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            data[count] = (ThreadData){i, j};
            pthread_create(&threads[count], NULL, multiply, &data[count]);
            count++;
        }

    for (int i = 0; i < count; i++)
        pthread_join(threads[i], NULL);

    printf("Resultant Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}
