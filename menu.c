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

void menu_consultanome(Produto* lista){
    system("cls");

    Produto* p;
    char nome[255];

    printf("--------CONSULTA POR NOME-----------");

    printf("\n\nDigite o nome do produto :");
    fflush(stdin);
    gets(&nome);
    printf("\nnome:   %s",nome);

    p = consultaNome(lista, nome);

    if(p != NULL)
        sprintf(_resposta, "\n\nProduto Encontrado!\n    nome:   %s\n    codigo: %d",p->nome,p->codigo);
    else
        sprintf(_resposta, "\n\nProduto nao encontrado!");
}

void menu_consultacodigo(Produto* lista){
    system("cls");

    Produto* p;
    int codigo;

    printf("--------CONSULTA POR CODIGO-----------");

    printf("\n\nDigite o codigo de busca :");
    scanf("%d",&codigo);

    p = consultaCodigo(lista, codigo);

    if(p != NULL)
        sprintf(_resposta, "\n\nProduto Encontrado!\n    nome:   %s\n    codigo: %d\n    qtd: %d",p->nome,p->codigo,p->qtd);
    else
        sprintf(_resposta, "\n\nProduto nao encontrado!");
}

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

void menu_alterarProduto(Produto* lista){
    system("cls");

    Produto* novo = instancia();
    int codigo;

    printf("--------ALTERACAO DE PRODUTO-----------");

    printf("\n\nDigite o codigo do produto:");
    scanf("%d",&codigo);

    printf("\n\nDigite o novo codigo:");
    scanf("%d",&(novo->codigo));
    printf("\nDigite o novo nome do produto:");
    fflush(stdin);
    gets(&(novo->nome));
    printf("\nDigite o novo valor do produto:");
    scanf("%f",&(novo->valor));
    printf("\nDigite a novo quantidade do produto:");
    scanf("%d",&(novo->qtd));

    switch(alterar(lista,novo,codigo)){
    case 9:
        sprintf(_resposta, "Produto alterado com sucesso!\n    nome:   %s\n    codigo: %d",lista->nome,lista->codigo);
        break;
    case 8:
        sprintf(_resposta, "Produto nao pode ser alterado!");
        break;
    case 7:
        sprintf(_resposta, "Produto nao encontrado!");
        break;
    }
}

void menu_excluirProduto(Produto* lista){
    system("cls");

    Produto* p;
    int codigo;

    printf("--------EXCLUSAO DE PRODUTO-----------");

    printf("\n\nDigite o codigo do produto:");
    scanf("%d",&codigo);

    p = consultaCodigo(lista, codigo);

    if(p != NULL){
        sprintf(_resposta, "Produto excluido com sucesso!\n    nome:   %s\n    codigo: %d",p->nome,p->codigo);

        exclui(p);
    }else
        sprintf(_resposta, "Produto nao encontrado!\n    codigo: %d",codigo);
}

void menu_venderProduto(Produto* lista){
    system("cls");

    Produto* p;
    int codigo;

    printf("--------VENDA DE PRODUTO-----------");

    printf("\n\nDigite o codigo do produto:");
    scanf("%d",&codigo);

    switch(vender(lista, codigo)){
        case 5:  // Realizada
            sprintf(_resposta, "Produto vendido com sucesso!\n    codigo: %d",codigo);
            break;
        case 6:  // Nao realizada
            sprintf(_resposta, "Venda nao realizada!\n    codigo: %d",codigo);
            break;
        case 7:  // Nao encontrada
            sprintf(_resposta, "Produto nao encontrado!\n    codigo: %d",codigo);
            break;
    }
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
            menu_consultacodigo(lista);
            break;
        case '3':
            menu_consultanome(lista);
            break;
        case '5':
            //menu_listagemqtd();
            break;
        case '6':
            menu_alterarProduto(lista);
            break;
        case '7':
            menu_excluirProduto(lista);
            break;
        case '8':
            menu_venderProduto(lista);
            break;
        }

    }while(op != 27);


}
