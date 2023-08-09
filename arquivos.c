#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include "estrategia1.h"
#include "estrategia2.h"
#include "matriz.h"

/* Essa função lê o número de testes que está no arquivo de entrada e redireciona para a função imprimeResultado. */
void abreArquivo(char* estrategia, char* nomeArquivo) {
    FILE* arquivoEntrada = fopen(nomeArquivo, "r");
    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir arquivo\n");
        return;
    }
    int numeroTeste;
    fscanf(arquivoEntrada, "%d", &numeroTeste);
    imprimeResultado(arquivoEntrada, numeroTeste, estrategia);
    fclose(arquivoEntrada);
}

/* Essa função lê as linhas e colunas de cada caso com um loop, redireciona para as estratégias e escreve no arquivo de saída. */
void imprimeResultado(FILE* arquivo, int numeroTeste, char* estrategia) {
    FILE* arquivoSaida = fopen("saida.txt", "a");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída!\n");
        return;
    }

    for (int teste = 0; teste < numeroTeste; teste++) {
        int linhas, colunas;
        fscanf(arquivo, "%d %d", &linhas, &colunas);
        Matriz matriz = criarMatriz(arquivo, linhas, colunas);
        if (strcmp(estrategia, "1") == 0) {
            fprintf(arquivoSaida, "%d\n", estrategia1(matriz));
        } else if (strcmp(estrategia, "2") == 0) {
            fprintf(arquivoSaida, "%d\n", estrategia2(matriz));
        } else {
            printf("Estratégia inválida!");
            return;
        }
        liberarMatriz(matriz);
    }
    fclose(arquivoSaida);
}