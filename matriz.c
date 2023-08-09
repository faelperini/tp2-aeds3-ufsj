#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include "matriz.h"

/* Essa função retorna o valor máximo entre dois inteiros. */
int max(int a, int b) {
    return (a > b) ? a : b;
}

/* Essa função retorna o valor mínimo entre dois inteiros. */
int min(int a, int b) {
    return (a < b) ? a : b;
}

/* Essa função libera a memória alocada da matriz. */
void liberarMatriz(Matriz matriz) {
    for (int i = 0; i < matriz.linhas; i++) {
        free(matriz.matriz[i]);
    }
    free(matriz.matriz);
}

/* Essa função retorna uma matriz em que a memória foi alocada para as linhas (ponteiro de ponteiro) usando um loop, 
e por fim ela é preenchida com os valores do arquivo de entrada. */
Matriz criarMatriz(FILE* arquivo, int linhas, int colunas) {
    Matriz matriz;
    matriz.linhas = linhas;
    matriz.colunas = colunas;
    matriz.matriz = (int**) malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz.matriz[i] = (int*) malloc(colunas * sizeof(int));
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            fscanf(arquivo, "%d", &matriz.matriz[i][j]);
        }
    }
    return matriz;
}