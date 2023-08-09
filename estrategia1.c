#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include "estrategia1.h"

/* Essa função inicializa a matriz de energias, calcula a energia da última célula da matriz. Em seguida, calcula a energia da última linha e coluna,
 da direita para a esquerda e de baixo para cima. A função max é usada porque a energia de cada célula é calculada como o máximo entre a energia da célula adjacente (direita ou abaixo) 
 e menos o valor do elemento correspondente. Depois, calcula a energia das demais células. 
 Por fim, a função armazena a energia mínima da primeira célula e libera a memória. */
int estrategia1(Matriz matriz) {
    int** energias = (int**) malloc(matriz.linhas * sizeof(int*));
    for (int i = 0; i < matriz.linhas; i++) {
        energias[i] = (int*) malloc(matriz.colunas * sizeof(int));
    }

    energias[matriz.linhas-1][matriz.colunas-1] = max(1, 1 - matriz.matriz[matriz.linhas-1][matriz.colunas-1]);

    for (int j = matriz.colunas - 2; j >= 0; j--) {
        energias[matriz.linhas-1][j] = max(energias[matriz.linhas-1][j+1] - matriz.matriz[matriz.linhas-1][j], 1);
    }
    for (int i = matriz.linhas - 2; i >= 0; i--) {
        energias[i][matriz.colunas-1] = max(energias[i+1][matriz.colunas-1] - matriz.matriz[i][matriz.colunas-1], 1);
    }
    for (int i = matriz.linhas - 2; i >= 0; i--) {
        for (int j = matriz.colunas - 2; j >= 0; j--) {
            int energiaAbaixo = energias[i+1][j];
            int energiaDireita = energias[i][j+1];
            energias[i][j] = max(min(energiaAbaixo, energiaDireita) - matriz.matriz[i][j], 1);
        }
    }

    int energiaMinima = energias[0][0];
    for (int i = 0; i < matriz.linhas; i++) {
        free(energias[i]);
    }
    free(energias);
    return energiaMinima;
}