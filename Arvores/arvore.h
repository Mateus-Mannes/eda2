typedef struct no
{
    struct no *pai;      // ponteiro para o nó pai
    struct no *esquerda; // ponteiro para o nó filho a esquerda
    struct no *direita;  // ponteiro para o nó filho a direita
    float valor;             // conteúdo de um nó arbitrário da árvore
} No;

typedef struct arvore
{
    struct no *raiz;
} Arvore;

Arvore* cria_arvore();

int arvore_vazia(Arvore* arvore);

No* adiciona_na_arvore(Arvore* arvore, No* pai, float valor);

void remove_na_arvore(Arvore* arvore, No* no);

void percorrer_arvore(No* no);

void limpa_arvore(Arvore* arvore);



