#include <stdio.h>
#include <string.h>
/**
** Thiago André Cardoso Silva
** Aulas particulares de programação (para iniciantes)
** Instagram: @programador_who
** Cel: (085) 999273805
*/

/**
* Uma struct é uma variável especial que contém
* diversas outras variáveis normalmente de tipos diferentes.
* As variáveis internas contidas pela struct
* são denominadas membros da struct.
* Podemos dizer que as structs da linguagem C
* são o equivalente ao que se denomina registros em o
* utras linguagens de programação.
* Por: Eduardo Casavella
*/
struct Data{
  int dia;
  int mes;
  int ano;
  char descricao[200];
};

int main(int argc, char const *argv[]) {
  /**
  * Delcarando variável da struct Data
  * struct Data É O TIPO
  * data É A VARIÁVEL
  */
  struct Data data;
  /**
  * Acessando os atributos da struct:
  * Usamos o .(ponto) para fazer o acesso.
  * Abaixo estamos atribuindo o valor 12
  * ao atributo dia da variável data.
  */
  data.dia = 05;
  data.mes = 12;
  data.ano = 1987;
  /*
  * Podemos usar a função strcpy para atribuição de char[]
  * função esta que faz parte da biblioteca <string.h>
  */
  strcpy(data.descricao, "Meu aniversáio!");
  printf("%d/%d/%d\n", data.dia, data.mes, data.ano);
  printf("%s\n", data.descricao);

  /*
  * Para fazer atribuição as variáveis atravez do console
  */
  scanf("%d", &data.dia); // para valores numericos
  setbuf(stdin, NULL); // limpa o buffer do teclado
  /**
  * É necessário limpar o buffer, pois variáveis numericas
  * não pegam o ENTER do teclado, e este valor iria para
  * uma próxima leitura, se esta fosse literal.
  */

  /**
  * Leitura para variáveis tipo char[]
  * fgets aceita espaços entre nomes ou letras.
  */
  fgets(data.descricao, 200, stdin);
  return 0;
}
