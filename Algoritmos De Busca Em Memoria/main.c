#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contarPesquisaSequencial(int chave, int v[], int n);
void printWithThousandSeparator(int number);

int main(int argc, char const *argv[])
{
    int quantidadeDeParametros = atoi(argv[1]);

    // crie um vetor de inteiros com a quantidade de elementos passada por parametro com valores aleatorios
    int vetor[quantidadeDeParametros];
    int i;
    srand(time(NULL));
    for (i = 0; i < quantidadeDeParametros; i++) vetor[i] = rand() % quantidadeDeParametros;

    int quantidadeDeSimulacoes = atoi(argv[2]);

    int contagemSequencialSoma = 0;
    for(i = 0; i < quantidadeDeSimulacoes; i++) {
        int indiceNumeroBuscar = rand() % quantidadeDeParametros;
        int numeroBuscar = vetor[indiceNumeroBuscar];
        contagemSequencialSoma += contarPesquisaSequencial(numeroBuscar, vetor, quantidadeDeParametros);
    }

    printf("Contagem Sequencial Media: ");
    printWithThousandSeparator(contagemSequencialSoma / quantidadeDeSimulacoes);
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
