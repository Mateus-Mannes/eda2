#include "arvore_avl.h"
#include <stdio.h>

void print_no(NoAvl* no) {
    if(no->pai != NULL)
        printf("%.0f(pai %.0f) ", no->valor, no->pai->valor);
    else
        printf("%.0f ", no->valor);
}

int main() {
    ArvoreAvl * arvore = cria_arvore_avl(1);
    adiciona_na_arvore_avl(arvore, arvore->raiz, 2);
    adiciona_na_arvore_avl(arvore, arvore->raiz, 3);
    adiciona_na_arvore_avl(arvore, arvore->raiz, 4);
    adiciona_na_arvore_avl(arvore, arvore->raiz, 5);
    adiciona_na_arvore_avl(arvore, arvore->raiz, 6);
    adiciona_na_arvore_avl(arvore, arvore->raiz, 7);
    adiciona_na_arvore_avl(arvore, arvore->raiz, 8);

    
    percorrer_arvore_em_largura_avl(arvore->raiz, print_no);
    printf("\n");
}