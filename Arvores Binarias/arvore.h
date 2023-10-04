typedef struct no
{
    struct no *pai;
    struct no *esquerda;
    struct no *direita;
    float valor;
} No;

typedef struct arvore
{
    struct no *raiz;
} Arvore;

Arvore* cria_arvore();

int arvore_vazia(Arvore* arvore);

No* adiciona_na_arvore(Arvore* arvore, No* pai, float valor);

void remove_na_arvore(Arvore* arvore, No* no);

void percorrer_arvore_pre_order(No* no, void (*callback)(No*));
void percorrer_arvore_in_order(No* no, void (*callback)(No*));
void percorrer_arvore_pos_order(No* no, void (*callback)(No*));

void percorrer_arvore_em_largura(No* no, void (*callback)(No*));

No * adiciona_na_arvore_ordenado(Arvore* arvore, float valor);

void limpa_arvore(Arvore* arvore);

void limpar_arvore(Arvore* arvore);


