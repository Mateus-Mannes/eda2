#include <stdio.h>
#include <stdlib.h>

// A Deque (Double ended queue) based method for printing maximum element of
// all subarrays of size k
int* maxSlidingWindow(int* v, int n, int k, int* returnSize) {
    if (!v || n == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    *returnSize = n - k + 1;
    int* res = (int*)malloc((*returnSize) * sizeof(int));
    
    int deque[n];
    int i, front = 0, back = 0;
    
    for (i = 0; i < n; i++) {
        // remove numbers out of range k from deque
        while (front < back && deque[front] < i - k + 1) front++;
        
        // remove smaller numbers in k range as they are useless
        while (front < back && v[deque[back - 1]] < v[i]) back--;
        
        // add current number into the back of deque
        deque[back++] = i;
        
        // the first index has the largest value for the current sliding window
        if (i >= k - 1) res[i - k + 1] = v[deque[front]];
    }
    
    return res;
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
    int returnSize = 0;
    
    int* res = maxSlidingWindow(array, n, k, &returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    
    printf("\n");
    free(res);
    free(array);

    return 0;
}
