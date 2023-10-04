#include <stdio.h>  
#include <stdlib.h>
#include "arvore.h"

int main() {
    Arvore *arvore = cria_arvore();
    No * raiz = adiciona_na_arvore(arvore, NULL, 4);
    No * n1 = adiciona_na_arvore(arvore, raiz, 2);
    No * n2 = adiciona_na_arvore(arvore, raiz, 8);
    No * n3 = adiciona_na_arvore(arvore, n1, 1);
    No * n4 = adiciona_na_arvore(arvore, n1, 3);
    No * n5 = adiciona_na_arvore(arvore, n2, 6);
    No * n6 = adiciona_na_arvore(arvore, n2, 9);
    No * n7 = adiciona_na_arvore(arvore, n5, 5);
    No * n8 = adiciona_na_arvore(arvore, n5, 7);

    
    printf("Numero de comparacoes: %d\n", contador);
}