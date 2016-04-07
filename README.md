# TRABALHO PRÁTICO: Lista Duplamente Encadeada

##### Implementar um programa  para efetuar o controle e venda de produtos.

##### **Obs: cada aluno deverá postar individualmente**

___

## Especificações
### Estrutura

```
____________________
Produto
____________________
codigo
nome
valor
qtd
____________________
```

### Funcionalidades básicas:

**Luana**
- [ ] cadastro
- [ ] consulta por código
- [ ] consulta por nome do produto

```
Produto* cadastro(Produto* raiz, Produto* novo);
Produto* consultaCodigo(Produto* raiz,int codigo);
Produto* consultaNome(Produto* raiz,char* nome);
```

**Abel**
- [ ] listagem (de todos os produtos cadastrados)
- [ ] listagem (de todos os produtos com quantidade abaixo de um valor fornecido) 
- [ ] printProduto

```
void listarProduto(Produto* raiz);
void listarProdutoCEstoque(Produto* raiz, int qtd);
void printProduto(Produto* produto)
```

**Luiz**
- [ ] Alteração
- [ ] venda (imprimir o total da venda. Fazer o controle da quantidade)
- [ ] exclusão

```
Produto* exclui(Produto* produto);
Produto* alterar(Produto* produto, Produto* novoProduto);
Produto* vender(Produto* produto, float novoValor);
```

### Criar e utilizar:

-BibListaDup.c
-BibListaDup.h
