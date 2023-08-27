#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    char string[100] = { '\0' };

    printf("Escreva a string: ");

    fgets(string, 100, stdin);

    char * ptr = &string[0];

    char * ptrAnterior = &string[0];

    int count = 0;

    while (*ptr != '\0') {

        count++;

        if(*ptr != *ptrAnterior) {
            printf("%d%c", count - 1, *ptrAnterior);
            count = 1;
        }

        ptrAnterior = ptr;
        ptr++;
    }

    printf("\n");

    return 0;
}