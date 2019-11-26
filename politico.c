#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int menu();

int main(int argc, char const *argv[]) {
  int opcao = menu();
  return 0;
}

int menu(){
  int opcao;
  printf("Escolha uma das opcoes :\n");
  printf("\t\t1- Cadastrar politico\n");
  printf("\t\t2- Editar dados de politico\n");
  printf("\t\t3- Excluir politico do sistema\n");
  printf("\t\t4- Cadastrar proposta de emenda constitucional (PEC)\n");
  printf("\t\t5- Registrar voto de politico em emenda\n");
  printf("\t\t6- Excluir proposta de emenda constitucional (PEC)\n");
  printf("\t\t7- Exibir Meu Ranking por politico\n");
  scanf("%d", &opcao);
  return opcao;
}
