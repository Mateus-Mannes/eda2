#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int valor;
    struct node *proximo;
} Node;

typedef struct lista
{
    int tamanho;
    Node *cabeca;
} Lista;



int main() {
    
    // primeira lista
    Node tres;
    tres.valor = 3;

    Node sete;
    sete.valor = 7;
    tres.proximo = &sete;

    Node oito;
    oito.valor = 8;
    sete.proximo = &oito;

    Node dez;
    dez.valor = 10;
    oito.proximo = &dez;

    Lista lista1;
    lista1.tamanho = 4;
    lista1.cabeca = &tres;

    // segunda lista
    Node noventaENove;
    noventaENove.valor = 99;

    Node um;
    um.valor = 1;
    noventaENove.proximo = &um;

    um.proximo = &oito;

    Lista lista2;
    lista2.tamanho = 4;
    lista2.cabeca = &noventaENove;

    Node * ptr1 = lista1.cabeca;

    Node * ptr2 = lista2.cabeca;

    int diferenca = abs(lista1.tamanho - lista2.tamanho);

    while (diferenca > 0)
    {
        if(lista1.tamanho > lista2.tamanho) {
            ptr1 = ptr1->proximo;
        } else {
            ptr2 = ptr2->proximo;
        }
        diferenca--;
    }

    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->proximo;
        ptr2 = ptr2->proximo;
    }
    
    printf("O valor do nó de intersecção é: %d\n", ptr1->valor);

    return 0;
}