#include "arvore.h"
#include <stdlib.h>

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
    return no;
}

void remove_na_arvore(Arvore* arvore, No* no) {
    if (no->esquerda != NULL)
        remove(arvore, no->esquerda);

    if (no->direita != NULL)
        remove(arvore, no->direita);

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

void percorrer_arvore(No* no) {
    if (no != NULL)
    {
        printf("%f", no->valor);
        percorrer(no->esquerda);
        percorrer(no->direita);
    }
}