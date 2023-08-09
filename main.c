#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "matriz.h"

int main(int argc, char* argv[]) {

    struct rusage r_usage;
    getrusage(RUSAGE_SELF, &r_usage);
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    char* estrategia = argv[1];
    char* nomeArquivo = argv[2];

    abreArquivo(estrategia, nomeArquivo);
    (void)argc;

    gettimeofday(&end_time, NULL);
    double exec_time = (end_time.tv_sec - start_time.tv_sec) + 
                       (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    double mem_used = r_usage.ru_maxrss / 1024.0;

    printf("Memória utilizada: %lf KB\n", mem_used);
    printf("Tempo de execução: %lf segundos\n", exec_time);

    return 0;
}
