typedef struct no_avl
{
    struct no_avl *pai;
    struct no_avl *esquerda;
    struct no_avl *direita;
    int altura;
    float valor;
} NoAvl;

typedef struct arvore_avl
{
    struct no_avl *raiz;
} ArvoreAvl;

ArvoreAvl* cria_arvore_avl(float valorRaiz);

NoAvl *adiciona_na_arvore_avl(ArvoreAvl * arvore, NoAvl * no, float valor);

void limpar_arvore_avl(ArvoreAvl *arvore);

NoAvl* remove_na_arvore_avl(ArvoreAvl * arvore , NoAvl* raiz, int valor);

void percorrer_arvore_em_largura_avl(NoAvl* no, void (*callback)(NoAvl*));

void print_arvore_avl(NoAvl* root);