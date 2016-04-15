struct produto{
    int codigo;
    char nome[155];
    float valor;
    int qtd;
    struct produto* ant;
    struct produto* prox;

};
typedef struct produto Produto;

/// Descri��o: Inicializa a lista encadeada de produto
/// Parametros: p = Endere�o da lista a ser inicializada
Produto* inicializa();

/// Descri��o: Inicializa a lista encadeada de produto
/// Parametros: p = Endere�o da lista a ser inicializada
Produto* instancia();

/// Responsavel: Luana
/// Descri��o:
/// Parametros:
Produto* cadastro(Produto* raiz, Produto* novo);
/// Responsavel: Luana
/// Descri��o:
/// Parametros:
Produto* consultaCodigo(Produto* raiz,int codigo);
/// Responsavel: Luana
/// Descri��o:
/// Parametros:
Produto* consultaNome(Produto* raiz,char* nome);

// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// Responsavel: Abel
/// Descri��o:
/// Parametros:
void listarProduto(Produto* raiz);
/// Responsavel: Abel
/// Descri��o:
/// Parametros:
void listarProdutoCEstoque(Produto* raiz, int qtd);
/// Responsavel: Abel
/// Descri��o:
/// Parametros:
void printProduto(Produto* produto);

// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// Responsavel: Luiz
/// Descri��o:
/// Parametros:
Produto* exclui(Produto* produto);
/// Responsavel: Luiz
/// Descri��o:
/// Parametros:
Produto* alterar(Produto* produto, Produto* novoProduto);
/// Responsavel: Luiz
/// Descri��o:
/// Parametros:
Produto* vender(Produto* produto, float novoValor);
