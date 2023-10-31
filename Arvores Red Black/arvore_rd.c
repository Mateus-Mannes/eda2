#include "arvore_rd.h"
#include <stdio.h>
#include <stdlib.h>

void rotacionarEsquerda(Arvore *arvore, No *no);
void rotacionarDireita(Arvore *arvore, No *no);
void balancear(Arvore *arvore, No *no);

void print_arvore_recursivo(No* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += 10;
 
    // Process right child first
    print_arvore_recursivo(root->direita, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->valor);
 
    // Process left child
    print_arvore_recursivo(root->esquerda, space);
}
 
// Wrapper over print2DUtil()
void print_arvore(No* root)
{
    // Pass initial space count as 0
    print_arvore_recursivo(root, 0);
}

Arvore *criarArvore() {
    Arvore *arvore = (Arvore*) malloc(sizeof(Arvore));
    arvore->nulo = malloc(sizeof(No));
    arvore->nulo->cor = Preto;
    arvore->raiz = arvore->nulo;
    return arvore;
}

No* obterMenorValor(No *inicio, No *nulo) {
    No *atual = inicio;
    while (atual->esquerda != nulo) {
        atual = atual->esquerda;
    }
    return atual;
}

void substituirNo(Arvore *arvore, No *antigoNo, No *novoNo) {
    if (antigoNo->pai == arvore->nulo) {
        arvore->raiz = novoNo;
    } else if (antigoNo == antigoNo->pai->esquerda) {
        antigoNo->pai->esquerda = novoNo;
    } else {
        antigoNo->pai->direita = novoNo;
    }
    novoNo->pai = antigoNo->pai;
}

void corrigirAposRemocao(Arvore *arvore, No *nodoCorrigido) {
    while (nodoCorrigido != arvore->raiz && nodoCorrigido->cor == Preto) {
        if (nodoCorrigido == nodoCorrigido->pai->esquerda) {
            No *irmao = nodoCorrigido->pai->direita;

            // Caso 1: o irmão é vermelho
            if (irmao->cor == Vermelho) {
                irmao->cor = Preto;
                nodoCorrigido->pai->cor = Vermelho;
                rotacionarEsquerda(arvore, nodoCorrigido->pai);
                irmao = nodoCorrigido->pai->direita;
            }

            // Caso 2: Ambos os filhos do irmão são pretos
            if (irmao->esquerda->cor == Preto && irmao->direita->cor == Preto) {
                irmao->cor = Vermelho;
                nodoCorrigido = nodoCorrigido->pai;
            } else {
                // Caso 3: Filho da direita do irmão é preto
                if (irmao->direita->cor == Preto) {
                    irmao->esquerda->cor = Preto;
                    irmao->cor = Vermelho;
                    rotacionarDireita(arvore, irmao);
                    irmao = nodoCorrigido->pai->direita;
                }

                // Caso 4: Filho da direita do irmão é vermelho
                irmao->cor = nodoCorrigido->pai->cor;
                nodoCorrigido->pai->cor = Preto;
                irmao->direita->cor = Preto;
                rotacionarEsquerda(arvore, nodoCorrigido->pai);
                nodoCorrigido = arvore->raiz;
            }
        } else {
            No *irmao = nodoCorrigido->pai->esquerda;

            // Caso 1: o irmão é vermelho
            if (irmao->cor == Vermelho) {
                irmao->cor = Preto;
                nodoCorrigido->pai->cor = Vermelho;
                rotacionarDireita(arvore, nodoCorrigido->pai);
                irmao = nodoCorrigido->pai->esquerda;
            }

            // Caso 2: Ambos os filhos do irmão são pretos
            if (irmao->direita->cor == Preto && irmao->esquerda->cor == Preto) {
                irmao->cor = Vermelho;
                nodoCorrigido = nodoCorrigido->pai;
            } else {
                // Caso 3: Filho da esquerda do irmão é preto
                if (irmao->esquerda->cor == Preto) {
                    irmao->direita->cor = Preto;
                    irmao->cor = Vermelho;
                    rotacionarEsquerda(arvore, irmao);
                    irmao = nodoCorrigido->pai->esquerda;
                }

                // Caso 4: Filho da esquerda do irmão é vermelho
                irmao->cor = nodoCorrigido->pai->cor;
                nodoCorrigido->pai->cor = Preto;
                irmao->esquerda->cor = Preto;
                rotacionarDireita(arvore, nodoCorrigido->pai);
                nodoCorrigido = arvore->raiz;
            }
        }
    }
    nodoCorrigido->cor = Preto;
}

void removerValor(Arvore *arvore, int valorDesejado) {
    No *nodoParaRemover = arvore->raiz;
    while (nodoParaRemover != arvore->nulo && nodoParaRemover->valor != valorDesejado) {
        if (valorDesejado < nodoParaRemover->valor) {
            nodoParaRemover = nodoParaRemover->esquerda;
        } else {
            nodoParaRemover = nodoParaRemover->direita;
        }
    }

    if (nodoParaRemover == arvore->nulo) {
        return; // Não encontrou o valor na árvore.
    }

    No *nodoSubstituto = nodoParaRemover;
    Cor corOriginalSubstituto = nodoSubstituto->cor;
    No *nodoFilho;

    if (nodoParaRemover->esquerda == arvore->nulo) {
        nodoFilho = nodoParaRemover->direita;
        substituirNo(arvore, nodoParaRemover, nodoParaRemover->direita);
    } else if (nodoParaRemover->direita == arvore->nulo) {
        nodoFilho = nodoParaRemover->esquerda;
        substituirNo(arvore, nodoParaRemover, nodoParaRemover->esquerda);
    } else {
        nodoSubstituto = obterMenorValor(nodoParaRemover->direita, arvore->nulo);
        corOriginalSubstituto = nodoSubstituto->cor;
        nodoFilho = nodoSubstituto->direita;

        if (nodoSubstituto->pai == nodoParaRemover) {
            nodoFilho->pai = nodoSubstituto;
        } else {
            substituirNo(arvore, nodoSubstituto, nodoSubstituto->direita);
            nodoSubstituto->direita = nodoParaRemover->direita;
            nodoSubstituto->direita->pai = nodoSubstituto;
        }

        substituirNo(arvore, nodoParaRemover, nodoSubstituto);
        nodoSubstituto->esquerda = nodoParaRemover->esquerda;
        nodoSubstituto->esquerda->pai = nodoSubstituto;
        nodoSubstituto->cor = nodoParaRemover->cor;
    }

    if (corOriginalSubstituto == Preto) {
        corrigirAposRemocao(arvore, nodoFilho);
    }
    free(nodoParaRemover);
}


void inserir(Arvore *arvore, int valor) {
    No *novoNo = criarNo(arvore, arvore->nulo, valor);
    No *pai = arvore->nulo;
    No *interacao = arvore->raiz;

    while (interacao != arvore->nulo) {
        pai = interacao;
        if (novoNo->valor < interacao->valor) {
            interacao = interacao->esquerda;
        } else {
            interacao = interacao->direita;
        }
    }

    novoNo->pai = pai;

    if (pai == arvore->nulo) {
        arvore->raiz = novoNo;
    } else if (novoNo->valor < pai->valor) {
        pai->esquerda = novoNo;
    } else {
        pai->direita = novoNo;
    }

    balancear(arvore, novoNo);
}

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

void limparRecursivamente(No *nodo, No *nulo) {
    if (nodo == nulo) {
        return; // Se o nó é nulo, simplesmente retorna
    }

    limparRecursivamente(nodo->esquerda, nulo);
    limparRecursivamente(nodo->direita, nulo);
    free(nodo);
}

void limparArvore(Arvore *arvore) {
    limparRecursivamente(arvore->raiz, arvore->nulo);
    free(arvore->nulo);
}
