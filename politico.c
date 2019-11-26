#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// variáveis globais
int qntd_politicos = 100;
int qntd_politicos_cadastrados = 0;

typedef struct{
  char nome[100];
  char partido[100];
}Politico;

int cadastrarPolitico(Politico listaPoliticos[qntd_politicos]);
int menu();
int verificaNome(char nome[100]);

// --------------------- MAIN -------------------------------------------------
int main(int argc, char const *argv[]) {
  Politico listaPoliticos[qntd_politicos];
  Politico politico;
  int opcao = -1;
  /**
  * while abaixo é o loop principal do programa.
  */
  while (opcao != 0) {
    opcao = menu();
    switch (opcao) {
      case 1:
      cadastrarPolitico(listaPoliticos);
      break;
    }
  }

  return 0;
}
// --------------------- MAIN -------------------------------------------------

int cadastrarPolitico(Politico listaPoliticos[qntd_politicos]){
  Politico politico;
  char nome_aux[100];
  int nomevalido = 0;

  do {
    printf("Qual o nome do politico que gostaria de cadastrar? Digite 0 para voltar ao menu inicial.\n");
    fgets(nome_aux, 100, stdin);
    if (nome_aux[0] == 48 && nome_aux[1] == 10) { // se digitar 0 volta
      return 0;
    }
    nomevalido = verificaNome(nome_aux);
    if(!nomevalido) printf("Nome inválido\n");
  } while(nomevalido != 1);

  if(qntd_politicos_cadastrados == 0){ // cadastrar primeiro politico
    strcpy(listaPoliticos[qntd_politicos_cadastrados].nome, nome_aux);
    printf("Qual o partido dele? ");
    fgets(listaPoliticos[qntd_politicos_cadastrados].partido, 100, stdin);
  }

  return 0;
}

// esta validação compara os caracteres com tabela ASCII
int verificaNome(char nome[100]){
  int i = 0;
  int n = 0;
  int tem_espaco_seguido = 0;

  if (nome[0] == 32) { // verifica se começa com espaço.
    return 0;
  }

  while (nome[i] != '\0') { // varre o nome até encontrar o enter
    if(((nome[i] >= 97 && nome[i] <= 122) || (nome[i] >= 65 && nome[i] <= 90)) != 1){
      if (nome[i] == 32)  tem_espaco_seguido ++;
      if (nome[i] != 32)  tem_espaco_seguido = 0;
      if(tem_espaco_seguido == 2) return 0; // verifica se tem dois espaços seguidos
      n++;
    }
    i++;
  }

  n -= 2; // desconta o enter que contém na palavra.
  if(n <= 0){return 1;}
  else{return 0;}
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
  printf("\t\t0- Sair\n");
  scanf("%d", &opcao);
  setbuf(stdin, NULL); // limpa buffer do teclado
  return opcao;
}
