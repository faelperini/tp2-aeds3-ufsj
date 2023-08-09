#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include "estrategia2.h"

/* Essa função é semelhante à estratégia1, porém, ao calcular a energia das células que não são a última linha e coluna, 
utiliza um método guloso. O método consiste em sempre escolher a célula possível com menor energia (direita ou abaixo), sem se preocupar com o custo total do caminho. */
int estrategia2(Matriz matriz) {
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
            int energiaGulosa = min(energiaAbaixo, energiaDireita) - matriz.matriz[i][j];
            energias[i][j] = max(energiaGulosa, 1);
        }
    }

    int energiaMinima = energias[0][0];
    for (int i = 0; i < matriz.linhas; i++) {
        free(energias[i]);
    }
    free(energias);
    return energiaMinima;
}