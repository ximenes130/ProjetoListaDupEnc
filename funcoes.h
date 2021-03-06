
#define VENDA_REALIZADA          5;
#define VENDA_NAO_REALIZADA      6;
#define PRODUTO_NAO_ENCONTRADO   7;
#define PRODUTO_NAO_ALTERADO     8;
#define PRODUTO_ALTERADO         9;

struct produto{
    int codigo;
    char nome[255];
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
/// Descri��o: Exclui um elemento da lista.
/// Parametros: Produto - Elemento a ser excluido da lista.
void exclui(Produto* produto);

/// Responsavel: Luiz
/// Descri��o: Altera valores de itens da lista de produtos.
///
/// Parametros: Lista       - Lista de produtos;
///             novoProduto - Produto a ser alterado
///             codigo      - codigo do produto para pesquisa
///
/// Retorno: PRODUTO_NAO_ENCONTRADO - Produto n�o foi encontrado;
///          PRODUTO_ALTERADO       - Altera��o realizada com sucesso;
///          PRODUTO_NAO_ALTERADO   - N�o houve altera��o;
///
int alterar(Produto* lista, Produto* novoProduto, int codigo);

/// Responsavel: Luiz
/// Descri��o: Registra a venda de um produto.
///
/// Parametros: Lista - Lista de produtos;
///             novoProduto - Produto a ser alterado;
///             codigo - codigo do produto para pesquisa;
///
/// Retorno: PRODUTO_NAO_ENCONTRADO - Produto n�o foi encontrado;
///          VENDA_NAO_REALIZADA    - Venda n�o realizada pois n�o ha quantidade de produtos a serem vendidos;
///          VENDA_REALIZADA        - Altera��o realizada com sucesso;
///
int vender(Produto* lista, int codigo);
