#include <stdio.h>  
#include <stdlib.h>
#include "arvore.h"

void print_no(No* no) {
    printf("%.2f, ", no->valor);
}

int main() {
    Arvore *arvore = cria_arvore();
    adiciona_na_arvore_ordenado(arvore, 4);
    adiciona_na_arvore_ordenado(arvore, 2);
    adiciona_na_arvore_ordenado(arvore, 1);
    adiciona_na_arvore_ordenado(arvore, 3);
    adiciona_na_arvore_ordenado(arvore, 8);
    adiciona_na_arvore_ordenado(arvore, 9);
    adiciona_na_arvore_ordenado(arvore, 6);
    adiciona_na_arvore_ordenado(arvore, 5);
    adiciona_na_arvore_ordenado(arvore, 7);

    percorrer_arvore_em_largura(arvore->raiz, print_no);
}