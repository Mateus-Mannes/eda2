#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contarPesquisaSequencial(int chave, int v[], int n);
void printWithThousandSeparator(int number);
int contarPesquisaSequencialComSentinela(int chave, int v[], int n);

// RECOMENDO TESTAR COM 1000 PARAMETROS E 2.000.000 SIMULACOES
// gcc main.c -o program
// ./program 1000 20000000
int main(int argc, char const *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <quantidadeDeParametros> <quantidadeDeSimulacoes>\n", argv[0]);
        return 1;
    }

    int quantidadeDeParametros = atoi(argv[1]);

    int vetor[quantidadeDeParametros];
    int i;
    srand(time(NULL));
    for (i = 0; i < quantidadeDeParametros; i++) vetor[i] = rand() % quantidadeDeParametros;

    int quantidadeDeSimulacoes = atoi(argv[2]);

    long long int contagemSequencialSoma = 0;
    long long int contagemSequencialComSentinelaSoma = 0;

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for(i = 0; i < quantidadeDeSimulacoes; i++) {
        int indiceNumeroBuscar = rand() % quantidadeDeParametros;
        int numeroBuscar = vetor[indiceNumeroBuscar];
        contagemSequencialSoma += contarPesquisaSequencial(numeroBuscar, vetor, quantidadeDeParametros);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("contarPesquisaSequencial took %f seconds to execute\n", cpu_time_used);
    printf("Contagem Sequencial Media: ");
    printWithThousandSeparator(contagemSequencialSoma / quantidadeDeSimulacoes);
    printf("\n");

    start = clock();
    for(i = 0; i < quantidadeDeSimulacoes; i++) {
        int indiceNumeroBuscar = rand() % quantidadeDeParametros;
        int numeroBuscar = vetor[indiceNumeroBuscar];
        contagemSequencialComSentinelaSoma += contarPesquisaSequencialComSentinela(numeroBuscar, vetor, quantidadeDeParametros);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("contarPesquisaSequencialComSentinela took %f seconds to execute\n", cpu_time_used);
    printf("Contagem Sequencial Com Sentinela Media: ");
    printWithThousandSeparator(contagemSequencialComSentinelaSoma / quantidadeDeSimulacoes);
    printf("\n");

    return 0;
}

int contarPesquisaSequencial(int chave, int v[], int n)
{
    int count = 1;
    int i;
    for (i = 0; i < n; i++)
    {
        count++;
        if (v[i] == chave) return count;
        count++;
    }
    return count;
}

int contarPesquisaSequencialComSentinela(int chave, int v[], int n)
{
    // contar sequencial com sentinela
    int count = 1;
    int i = 0;
    v[n] = chave;
    while (v[i] != chave)
    {
        count++;
        i++;
    }
    count++;
    if (i < n) return count;
    return count;
}

void printWithThousandSeparator(int number)
{
    if (number < 1000)
    {
        printf("%d", number);
        return;
    }
    printWithThousandSeparator(number / 1000);
    printf(".%03d", number % 1000);
}
