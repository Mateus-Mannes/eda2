typedef struct no_avl
{
    struct no_avl *pai;
    struct no_avl *esquerda;
    struct no_avl *direita;
    float valor;
} NoAvl;

typedef struct arvore_avl
{
    struct no_avl *raiz;
} ArvoreAvl;

ArvoreAvl* cria_arvore_avl();

int arvore_vazia_avl(ArvoreAvl* arvore);

NoAvl* adiciona_na_arvore_avl(ArvoreAvl* arvore, NoAvl* pai, float valor);

void remove_na_arvore_avl(ArvoreAvl* arvore, NoAvl* no);

void limpar_arvore_avl(ArvoreAvl* arvore);

int altura_avl(NoAvl* no);

int fb_avl(NoAvl* no);

NoAvl* rse_avl(NoAvl* no);

NoAvl* rsd_avl(NoAvl* no);

NoAvl* rde_avl(NoAvl* no);

NoAvl* rdd_avl(NoAvl* no);