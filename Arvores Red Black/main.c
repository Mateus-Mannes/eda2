#include "arvore_rd.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Arvore * a = criarArvore();
    inserir(a, 4);
    inserir(a, 2);
    inserir(a, 1);
    inserir(a, 3);
    inserir(a, 8);
    inserir(a, 9);
    inserir(a, 6);
    inserir(a, 5);
    inserir(a, 7);
    removerValor(a, 6);
    print_arvore(a->raiz);
    limparArvore(a);
    free(a);
}