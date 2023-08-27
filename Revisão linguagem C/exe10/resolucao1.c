#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void powerSet(int v[], int n) {
    int numberOfSubsets = pow(2, n);

    for (int i = 0; i < numberOfSubsets; i++) {
        printf("{ ");
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) > 0) {
                printf("%d ", v[j]);
            }
        }
        printf("}\n");
    }
}


int main(int argc, char * argv[]) {
    
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

    powerSet(array, n);    

    return 0;
}