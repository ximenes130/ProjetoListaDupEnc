/*
 cadastro
 consulta por código
 consulta por nome do produto

 listagem (de todos os produtos cadastrados)
 listagem (de todos os produtos com quantidade abaixo de um valor fornecido)


 exclusão
 alteração
 venda (imprimir o total da venda. Fazer o controle da quantidade)

*/

struct produto{
    int codigo;
    char* nome;
    float valor;
    int qtd;
    struct produto* ant;
    struct produto* prox;

};
typedef struct produto Produto;

/// Descrição: Inicializa a lista encadeada de produto
/// Parametros: p = Endereço da lista a ser inicializada
Produto* inicializa();

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
Produto* exclui(Produto* produto);
/// Responsavel: Luiz
/// Descrição:
/// Parametros:
Produto* alterar(Produto* produto, Produto* novoProduto);
/// Responsavel: Luiz
/// Descrição:
/// Parametros:
Produto* vender(Produto* produto, float novoValor);
