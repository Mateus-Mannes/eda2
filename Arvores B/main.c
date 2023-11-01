#include <stdio.h>
#include "arvoreB.h"
#include <stdlib.h>

int main() {
    ArvoreB * a = criaArvore(1);
    adicionaChave(a, 1);
    adicionaChave(a, 3);
    adicionaChave(a, 5);
    free(a);
}