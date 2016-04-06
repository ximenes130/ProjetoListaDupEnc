#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto
{

    int codigo;
    char nome[50];
    float valor;
    int qtd;
    struct produto* ant;
    struct produto* prox;

};
typedef struct produto Produto;

Produto* inicializa(void)
{
    return NULL;
}
Produto* cadastra(Produto* pdt,int codigo,char nome,float valor,int qtd) //CADASTRO
{

    Produto* novo=(Produto*)malloc(sizeof(Produto));
    novo->codigo=codigo;
     /*strcpy(novo->nome,novo.nome);*/
    novo->valor=valor;
    novo->qtd=qtd;
    novo->prox=pdt;
    novo->ant=NULL;
    if(pdt!=NULL)
        pdt->ant=novo;
    return novo;

}

Produto* busca(Produto* pdt,int valor) //CONSULTA POR CODIGO
{

    Produto* aux;

    for(aux=pdt; aux!=NULL; aux=aux->prox)
        if(aux->codigo==valor)
            return aux;
    return NULL;


}

/*Produto* busca_nome(Produto* pdt,char nome){//CONSULTA POR NOME

    Produto* aux;

    for(aux=pdt;aux!=NULL;aux=aux->prox)
    if(aux->nomeProduto==nome)
    return aux;
    return NULL;


    }  */

Produto* imprime(Produto* pdt)
{

    Produto* aux;
    for(aux=pdt; aux!=NULL; aux=aux->ant->prox)
    {
        printf("Codigo:%d",aux->codigo);

    }

}


Produto* retira(Produto* pdt,int valor)
{

    Produto* aux=busca(pdt,valor);
    if(aux==NULL)
        return pdt;
    if(pdt==aux)
        pdt=aux->prox;
    else
        aux->ant->prox=aux->prox;
    if(aux->prox!=NULL)
        aux->prox->ant=aux->ant;
    free(aux);
    return pdt;



}


