struct produto{
    int codigo;
    char nome[155];
    float valor;
    int qtd;
    struct produto* ant;
    struct produto* prox;

};
typedef struct produto Produto;

/// Descrição: Inicializa a lista encadeada de produto
/// Parametros: p = Endereço da lista a ser inicializada
Produto* inicializa();

/// Descrição: Inicializa a lista encadeada de produto
/// Parametros: p = Endereço da lista a ser inicializada
Produto* instancia();

/// Responsavel: Luana
/// Descrição:
/// Parametros:
Produto* cadastro(Produto* raiz, Produto* novo);
/// Responsavel: Luana
/// Descrição:
/// Parametros:
Produto* consultaCodigo(Produto* raiz,int codigo);
/// Responsavel: Luana
/// Descrição:
/// Parametros:
Produto* consultaNome(Produto* raiz,char* nome);

// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// Responsavel: Abel
/// Descrição:
/// Parametros:
void listarProduto(Produto* raiz);
/// Responsavel: Abel
/// Descrição:
/// Parametros:
void listarProdutoCEstoque(Produto* raiz, int qtd);
/// Responsavel: Abel
/// Descrição:
/// Parametros:
void printProduto(Produto* produto);

// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// Responsavel: Luiz
/// Descrição:
/// Parametros:
Produto* exclui(Produto* produto);
/// Responsavel: Luiz
/// Descrição:
/// Parametros:
Produto* alterar(Produto* produto, Produto* novoProduto);
/// Responsavel: Luiz
/// Descrição:
/// Parametros:
Produto* vender(Produto* produto, float novoValor);
