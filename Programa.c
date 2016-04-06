#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

 typedef struct lista{
     char nome[40];
     char endereco[40];
     unsigned long int codigo;
     struct lista* prox;   
   }Lista;
   
   //Declara��o de fun��es.
   Lista* inserir_restaurantes(Lista* primeiro);
   void listar_restaurantes(Lista* primeiro);
   Lista* excluir_restaurantes(Lista* primeiro);
   void alterar_restaurantes(Lista* primeiro);

main() 
{ 
   //Declara��o de vari�veis
   Lista *primeiro= NULL;
   char opcao;
     
   //Artif�cio para repetir o programa.
   while(opcao!='s')   
   {  
     //Menu de opcoes 
      printf(" %c----------------------------------------------------------------------------%c\n",201,187);
      printf(" | ");printf("\t\t\t     CADASTRO DE RESTAURANTES");printf("\t\t\t      |\n");
      printf(" %c----------------------------------------------------------------------------%c\n",200,188);
      printf("\t       %c----------%c\t\t\t\t       ",201,187);
      printf("\t\t\t               |   MENU   ");printf("|\t\t\t\t      \n");
      printf("   %c-----------%c----------%c------------%c \n",201,200,188,187);
      printf("   | <A>  Novo cadastro                |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <B>  Listar                       |\n");      
      printf("   |-----------------------------------|\n");
      printf("   | <C>  Excluir cadastro             |\n");      
      printf("   |-----------------------------------|\n");
      printf("   | <D>  Alterar cadastro             |\n"); 
      printf("   |-----------------------------------|\n");
      printf("   | <S>  Sair                         |\n");
      printf("   %c-----------------------------------%c",200,188);
      printf("\n\n\n\n");
      printf("\t\t\t      By Adelman Benigno");
      
      //Lendo a opcao do menu   
      fflush(stdin);
      opcao= getch(); 
      
      //Menu de opcoes
      switch(opcao)
      {
         case 'A':   
         case 'a':   
              //Inserindo os restaurantes.
              fflush(stdin);
              system("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t          NOVO CADASTRO     ");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              primeiro= inserir_restaurantes(primeiro);
         getch();
         system("cls"); 
         break;
         
         case 'B':   
         case 'b':       
              //Listando os restaurantes.
              system ("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t     RESTAURANTES CADASTRADOS");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              listar_restaurantes(primeiro);
         getch();
         system("cls");
         break;
         
         case 'C':   
         case 'c':   
              //Excluindo restaurantes da lista.
              system ("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t        EXCLUIR CADASTROS");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              primeiro= excluir_restaurantes(primeiro);
         getch();
         system("cls");
         break;

         case 'D':   
         case 'd':   
              //Alterando restaurantes da lista. 
              system ("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t       ALTERAR CADASTRADOS");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              alterar_restaurantes(primeiro);
         getch();
         system("cls");
         break;
         
         case 'S':   
         case 's':       
              //Artif�cio para sair do programa.
              opcao='s';
         break;
         
         default:     
              //Artif�cio que previne a situa��o de um usu�rio qualquer, digitar uma opc�o inexistente no menu.
              system("cls");        
         break; 
      } 
   }  
}

Lista* inserir_restaurantes (Lista *primeiro){ 
     Lista restaurante;
     Lista *atual= primeiro;
     char identificador= 'F';
     
     //Lendo as informa��es do restaurante.
     printf("  Nome: ");
     fflush (stdin); fgets(restaurante.nome, 40, stdin); printf ("\n");
     printf("  Endere%co: ",135);
     fflush (stdin); fgets(restaurante.endereco, 40, stdin); printf ("\n");
     printf("  C%cdigo: ",162);
     scanf("%u",&restaurante.codigo);printf ("\n");
     
     //Verificando se o cadastro j� existe.
     for(atual=primeiro; atual!=NULL; atual=atual->prox){
        if(atual->codigo==restaurante.codigo){
            identificador= 'V'; 
            break;
        }    
     }

     if(identificador!='V' && (strlen(restaurante.nome)!=1 && strlen(restaurante.endereco)!=1)){
         //Alocando os espa�os e guardando as informa��es do restaurante.
         Lista* NovoRestaurante=(Lista*) malloc (sizeof(Lista));       
         strcpy(NovoRestaurante->nome, restaurante.nome);
         strcpy(NovoRestaurante->endereco, restaurante.endereco);
         NovoRestaurante->codigo= restaurante.codigo;
         NovoRestaurante->prox= primeiro;
         printf("  Cadastro realizado com sucesso.");
         printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
         return NovoRestaurante;    
     }else{
         printf("  Cadastro inv%clido.",160);
         printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
         return primeiro;
     }
}

void listar_restaurantes (Lista* primeiro){
     Lista* atual;//Ponteiro para percorrer a lista sem perder a refer�ncia do primeiro elemento da lista.
     
     //Imprimindo os restaurantes da lista, e suas repectivas informa��es.
     for(atual= primeiro ; atual!= NULL; atual= atual->prox){
        printf("\n  Nome: ");
        printf("%s", atual->nome);
        printf("\n  Endere%co: ",135);
        printf("%s", atual->endereco);
        printf("\n  C%cdigo: ",162 );
        printf("%u", atual->codigo);
        printf("\n\n");
     }
     if(primeiro==NULL)
        printf("  Nenhum restaurante cadastrado.");
     printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}

Lista* excluir_restaurantes(Lista *primeiro){
     
     Lista *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
     Lista *atual= primeiro;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
     unsigned long int codigo=0;
     
     //Requisitando e lendo o c�digo do restaurante a ser exclu�do.
     printf("  C%cdigo do restaurante a ser exclu%cdo: ", 162,161);
     fflush(stdin);
     scanf("%u",&codigo);
     
     //Procurando o restaurante na lista.
     while(atual!= NULL && atual->codigo!=codigo){
        anterior= atual;
        atual= atual->prox;
     }
     
     //Mensagem caso o restaurante n�o seja encontrado.
     if(atual==NULL){
        printf("\n  Restaurante n%co encontrado.", 198); 
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return primeiro;
     }
     
     //Excluindo o primeiro restaurante da lista.   
     if(anterior==NULL){
        printf("\n  Conte%cdo exclu%cdo com sucesso.", 163,161); 
        primeiro= atual->prox;
     //Excluindo um restaurante do meio da lista.
     }else{
        printf("\n  Conte%cdo exclu%cdo com sucesso.", 163,161);
        anterior->prox= atual->prox;
     }
     
     //Desalocando o espa�o da mem�ria.
     free(atual);
     printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
     return primeiro;     
}

//Fun��o para alterar restaurantes.
void alterar_restaurantes(Lista* primeiro){     
     char nome_substituto[40], endereco_substituto[40];
     unsigned long int codigo;  
     Lista* atual=primeiro;
     
     //Requisitando e lendo o c�digo do restaurante a ser alterado.
     printf("  C%cdigo do restaurante a ser alterado: ", 162);
     fflush(stdin);
     scanf("%u",&codigo);
     
     //Procurando o restaurante na lista.
     while(atual!= NULL && atual->codigo!=codigo){
        atual= atual->prox;
     }
     
     //Alterando os dados do restaurante.
     if(atual!=NULL){
        printf("\n  Novo nome: ");
        fflush (stdin); fgets(nome_substituto, 40, stdin); 
        strcpy(atual->nome,nome_substituto);
        printf("\n  Novo endere%co: ",135);
        fflush (stdin); fgets(endereco_substituto, 40, stdin); printf ("\n");
        strcpy(atual->endereco,endereco_substituto);
        printf("  Dados alterados com sucesso.");
     }else{
        printf("\n  Restaurante n%co encontrado.",198);
     }
     printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}
