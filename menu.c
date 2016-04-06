#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


void menu_exclusao()
{


    system("cls");

    Produto* novo;

    int codigo,op;

    printf("--------EXCLUSAO-----------");

    printf("\n\nDigite codigo do produto :");
    scanf("%d",&codigo);

    retira(novo,codigo);
    imprime(novo);

    printf("\n\n0-Voltar");
    printf("\n1-Sair");
    scanf("%d",&op);

    switch(op)
    {

    case 0 :
        menu();
        break;
    case 1 :
        return 0;
        break;
    }

}

void menu_listagemqtd()
{


    system("cls");


    int qtd,op;

    printf("--------LISTAGEM POR QUANTIDADE-----------");

    printf("\n\nDigite quantidade :");
    scanf("%d",&qtd);

    /*FUNCAO*/////////////////////////////////////

    printf("\n\n0-Voltar");
    printf("\n1-Sair");
    scanf("%d",&op);

    switch(op)
    {

    case 0 :
        menu();
        break;
    case 1 :
        return 0;
        break;
    }

}

void menu_consultanome()
{


    system("cls");


    int op;
    char nome[50];

    printf("--------CONSULTA POR NOME-----------");

    printf("\n\nDigite o nome do produto :");
    scanf("%c",&nome);

    /*FUNCAO*/////////////////////////////////////////

    printf("\n\n0-Voltar");
    printf("\n1-Sair");
    scanf("%d",&op);

    switch(op)
    {

    case 0 :
        menu();
        break;
    case 1 :
        return 0;
        break;
    }

}

void menu_consultacodigo()
{


    system("cls");

    Produto* novo;
    int valor,op;

    printf("--------CONSULTA POR CODIGO-----------");

    printf("\n\nDigite o codigo de busca :");
    scanf("%d",&valor);

    busca(novo,valor);
    imprime(novo);

    printf("\n\n0-Voltar");
    printf("\n1-Sair");
    scanf("%d",&op);

    switch(op)
    {

    case 0 :
        menu();
        break;
    case 1 :
        return 0;
        break;
    }

}

void menu_cadastro()
{

    int codigo,qtd,op;
    char nome[50];
    float valor;
    Produto* novo;
    novo=inicializa();

    system("cls");

    printf("--------CADASTRO-----------");

    printf("\n\nDigite codigo");
    scanf("%d",&codigo);
    printf("\nDigite nome do produto:");
    scanf("%c",&nome);
    printf("\nDigite valor do produto:");
    scanf("%f",&valor);
    printf("\nDigite quantidade do produto:");
    scanf("%d",&qtd);

    /*FUNCAO*/////////////////////////////////////////

    printf("\n\n0-Voltar");
    printf("\n1-Sair");
    scanf("%d",&op);

    switch(op)
    {

    case 0 :
        menu();
        break;
    case 1 :
        return 0;
        break;
    }

}

void menu()
{

    int op;

    system("cls");
    printf("-------VENDAS---------\n\n");
    printf("\n01-Cadastro");
    printf("\n02-Consulta por Codigo");
    printf("\n03-Consulta por Nome");
    printf("\n04-Listagem");
    printf("\n05-Listagem Quantidade");
    printf("\n06-Alteracao");
    printf("\n07-Exclusao");
    printf("\n08-Venda\n");
    printf("\n0-Sair\n\n");
    printf("\nEscolha uma opcao:");
    scanf("%d",&op);

    switch(op)
    {
    case 1:
        menu_cadastro();
        break;
    case 2:
        menu_consultacodigo();
        break;
    case 3:
        menu_consultanome();
        break;
    case 5:
        menu_listagemqtd();
        break;
    case 7:
        menu_exclusao();
        break;
    case 0:
        return 0;
        break;
    }


}
