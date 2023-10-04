#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

Arvore *cria_arvore()
{
    Arvore *arvore;
    arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

int arvore_vazia(Arvore* arvore) {
    return (arvore->raiz == NULL);
}

No* adiciona_na_arvore(Arvore* arvore, No* pai, float valor) {
    No *no = malloc(sizeof(No));
    no->pai = pai;
    no->esquerda = NULL;
    no->direita = NULL;
    no->valor = valor;

    if (pai == NULL)
    {
        arvore->raiz = no;
    }
    else 
    {
        if (valor < pai->valor)
            pai->esquerda = no;
        else
            pai->direita = no;
    }
    return no;
}

void remove_na_arvore(Arvore* arvore, No* no) {
    if (no->esquerda != NULL)
        remove_na_arvore(arvore, no->esquerda);

    if (no->direita != NULL)
        remove_na_arvore(arvore, no->direita);

    if (no->pai == NULL)
    {
        arvore->raiz = NULL;
    }
    else
    {
        if (no->pai->esquerda == no)
            no->pai->esquerda = NULL;
        else
            no->pai->direita = NULL;
    }
    free(no);
}

void percorrer_arvore_pre_order(No* no, void (*callback)(No*)) {
    if (no != NULL)
    {
        callback(no);
        percorrer_arvore_pre_order(no->esquerda, callback);
        percorrer_arvore_pre_order(no->direita, callback);
    }
}

void percorrer_arvore_in_order(No* no, void (*callback)(No*)) {
    if (no != NULL)
    {
        percorrer_arvore_in_order(no->esquerda, callback);
        callback(no);
        percorrer_arvore_in_order(no->direita, callback);
    }
}

void percorrer_arvore_pos_order(No* no, void (*callback)(No*)) {
    if (no != NULL)
    {
        percorrer_arvore_pos_order(no->esquerda, callback);
        percorrer_arvore_pos_order(no->direita, callback);
        callback(no);
    }
}

void noopFreeFunction(void* data) {
    // Do nothing
}

void percorrer_arvore_em_largura(No* no, void (*callback)(No*)) {
    Queue fila;
    initializeQueue(&fila);
    enqueue(&fila, no);
    while (!queueIsEmpty(&fila))
    {
        No *no = dequeue(&fila);
        callback(no);
        if (no->esquerda != NULL)
            enqueue(&fila, no->esquerda);
        if (no->direita != NULL)
            enqueue(&fila, no->direita);
    }
    freeQueue(&fila, noopFreeFunction);
}

No * adiciona_na_arvore_ordenado(Arvore* arvore, float valor) {
    No *no = malloc(sizeof(No));
    no->valor = valor;
    no->pai = NULL;
    no->esquerda = NULL;
    no->direita = NULL;

    if (arvore->raiz == NULL)
    {
        arvore->raiz = no;
        return no;
    }

    No * atual = arvore->raiz;
    no->pai = atual;
    while (no->pai->esquerda != no && no->pai->direita != no) 
    {
        no->pai = atual;
        if(atual->valor > valor)
        {
            if(atual->esquerda != NULL) atual = atual->esquerda;
            else atual->esquerda = no;
        }
        else 
        {
            if(atual->direita != NULL) atual = atual->direita;
            else atual->direita = no;
        }
    }
    return no;
}

void limpar_arvore(Arvore* arvore) {
    if (arvore->raiz != NULL)
        remove_na_arvore(arvore, arvore->raiz);
    free(arvore);
}