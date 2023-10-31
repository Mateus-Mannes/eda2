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

void limparArvore(Arvore *arvore);

Arvore *criarArvore();
void print_arvore(No* root);
No *criarNo(Arvore *arvore, No *pai, int valor);
void inserir(Arvore *arvore, int valor);
void removerValor(Arvore *arvore, int valorDesejado);