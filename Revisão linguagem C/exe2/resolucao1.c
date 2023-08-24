#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

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

    int produtoTotal = 1;

    for(int i = 0; i < n; i++) {
        produtoTotal *= array[i];
    }

    printf("[");

    for(int i = 0; i < n; i++) {
        printf("%d", produtoTotal / array[i]);
        if(i != n-1) {
            printf(", ");
        }
    }

    printf("]\n");

    free(array);

    return 0;
}