#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

void print_no(No* no) {
    printf("%f\n", no->valor);
}

int main() {
    // COMO FUNCIONA A COMPILACAO ?
    Arvore *arvore = cria_arvore();
    adiciona_na_arvore(arvore, NULL, 10);
    adiciona_na_arvore(arvore, arvore->raiz, 5);
    adiciona_na_arvore(arvore, arvore->raiz, 15);
    percorrer_arvore_in_order(arvore->raiz, print_no);
    limpar_arvore(arvore);
    return 0;
}