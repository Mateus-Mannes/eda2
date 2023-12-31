#include <stdio.h>
#include <stdlib.h>

int compareint(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}

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

    // resolucao nlogn

    qsort(&array[0], n, sizeof(int), compareint);

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int sum = array[left] + array[right];
        if(sum == k) {
            printf("Soma encontrada entre %d e %d.", array[left], array[right]);
            free(array);
            return 0;
        }
        else if(sum < k) left++;
        else right--;
    }
                
    printf("Valor k nao encontrado como a soma de um par.");

    free(array);    

    return 0;
}