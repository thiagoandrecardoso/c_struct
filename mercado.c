#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int qntd_prod = 1;

typedef struct{
  int codigo;
  char nome[15];
  double preco;
  int quantidade;
}Produto;

void cadastrarProdutos(Produto produto[qntd_prod]);
void lerPedido(Produto produto[qntd_prod]);

int main(int argc, char const *argv[]) {
  Produto produto[qntd_prod];
  cadastrarProdutos(produto);
  printf("______________\n");
  lerPedido(produto);
  return 0;
}

void cadastrarProdutos(Produto produto[qntd_prod]){
  printf("Cadastro:\n");
  for (int i = 0; i < qntd_prod; i++) {
    printf("Digite o codigo: ");
    scanf("%d", &produto[i].codigo);
    setbuf(stdin, NULL);
    printf("Digite o nome: ");
    fgets(produto[i].nome, 15, stdin);
    printf("Digite o preço: ");
    scanf("%lf", &produto[i].preco);
    printf("Digite a quantidade: ");
    scanf("%d", &produto[i].quantidade);
  }
}

void lerPedido(Produto produto[qntd_prod]){

  int codigo = -1;
  int quantidade = 0;

  while (codigo != 0) {
    printf("Digite o codigo do produto ou zero para encerrar\n");
    scanf("%d", &codigo);
    setbuf(stdin, NULL);
    printf("Digite a quantidade\n");
    scanf("%d", &quantidade);

    for (int i = 0; i < qntd_prod; i++) {
      if(codigo == produto[i].codigo){
        if (quantidade <= produto[i].quantidade) {
          produto[i].quantidade -= quantidade;
          printf("Codigo %d\n", produto[i].codigo);
          printf("Nome %s", produto[i].nome);
          printf("Preço %lf\n", produto[i].preco);
          printf("Quantidade %d\n", produto[i].quantidade);
        }
      }
    }
  }

}
