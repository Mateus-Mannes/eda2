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
    
}

void remove_na_arvore_avl(ArvoreAvl *arvore, NoAvl *no) {
    
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
    no->pai = direita;
    direita->esquerda = no;
    direita->pai = pai;

    if(arvore->raiz == no) arvore->raiz = direita;

    return direita;
}

NoAvl *rsd(NoAvl *no, ArvoreAvl * arvore)
{
    NoAvl *pai = no->pai;
    NoAvl *esquerda = no->esquerda;

    no->esquerda = esquerda->direita;
    no->pai = esquerda;

    esquerda->direita = no;
    esquerda->pai = pai;

    if(arvore->raiz == no) arvore->raiz = esquerda;

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