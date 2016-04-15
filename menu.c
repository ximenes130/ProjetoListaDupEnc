#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

char* _resposta = "";

/*void menu_exclusao(){


    system("cls");

    Produto* novo;

    int codigo,op;

    printf("--------EXCLUSAO-----------");

    printf("\n\nDigite codigo do produto :");
    scanf("%d",&codigo);

    exclui(novo,codigo);
    imprime(novo);
}*/

void menu_listagemqtd()
{


    system("cls");


    int qtd,op;

    printf("--------LISTAGEM POR QUANTIDADE-----------");

    printf("\n\nDigite quantidade :");
    scanf("%d",&qtd);
}

void menu_consultanome()
{


    system("cls");


    int op;
    char nome[50];

    printf("--------CONSULTA POR NOME-----------");

    printf("\n\nDigite o nome do produto :");
    scanf("%c",&nome);
}

/*void menu_consultacodigo()
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

}*/

Produto* menu_cadastro(Produto* p){

    Produto* novo = instancia();

   // system("cls");

    printf("\n--------CADASTRO-----------");

    printf("\n\nDigite codigo:");
    scanf("%d",&(novo->codigo));
    printf("\nDigite nome do produto:");
    fflush(stdin);
    scanf("%s",novo->nome);
    printf("\nDigite valor do produto:");
    scanf("%f",&(novo->valor));
    printf("\nDigite quantidade do produto:");
    scanf("%d",&(novo->qtd));

    _resposta = "\n\nProduto cadastrado!\n\n";

     return cadastro(p,novo);
}

void menu()
{
    Produto* lista = inicializa();
    char op;

    do{
        system("cls");
        printf("-------VENDAS---------\n\n");
        printf("\n 01-Cadastro");
        printf("\n 02-Consulta por Codigo");
        printf("\n 03-Consulta por Nome");
        printf("\n 04-Listagem");
        printf("\n 05-Listagem Quantidade");
        printf("\n 06-Alteracao");
        printf("\n 07-Exclusao");
        printf("\n 08-Venda\n");
        printf("\nesc-Sair\n");

        //printf("\nUltimo produto cadastrado: %s\n",p->nome);

        printf("%s",_resposta);

        printf("\nEscolha uma opcao:");

        fflush(stdin);
        op = getch();

        switch(op)
        {
        case '1':
            lista = menu_cadastro(lista);
            break;
        case '2':
            //menu_consultacodigo();
            break;
        case '3':
            //menu_consultanome();
            break;
        case '5':
            //menu_listagemqtd();
            break;
        case '7':
            //menu_exclusao();
            break;
        }

    }while(op != 27);


}
