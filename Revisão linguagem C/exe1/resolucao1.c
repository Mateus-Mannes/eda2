#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    
    int n = atoi(argv[1]);

    int * array = malloc(sizeof(int) * n);

    printf("Escreva os numeros:\n");

    for(int i = 0; i < n; i++) {
        printf("Numero %d: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\nEscreva o valor de k: ");
    int k = 0;
    scanf("%d", &k);

    int resultado = 0;

    // resolucao n^2

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(array[i] + array[j] == k) {
                printf("Soma encontrada entre %d e %d.", array[i], array[j]);
                return;
            }
                
    printf("Valor k nao encontrado como a soma de um par.\n");

    free(array);    
}