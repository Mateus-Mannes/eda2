#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    char sequencia[100] = { '\0' };
   
   char pilha[100];

   int ponta = -1;

    printf("Escreva uma sequência de parênteses: ");

    fgets(sequencia, 100, stdin);

    char * ptr = &sequencia[0];

    while (*ptr != '\0') {
        
        if(*ptr == '(' || *ptr == '[' || *ptr == '{') {
            ponta++;
            pilha[ponta] = *ptr;
        }

        if(*ptr == ')') {
            if(pilha[ponta] == '(') {
                ponta--;
            } else {
                printf("Sequência inválida!\n");
                return 0;
            }
        }

        if(*ptr == ']') {
            if(pilha[ponta] == '[') {
                ponta--;
            } else {
                printf("Sequência inválida!\n");
                return 0;
            }
        }

        if(*ptr == '}') {
            if(pilha[ponta] == '{') {
                ponta--;
            } else {
                printf("Sequência inválida!\n");
                return 0;
            }
        }

        ptr++;
    }

    if(ponta == -1) {
        printf("Sequência válida!\n");
    } else {
        printf("Sequência inválida!\n");
    }

    return 0;
}