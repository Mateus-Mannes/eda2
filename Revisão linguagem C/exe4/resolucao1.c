#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int findMaxSum(int v[], int n) {
    if (n == 0) return 0;
    if (n == 1) return v[0];

    int prevPrev = v[0];
    int prev = max(v[0], v[1]);
    for (int i = 2; i < n; i++) {
        int curr = max(prev, prevPrev + v[i]);
        prevPrev = prev;
        prev = curr;
    }
    return prev;
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

    printf("Soma maxima: %d\n", findMaxSum(array, n)); 

    free(array);

    return 0;
}
