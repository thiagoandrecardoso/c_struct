#include <stdio.h>
#include <string.h>
/**
** Thiago André Cardoso Silva
** Aulas particulares de programação (para iniciantes)
** Instagram: @programador_who
** Cel: (085) 999273805
*/
/**
* Com o uso typedef, podemos usar apenas o nome
* 'Pessoa' como um tipo, sem a necessidade do uso
* 'struct Pessoa'
* Estamos definindo um tipo!
*/
typedef struct{
  int dia;
  int mes;
  int ano;
}DataNascimento;

typedef struct{
  float peso;
  DataNascimento dataNasc; // uma struct pode conter outras
  float altura;
} Pessoa;

int main(int argc, char const *argv[]) {

  Pessoa pessoa; // delcarando variável do tipo Pessoa
  Pessoa pessoas[5]; // delcarando vetor do tipo Pessoa

  pessoa.peso = (float) 80.67;
  pessoa.altura = (float) 1.87;
  /**
  * Declaramos e preenchemos uma variável
  * do tipo DataNascimento
  */
  DataNascimento data;
  data.dia = 05;
  data.mes = 12;
  data.ano = 1987;
  /*
  * atribuindo a data criada a dataNasc da variável pessoa
  */
  pessoa.dataNasc = data;
  /*
  * adicionando a variável pessoa ao vetor de Pessoa
  */
  pessoas[0] = pessoa;

  return 0;
}
