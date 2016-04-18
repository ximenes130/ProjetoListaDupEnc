
#define VENDA_REALIZADA          5;
#define VENDA_NAO_REALIZADA      6;
#define PRODUTO_NAO_ENCONTRADO   7;
#define PRODUTO_NAO_ALTERADO     8;
#define PRODUTO_ALTERADO         9;

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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// Responsavel: Luana
/// Descrição:Cadastra o produto no sistema.
/// Parametros:raiz = Endereço da lista a ser inicializada; novo = Novo produto cadastrado no sistema.
Produto* cadastro(Produto* raiz, Produto* novo);

/// Responsavel: Luana
/// Descrição:Busca o produto a partir do codigo.
/// Parametros:raiz = Endereço da lista a ser inicializada; codigo = Codigo que será pesquisado.
Produto* consultaCodigo(Produto* raiz,int codigo);

/// Responsavel: Luana
/// Descrição:Busca o produto a partir do nome.
/// Parametros:raiz = Endereço da lista a ser inicializada; nome = Nome que será pesquisado.
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
Produto* exclui(Produto* produto);
/// Responsavel: Luiz
/// Descrição: Altera valores de itens da lista de produtos
/// Parametros: Lista - Lista de produtos;
///             novoProduto - Produto a ser alterado
///             codigo - codigo do produto para pesquisa
int alterar(Produto* lista, Produto* novoProduto, int codigo);
/// Responsavel: Luiz
/// Descrição:
/// Parametros:
int vender(Produto* lista, int codigo);
