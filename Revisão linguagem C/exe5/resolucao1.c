#include <stdio.h>
#include <stdlib.h>

void printa_combinacoes(int degrausRestantes, int posicao, int * combinacao) {
    if(degrausRestantes == 0) {
        printf("[");
        int * ptr = &combinacao[0];
        while(*ptr != 0) {
            printf("%d", *ptr);
            if(*(ptr+1) != 0) printf(", ");
            ptr++;
        }
        printf("]\n");
    }
    else 
    {
        if(degrausRestantes - 1 >= 0) {
            combinacao[posicao] = 1;
            printa_combinacoes(degrausRestantes - 1, posicao + 1, combinacao);
            combinacao[posicao] = 0;
        }
        if(degrausRestantes - 2 >= 0) {
            combinacao[posicao] = 2;
            printa_combinacoes(degrausRestantes - 2, posicao + 1, combinacao);
            combinacao[posicao] = 0;
        }
    }
}

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Uso: ./resolucao1 <n>\n");
        return 1;
    }

    int n = atoi(argv[1]);

    int * combinacao = malloc(sizeof(int) * n);

    printa_combinacoes(n, 0, combinacao);

    free(combinacao);

    return 0;
}


