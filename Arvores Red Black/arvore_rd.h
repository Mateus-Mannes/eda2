enum coloracao { Vermelho, Preto };

typedef enum coloracao Cor;

typedef struct no
{
    struct no *pai;
    struct no *esquerda;
    struct no *direita;
    Cor cor;
    int valor;
} No;

typedef struct arvore
{
    struct no *raiz;
    struct no *nulo;
} Arvore;

No *criarNo(Arvore *arvore, No *pai, int valor);