#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

int main() {
    srand(time(NULL));

    int matrizA[SIZE][SIZE];
    int matrizB[SIZE][SIZE];
    int resultado[SIZE][SIZE];

    for (int i = 0; i < SIZE; ++i) 
        for (int j = 0; j < SIZE; ++j) 
            matrizA[i][j] = rand() % 10;

    for (int i = 0; i < SIZE; ++i) 
        for (int j = 0; j < SIZE; ++j) 
            matrizB[i][j] = rand() % 10;

    printf("Matriz A:\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) 
            printf("%d ", matrizA[i][j]);
        printf("\n");
    }

    printf("\nMatriz B:\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) 
            printf("%d ", matrizB[i][j]);
        printf("\n");
    }

    clock_t inicio = clock();

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            resultado[i][j] = 0;
            for (int k = 0; k < SIZE; ++k) 
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }

    clock_t fin = clock();
    double tiempoEjecucion = ((double)(fin - inicio) * 1000) / CLOCKS_PER_SEC;

    printf("\nResultado:\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) 
            printf("%d ", resultado[i][j]);
        printf("\n");
    }

    printf("\nTiempo de ejecucion: %.2f milisegundos\n", tiempoEjecucion);

    return 0;
}

