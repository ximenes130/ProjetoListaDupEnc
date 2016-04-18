#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

Produto* inicializa(){
    return NULL;
}

Produto* instancia(){
    Produto* p = (Produto*) malloc(sizeof(Produto));
    p->prox = NULL;
    p->ant  = NULL;

    return p;
}

/// Responsavel: Luana
/// Descri��o:
/// Parametros:
Produto* cadastro(Produto* raiz, Produto* novo){
    printf("foi: %s",novo->nome);

    if(raiz != NULL){
        novo->prox = raiz;
        raiz->ant  = novo;
    }

    return novo;

}

/// Responsavel: Luana
/// Descri��o:
/// Parametros:
Produto* consultaCodigo(Produto* raiz,int codigo){

    Produto* aux;

    for(aux=raiz; aux!=NULL; aux=aux->prox)
        if(aux->codigo == codigo)
            return aux;
    return NULL;
}
/// Responsavel: Luana
/// Descri��o:
/// Parametros:
Produto* consultaNome(Produto* raiz,char* nome){

    Produto* aux;

    for(aux=raiz;aux!=NULL;aux=aux->prox)
        if(strcmp(aux->nome,nome) == 0)
            return aux;

    return NULL;
}

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
/// Descri��o: Imprime todos os atributos do produto recebido por parametro.
/// Parametros: produto = Produto a ser impresso.
void printProduto(Produto* produto);

// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// Responsavel: Luiz
/// Descri��o: Exclui um elemento da lista.
/// Parametros: Produto - Elemento a ser excluido da lista.
void exclui(Produto* produto){
    Produto* aux = NULL;

    if(produto == NULL)
        return;

    if(produto->prox != NULL)
        produto->prox->ant = produto->ant;
    else if(produto->ant != NULL)
        produto->ant->prox = NULL;

    if(produto->ant != NULL){
        produto->ant->prox = produto->prox;
        aux = produto->ant;
    }else if(produto->prox != NULL){
        produto->prox->ant = NULL;
        aux = produto->prox;
    }

    free(produto);
}

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
int alterar(Produto* lista, Produto* novoProduto, int codigo){

    Produto* p = consultaCodigo(lista, codigo);

    if(p == NULL)
        return PRODUTO_NAO_ENCONTRADO;

    if(novoProduto == NULL)
        return PRODUTO_NAO_ALTERADO;

    p->codigo = novoProduto->codigo;
    strcpy(p->nome, novoProduto->nome);
    p->qtd    = novoProduto->qtd;
    p->valor  = novoProduto->valor;

    return PRODUTO_ALTERADO;
}

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
int vender(Produto* lista, int codigo){
    Produto* p = consultaCodigo(lista, codigo);

    if(p == NULL)
         return PRODUTO_NAO_ENCONTRADO;

    if(lista->qtd <= 0)
        return VENDA_NAO_REALIZADA;

    p->qtd--;

    return VENDA_REALIZADA;
}
