/*

cadastro------------------------------
consulta por c�digo-----------------------
consulta por nome do produto*-*-*-*-*-*-*-*-*
listagem (de todos os produtos cadastrados)*
listagem (de todos os produtos com quantidade abaixo de um valor fornecido)*
altera��o*
exclus�o-------------------------------------
venda (imprimir o total da venda. Fazer o controle da quantidade)*

Fun��es auxiliares que forem necess�rias.   */


typedef struct produto Produto;
Produto* inicializa(void);
Produto* cadastra(Produto* pdt,int codigo,char nome,float valor,int qtd);
Produto* busca(Produto* pdt,int valor);
Produto* imprime(Produto* pdt);
Produto* retira(Produto* pdt,int valor);
