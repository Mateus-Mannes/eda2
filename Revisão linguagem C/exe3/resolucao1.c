#include <stdio.h>
#include <stdlib.h>

int compareint(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}

int main(int argc, char * argv[]){
    if(argc != 2) {
        printf("Uso: ./resolucao1 <n>\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int * array = malloc(sizeof(int) * n);

    printf("Escreva os numeros:\n");

    for(int i = 0; i < n; i++) {
        printf("Numero %d: ", i+1);
        scanf("%d", &array[i]);
    }

    qsort(&array[0], n, sizeof(int), compareint);

    int menorInteiroPositivo = 1;
    for(int i = 0; i < n; i++) {
        if(array[i] <= 0) {
            continue;
        }
        if(array[i] == menorInteiroPositivo) {
            menorInteiroPositivo++;
        } else {
            break;
        }
    }

    printf("Menor inteiro positivo: %d\n", menorInteiroPositivo);

    free(array);

    return 0;
}