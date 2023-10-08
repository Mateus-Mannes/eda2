#include <stdio.h>
#include <stdlib.h>
#include "arvore_avl.h"

ArvoreAvl* cria_arvore_avl() {
    ArvoreAvl* arvore = (ArvoreAvl*) malloc(sizeof(ArvoreAvl));
    if (arvore) {
        arvore->raiz = NULL;
    }
    return arvore;
}

int arvore_vazia_avl(ArvoreAvl* arvore) {
    return (arvore == NULL || arvore->raiz == NULL);
}

NoAvl *adiciona_na_arvore_avl(ArvoreAvl *arvore, NoAvl *pai, float valor) {
    NoAvl *no = (NoAvl*)malloc(sizeof(NoAvl));
    no->pai = pai;
    no->esquerda = NULL;
    no->direita = NULL;
    no->valor = valor;

    if (pai == NULL)
    {
        arvore->raiz = no;
    }
    else 
    {
        if (valor < pai->valor)
            pai->esquerda = no;
        else
            pai->direita = no;
    }
    return no;
}

void remove_na_arvore_avl(ArvoreAvl *arvore, NoAvl *no) {
    if (no->esquerda != NULL)
        remove_na_arvore_avl(arvore, no->esquerda);

    if (no->direita != NULL)
        remove_na_arvore_avl(arvore, no->direita);

    if (no->pai == NULL)
    {
        arvore->raiz = NULL;
    }
    else
    {
        if (no->pai->esquerda == no)
            no->pai->esquerda = NULL;
        else
            no->pai->direita = NULL;
    }
    free(no);
}

void limpar_arvore_avl(ArvoreAvl *arvore) {
    if (arvore->raiz != NULL)
        remove_na_arvore_avl(arvore, arvore->raiz);
    free(arvore);
}

int altura_avl(NoAvl *no)
{
    int esquerda = 0, direita = 0;
    if (no->esquerda != NULL)
    {
        esquerda = altura_avl(no->esquerda) + 1;
    }
    if (no->direita != NULL)
    {
        direita = altura_avl(no->direita) + 1;
    }

    return esquerda > direita ? esquerda : direita;
}

int fb_avl(NoAvl *no)
{
    int esquerda = 0;
    int direita = 0;

    if (no->esquerda != NULL)
    {
        esquerda = altura_avl(no->esquerda) + 1;
    }
    if (no->direita != NULL)
    {
        direita = altura_avl(no->direita) + 1;
    }

    return esquerda - direita;
}

NoAvl *rse_avl(NoAvl *no)
{
    NoAvl *pai = no->pai;
    NoAvl *direita = no->direita;

    no->direita = direita->esquerda;
    no->pai = direita;
    direita->esquerda = no;
    direita->pai = pai;

    return direita;
}

NoAvl *rsd(NoAvl *no)
{
    NoAvl *pai = no->pai;
    NoAvl *esquerda = no->esquerda;

    no->esquerda = esquerda->direita;
    no->pai = esquerda;

    esquerda->direita = no;
    esquerda->pai = pai;

    return esquerda;
}

NoAvl* rde_avl(NoAvl* no) {
    no->direita = rsd_avl(no->direita);
    return rse_avl(no);
}


NoAvl* rdd_avl(NoAvl* no) {
    no->esquerda = rsd_avl(no->esquerda);
    return rse_avl(no);
}