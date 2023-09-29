#include "arvore.h"
#include <stdlib.h>

int main() {
    // COMO FUNCIONA A COMPILACAO ?
    Arvore *arvore = cria_arvore();
    free(arvore);
    return 0;
}