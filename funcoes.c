#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

Produto* inicializa(){
    return (Produto*) malloc(sizeof(Produto));
}

/// Responsavel: Luana
/// Descri��o:
/// Parametros:
Produto* cadastro(Produto* raiz, Produto* novo){
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
    if(aux->nome==nome)
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
Produto* exclui(Produto* produto){
    Produto* aux;

    if(produto->prox != NULL)
        produto->prox->ant = produto->ant;
    else
        produto->ant->prox = NULL;

    if(produto->ant != NULL){
        produto->ant->prox = produto->prox;
        aux = produto->ant;
    }
    else{
        produto->prox->ant = NULL;
        aux = produto->prox;
    }

    free(produto);
    return aux;
}

/// Responsavel: Luiz
/// Descri��o:
/// Parametros:
Produto* alterar(Produto* produto, Produto* novoProduto);

/// Responsavel: Luiz
/// Descri��o:
/// Parametros:
Produto* vender(Produto* produto, float novoValor);
