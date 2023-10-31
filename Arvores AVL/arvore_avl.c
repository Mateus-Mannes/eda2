#include <stdio.h>
#include <stdlib.h>
#include "arvore_avl.h"
#include "fila.h"

// metodos privados
NoAvl * novo_no(float valor);
int fator_balanceamento(NoAvl *no);
int altura(NoAvl *no);
int max(float a, float b);
NoAvl *rse(NoAvl *no, ArvoreAvl * arvore);
NoAvl *rsd(NoAvl *no, ArvoreAvl * arvore);
NoAvl* rde(NoAvl* no, ArvoreAvl * arvore);
NoAvl* rdd(NoAvl* no, ArvoreAvl * arvore);


ArvoreAvl* cria_arvore_avl(float valorRaiz) {
    ArvoreAvl* arvore = (ArvoreAvl*) malloc(sizeof(ArvoreAvl));
    if (arvore) {
        arvore->raiz = novo_no(valorRaiz);
    }
    return arvore;
}

NoAvl *adiciona_na_arvore_avl(ArvoreAvl * arvore, NoAvl * no , float valor) {

    if (no == NULL) 
        return(novo_no(valor)); 
  
    if (valor < no->valor) {
        no->esquerda  = adiciona_na_arvore_avl(arvore, no->esquerda, valor); 
        no->esquerda->pai = no;
    }
    else if (valor > no->valor) {
        no->direita = adiciona_na_arvore_avl(arvore, no->direita, valor);
        no->direita->pai = no;
    }
    else return no; 
  
    no->altura = 1 + max(altura(no->esquerda), altura(no->direita)); 
  
    int fb = fator_balanceamento(no);
  
    if (fb > 1 && valor < no->esquerda->valor) 
        return rsd(no, arvore); 
  
    if (fb < -1 && valor > no->direita->valor) 
        return rse(no, arvore); 
  
    if (fb > 1 && valor > no->esquerda->valor) 
        rdd(no, arvore);
   
    if (fb < -1 && valor < no->direita->valor) 
        rde(no, arvore);
  
    return no; 
}

void limpar_arvore_avl(ArvoreAvl *arvore) {
    // TODO
}

NoAvl * minValueNode(NoAvl* no) 
{ 
    NoAvl* current = no; 
 
    while (current->esquerda != NULL) 
        current = current->esquerda; 
 
    return current; 
} 

NoAvl* remove_na_arvore_avl(ArvoreAvl * arvore , NoAvl* raiz, int valor) 
{ 
    if (raiz == NULL) 
        return raiz; 
 
    if ( valor < raiz->valor ) 
        raiz->esquerda = remove_na_arvore_avl(arvore, raiz->esquerda, valor); 
    else if( valor > raiz->valor ) 
        raiz->direita = remove_na_arvore_avl(arvore, raiz->direita, valor); 
    else
    { 
        if( (raiz->esquerda == NULL) ||
            (raiz->direita == NULL) ) 
        { 
            Node *noDeletar = raiz->esquerda ? 
                         raiz->esquerda : 
                         raiz->direita; 
 
            if (noDeletar == NULL) 
            { 
                noDeletar = raiz; 
                raiz = NULL; 
            } 
            else 
            {
                NoAvl * temp = raiz;
                raiz = noDeletar;
                noDeletar = temp;
            } 
            free(noDeletar); 
        } 
        else
        { 
            NoAvl* temp = minValueNode(raiz->direita); 
 
            raiz->valor = temp->valor; 
 
            raiz->direita = remove_na_arvore_avl(arvore, raiz->direita, temp->valor); 
        } 
    } 
  
    if (raiz == NULL) return raiz; 
  
    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita)); 
 
    int fb = fator_balanceamento(raiz); 
 
    if (fb > 1 && fator_balanceamento(raiz->esquerda) >= 0) 
        return rsd(raiz, arvore); 
 
    if (fb > 1 && fator_balanceamento(raiz->esquerda) < 0) 
        return rdd(raiz, arvore); 
 
    if (fb < -1 && fator_balanceamento(raiz->direita) <= 0) 
        return rse(raiz, arvore); 
 
    if (fb < -1 && fator_balanceamento(raiz->direita) > 0) 
        return rde(raiz, arvore);
 
    return raiz; 
} 

void noopFreeFunction(void* data) {
    // Do nothing
}

void percorrer_arvore_em_largura_avl(NoAvl* no, void (*callback)(NoAvl*)) {
    Queue fila;
    initializeQueue(&fila);
    enqueue(&fila, no);
    while (!queueIsEmpty(&fila))
    {
        NoAvl *no = dequeue(&fila);
        callback(no);
        if (no->esquerda != NULL)
            enqueue(&fila, no->esquerda);
        if (no->direita != NULL)
            enqueue(&fila, no->direita);
    }
    freeQueue(&fila, noopFreeFunction);
}


NoAvl * novo_no(float valor) 
{ 
    NoAvl *no = (NoAvl*)malloc(sizeof(NoAvl));
    no->pai = NULL;
    no->esquerda = NULL;
    no->direita = NULL;
    no->valor = valor; 
    no->altura = 1; // intancia um novo no como folha
}

int fator_balanceamento(NoAvl *no)
{
    if (no == NULL) 
        return 0; 
    return altura(no->esquerda) - altura(no->direita); 
}

int altura(NoAvl *no)
{
    if(no == NULL) return 0;
    return no->altura;
}

int max(float a, float b) 
{ 
    return (a > b)? a : b; 
} 

NoAvl *rse(NoAvl *no, ArvoreAvl * arvore)
{
    NoAvl *pai = no->pai;
    NoAvl *direita = no->direita;

    no->direita = direita->esquerda;
    if(no->direita != NULL) no->direita->pai = no;

    no->pai = direita;
    direita->esquerda = no;
    direita->pai = pai;

    if(arvore->raiz == no) arvore->raiz = direita;

    no->altura = max(altura(no->esquerda), 
                    altura(no->direita)) + 1; 
    direita->altura = max(altura(direita->esquerda), 
                    altura(direita->direita)) + 1; 

    return direita;
}

NoAvl *rsd(NoAvl *no, ArvoreAvl * arvore)
{
    NoAvl *pai = no->pai;
    NoAvl *esquerda = no->esquerda;

    no->esquerda = esquerda->direita;
    if(no->esquerda != NULL) no->esquerda->pai = no;

    no->pai = esquerda;
    esquerda->direita = no;
    esquerda->pai = pai;

    if(arvore->raiz == no) arvore->raiz = esquerda;

    no->altura = max(altura(no->esquerda), 
                    altura(no->direita)) + 1; 
    esquerda->altura = max(altura(esquerda->esquerda), 
                    altura(esquerda->direita)) + 1;

    return esquerda;
}

NoAvl* rde(NoAvl* no, ArvoreAvl * arvore) {
    no->direita = rsd(no->direita, arvore);
    return rse(no, arvore);
}


NoAvl* rdd(NoAvl* no, ArvoreAvl * arvore) {
    no->esquerda = rsd(no->esquerda, arvore);
    return rse(no, arvore);
}

void print_arvore_avl_recursivo(NoAvl* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += 10;
 
    // Process right child first
    print_arvore_avl_recursivo(root->direita, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%.0f\n", root->valor);
 
    // Process left child
    print_arvore_avl_recursivo(root->esquerda, space);
}
 
// Wrapper over print2DUtil()
void print_arvore_avl(NoAvl* root)
{
    // Pass initial space count as 0
    print_arvore_avl_recursivo(root, 0);
}