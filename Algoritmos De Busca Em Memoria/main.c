#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ExecutarPesquisa(
    int quantidadeDeParametros,
    int quantidadeDeSimulacoes,
    int vetor[],
    char * nomePesquisa,
    int (*func)(int, int[], int));

void printWithThousandSeparator(int number);
int compareInt(void const *a, void const *b);

int contarPesquisaSequencial(int chave, int v[], int n);
int contarPesquisaSequencialComSentinela(int chave, int v[], int n);
int contarPesquisaBinaria(int chave, int v[], int n);


// RECOMENDO TESTAR COM 1000 a 100.000 PARAMETROS E 500.000 a 2.000.000 SIMULACOES
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

    ExecutarPesquisa(
        quantidadeDeParametros, 
        quantidadeDeSimulacoes, 
        vetor, 
        "contarPesquisaSequencial", 
        contarPesquisaSequencial);

    ExecutarPesquisa(
        quantidadeDeParametros, 
        quantidadeDeSimulacoes, 
        vetor, 
        "contarPesquisaSequencialComSentinela", 
        contarPesquisaSequencialComSentinela);

    qsort(vetor, quantidadeDeParametros, sizeof(int), compareInt);
    
    ExecutarPesquisa(
        quantidadeDeParametros, 
        quantidadeDeSimulacoes, 
        vetor, 
        "contarPesquisaBinaria", 
        contarPesquisaBinaria);

    return 0;
}

void ExecutarPesquisa(
    int quantidadeDeParametros,
    int quantidadeDeSimulacoes,
    int vetor[],
    char * nomePesquisa,
    int (*func)(int, int[], int)) 
{
    clock_t start, end;
    double cpu_time_used;
    long long int contagemSoma = 0;
    start = clock();
    int i;
    for(i = 0; i < quantidadeDeSimulacoes; i++) {
        int indiceNumeroBuscar = rand() % quantidadeDeParametros;
        int numeroBuscar = vetor[indiceNumeroBuscar];
        contagemSoma += func(numeroBuscar, vetor, quantidadeDeParametros);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%s levou %f segundos para executar\n", nomePesquisa, cpu_time_used);
    printf("Contagem %s Media: ", nomePesquisa);
    printWithThousandSeparator(contagemSoma / quantidadeDeSimulacoes);
    printf("\n");
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

int compareInt(void const *a, void const *b)
{
    return (*(int *)a - *(int *)b);
}

int contarPesquisaBinaria(int chave, int v[], int n)
{
    int inicio = 0;
    int meio = 0; 
    int fim = n - 1;
    int count = 1;
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        count++;
        if (chave < v[meio])
        {
            fim = meio - 1;
        }
        else if (chave > v[meio])
        {
            count++;
            inicio = meio + 1;
        }
        else
        {
            return count;
        }
        count++;
    }
    return count; // Índice impossível
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
