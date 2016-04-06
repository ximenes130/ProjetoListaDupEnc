/*

cadastro------------------------------
consulta por código-----------------------
consulta por nome do produto*-*-*-*-*-*-*-*-*
listagem (de todos os produtos cadastrados)*
listagem (de todos os produtos com quantidade abaixo de um valor fornecido)*
alteração*
exclusão-------------------------------------
venda (imprimir o total da venda. Fazer o controle da quantidade)*

Funções auxiliares que forem necessárias.   */


typedef struct produto Produto;
Produto* inicializa(void);
Produto* cadastra(Produto* pdt,int codigo,char nome,float valor,int qtd);
Produto* busca(Produto* pdt,int valor);
Produto* imprime(Produto* pdt);
Produto* retira(Produto* pdt,int valor);
