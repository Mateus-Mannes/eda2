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

    printf("\nEscreva o valor de k: ");
    int k = 0;
    scanf("%d", &k);

    // resolucao n^2

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(array[i] + array[j] == k) {
                printf("Soma encontrada entre %d e %d.", array[i], array[j]);
                return 0;
            }
                
    printf("Valor k nao encontrado como a soma de um par.\n");

    free(array);    

    return 0;
}