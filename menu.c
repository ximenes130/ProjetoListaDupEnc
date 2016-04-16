#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

char _resposta[155];

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

    system("cls");

    printf("\n--------CADASTRO-----------");

    printf("\n\nDigite codigo:");
    scanf("%d",&(novo->codigo));
    printf("\nDigite nome do produto:");
    fflush(stdin);
    gets(&(novo->nome));
    printf("\nDigite valor do produto:");
    scanf("%f",&(novo->valor));
    printf("\nDigite quantidade do produto:");
    scanf("%d",&(novo->qtd));

    sprintf(_resposta, "\n\nProduto cadastrado com sucesso!\n    nome:   %s\n    codigo: %d",novo->nome,novo->codigo);

    return cadastro(p,novo);
}

Produto* menu_exclusao(Produto* lista){
    Produto* r = NULL;

    if(lista != NULL){ // Se existe produto a ser excluido
        sprintf(_resposta, "Produto excluido com sucesso\n    nome:   %s\n    codigo: %d",lista->nome,lista->codigo);

        r = exclui(lista);// TODO: Utilizar sistema de busca por codigo
    }else{
        strcpy(_resposta, "Não houve produto para ser excluido");
    }

    return r;
}

void menu()
{
    Produto* lista = inicializa();
    char op;

    do{
        system("cls");

        printf("\n      _________ __         ____   ____                  ___                 ");
        printf("\n     /   _____/|__| ______ \\   \\ /   /____   ____    __| _/____    ______   ");
        printf("\n     \\_____  \\ |  |/  ___/  \\   Y   // __ \\ /    \\  / __ |\\__  \\  /  ___/   ");
        printf("\n     /        \\|  |\\___ \\    \\     /\\  ___/|   |  \\/ /_/ | / __ \\_\\___ \\    ");
        printf("\n    /_______  /|__/____  >    \\___/  \\___  >___|  /\\____ |(____  /____  >   ");
        printf("\n            \\/         \\/                \\/     \\/      \\/     \\/     \\/    ");
        printf("\n________________________________________________________________________________");

        printf("\n      01-Cadastro");
        printf("\n      02-Consulta por Codigo");
        printf("\n      03-Consulta por Nome");
        printf("\n      04-Listagem");
        printf("\n      05-Listagem Quantidade");
        printf("\n      06-Alteracao");
        printf("\n      07-Exclusao");
        printf("\n      08-Venda\n");
        printf("\n     esc-Sair\n");

        //printf("\nUltimo produto cadastrado: %s\n",p->nome);

        printf("\n%s\n",_resposta);
        strcpy(_resposta, "");

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
            lista = menu_exclusao(lista);
            break;
        }

    }while(op != 27);


}
