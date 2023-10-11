#include "arvore_avl.h"
#include <stdio.h>

void print_no(NoAvl* no) {

    if(no->pai != NULL)
        printf("%.0f(pai %.0f) ", no->valor, no->pai->valor);
    else
        printf("%.0f ", no->valor);

    if(no->esquerda != NULL)
        printf("esquerda %.0f ", no->esquerda->valor);

    if(no->direita != NULL)
        printf("direita %.0f ", no->direita->valor);

    printf("\n");
}

int main() {
    ArvoreAvl * arvore = cria_arvore_avl(1);
    adiciona_na_arvore_avl(arvore, arvore->raiz, 4);
    adiciona_na_arvore_avl(arvore, arvore->raiz, 2);
    adiciona_na_arvore_avl(arvore,arvore->raiz, 1);
    adiciona_na_arvore_avl(arvore,arvore->raiz, 3);
    adiciona_na_arvore_avl(arvore,arvore->raiz, 8);
    adiciona_na_arvore_avl(arvore,arvore->raiz, 9);
    adiciona_na_arvore_avl(arvore,arvore->raiz, 6);
    adiciona_na_arvore_avl(arvore,arvore->raiz, 5);
    adiciona_na_arvore_avl(arvore,arvore->raiz, 7);

    print_arvore_avl(arvore->raiz);

    remove_na_arvore_avl(arvore, arvore->raiz, 6);

    print_arvore_avl(arvore->raiz);
}