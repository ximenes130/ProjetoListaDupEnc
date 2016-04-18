
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
/// Descrição: Exclui um elemento da lista.
/// Parametros: Produto - Elemento a ser excluido da lista.
void exclui(Produto* produto);

/// Responsavel: Luiz
/// Descrição: Altera valores de itens da lista de produtos.
///
/// Parametros: Lista       - Lista de produtos;
///             novoProduto - Produto a ser alterado
///             codigo      - codigo do produto para pesquisa
///
/// Retorno: PRODUTO_NAO_ENCONTRADO - Produto não foi encontrado;
///          PRODUTO_ALTERADO       - Alteração realizada com sucesso;
///          PRODUTO_NAO_ALTERADO   - Não houve alteração;
///
int alterar(Produto* lista, Produto* novoProduto, int codigo);

/// Responsavel: Luiz
/// Descrição: Registra a venda de um produto.
///
/// Parametros: Lista - Lista de produtos;
///             novoProduto - Produto a ser alterado;
///             codigo - codigo do produto para pesquisa;
///
/// Retorno: PRODUTO_NAO_ENCONTRADO - Produto não foi encontrado;
///          VENDA_NAO_REALIZADA    - Venda não realizada pois não ha quantidade de produtos a serem vendidos;
///          VENDA_REALIZADA        - Alteração realizada com sucesso;
///
int vender(Produto* lista, int codigo);
