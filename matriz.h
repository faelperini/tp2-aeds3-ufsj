#ifndef _H_MATRIZ
#define _H_MATRIZ

typedef struct {
    int linhas;
    int colunas;
    int** matriz;
} Matriz;

int max(int a, int b);
int min(int a, int b);
Matriz criarMatriz(FILE* arquivo, int linhas, int colunas);
void liberarMatriz(Matriz matriz);
void abreArquivo(char* estrategia, char* nomeArquivo);
void imprimeResultado(FILE* arquivo, int numeroTeste, char* estrategia);

#endif