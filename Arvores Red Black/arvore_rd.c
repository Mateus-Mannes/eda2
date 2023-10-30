#include "arvore_rd.h"

No *criarNo(Arvore *arvore, No *pai, int valor)
{
    No *no = malloc(sizeof(No));

    no->pai = pai;
    no->valor = valor;
    no->direita = arvore->nulo;
    no->esquerda = arvore->nulo;
    no->cor = Vermelho;
}

void balancear(Arvore *arvore, No *no)
{
    while (no->pai->cor == Vermelho)
    { // Garante que todos os níveis foram balanceados
        if (no->pai == no->pai->pai->esquerda)
        {
            No *tio = no->pai->pai->direita;

            if (tio->cor == Vermelho)
            {
                tio->cor = Preto; // Resolve caso 2
                no->pai->cor = Preto;
                no->pai->pai->cor = Vermelho;
                no = no->pai->pai; // Vai para o nível anterior
            }
            else
            {
                if (no == no->pai->direita)
                {
                    no = no->pai;                   // Vai para o nível anterior
                    rotacionarEsquerda(arvore, no); // Resolve caso 3
                }
                else
                {
                    no->pai->cor = Preto; // Resolve caso 4
                    no->pai->pai->cor = Vermelho;
                    rotacionarDireita(arvore, no->pai->pai);
                }
            }
        }
        else
        {
            No *tio = no->pai->pai->esquerda;

            if (tio->cor == Vermelho)
            {
                tio->cor = Preto; // Resolve caso 2
                no->pai->cor = Preto;
                no->pai->pai->cor = Vermelho;
                no = no->pai->pai; // Vai para o nível anterior
            }
            else
            {
                if (no == no->pai->esquerda)
                {
                    no = no->pai;                   // Vai para o nível anterior
                    rotacionarDireita(arvore, no); // Resolve caso 3
                }
                else
                {
                    no->pai->cor = Preto; // Resolve caso 4
                    no->pai->pai->cor = Vermelho;
                    rotacionarEsquerda(arvore, no->pai->pai);
                }
            }
        }
    }
    arvore->raiz->cor = Preto; // Resolve caso 1
}

void rotacionarEsquerda(Arvore *arvore, No *no)
{
    No *direita = no->direita;
    no->direita = direita->esquerda;
    if (direita->esquerda != arvore->nulo)
        direita->esquerda->pai = no; // Se houver filho à esquerda em direita, ele será pai do nó
    direita->pai = no->pai;          // Ajusta no pai do nó à direita

    if (no->pai == arvore->nulo)
        arvore->raiz = direita; // Se nó for raiz, o nó direita será a nova raiz da árvore
    else if (no == no->pai->esquerda)
        no->pai->esquerda = direita; // Corrige relação pai-filho do novo pai (esquerda)
    else
        no->pai->direita = direita; // Corrige relação pai-filho do novo pai (direita)
    direita->esquerda = no;         // Corrige relação pai-filho entre o nó pivô e o nó à direita
    no->pai = direita;
}

void rotacionarDireita(Arvore *arvore, No *no)
{
    No *esquerda = no->esquerda;
    no->esquerda = esquerda->direita;
    if (esquerda->direita != arvore->nulo)
        esquerda->direita->pai = no; // Se houver filho à direita em esquerda, ele será pai do nó
    esquerda->pai = no->pai;         // Ajusta no pai do nó à esquerda

    if (no->pai == arvore->nulo)
        arvore->raiz = esquerda; // Se nó for raiz, o nó esquerda será a nova raiz da árvore
    else if (no == no->pai->esquerda)
        no->pai->esquerda = esquerda; // Corrige relação pai-filho do novo pai (esquerda)
    else
        no->pai->direita = esquerda; // Corrige relação pai-filho do novo pai (direita)
    esquerda->direita = no;         // Corrige relação pai-filho entre o nó pivô e o nó à esquerda
    no->pai = esquerda;
}