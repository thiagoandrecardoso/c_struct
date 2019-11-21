#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AMOUNT_TEST 3
#define AMOUNT_STUDENT 5
#define MEAN_VALUE 6
/**
** Thiago André Cardoso Silva 
** Aulas particulares de programação (para iniciantes)
** Instagram: @programador_who
** Cel: (085) 999273805
*/
struct Student{
  unsigned long int registration;
  char name[100];
  double tests[AMOUNT_TEST];
  double mean;
};

void highest_score_of_the_first_test(struct Student studentList[AMOUNT_STUDENT]);
void highest_score_of_the_first_mean(struct Student studentList[AMOUNT_STUDENT]);
void lowest_score_of_the_first_mean(struct Student studentList[AMOUNT_STUDENT]);
void approved(struct Student studentList[AMOUNT_STUDENT]);
void print_student(struct Student student);

int main(int argc, char const *argv[]) {
  struct Student studentList[AMOUNT_STUDENT];
  struct Student student;

  for (size_t i = 0; i < AMOUNT_STUDENT; i++) {
    double summation = 0;
    printf("Enter name: ");
    fgets(student.name, 100, stdin);
    printf("Enter registration: ");
    scanf("%ld", &student.registration);
    setbuf(stdin, NULL);
    for (int i = 0; i < AMOUNT_TEST; i++) {
      printf("Enter %d test value\n", i + 1);
      scanf("%lf", &student.tests[i]);
      summation += student.tests[i];
    }
    setbuf(stdin, NULL);
    student.mean = summation / AMOUNT_TEST;
    studentList[i] = student;
  }
  highest_score_of_the_first_test(studentList);
  highest_score_of_the_first_mean(studentList);
  lowest_score_of_the_first_mean(studentList);
  approved(studentList);
  return 0;
}

void highest_score_of_the_first_test(struct Student studentList[AMOUNT_STUDENT]){
  double high_value = 0.0;
  struct Student student_help;
  for (int i = 0; i < AMOUNT_STUDENT; i++) {
    if (studentList[i].tests[0] > high_value) {
      high_value = studentList[i].tests[0];
      student_help = studentList[i];
    }
  }
  printf("highest score of the first test\n");
  print_student(student_help);
}

void highest_score_of_the_first_mean(struct Student studentList[AMOUNT_STUDENT]){
  double mean_help = 0.0;
  struct Student student_help;
  for (int i = 0; i < AMOUNT_STUDENT; i++) {
    if (studentList[i].mean > mean_help) {
      mean_help = studentList[i].mean;
      student_help = studentList[i];
    }
  }
  printf("highest score of the first mean\n");
  print_student(student_help);
}

void lowest_score_of_the_first_mean(struct Student studentList[AMOUNT_STUDENT]){
  double mean_help = 10.0;
  struct Student student_help;
  for (int i = 0; i < AMOUNT_STUDENT; i++) {
    if (studentList[i].mean < mean_help) {
      mean_help = studentList[i].mean;
      student_help = studentList[i];
    }
  }
  printf("lowest score of the first mean\n");
  print_student(student_help);
}

void approved(struct Student studentList[AMOUNT_STUDENT]){
  for (int i = 0; i < AMOUNT_STUDENT; i++) {
    if (studentList[i].mean > MEAN_VALUE) {
      printf("approved\n");
      print_student(studentList[i]);
    }else{
      printf("disapproved\n");
      print_student(studentList[i]);
    }
  }
}

void print_student(struct Student student){
  printf("Name %s", student.name);
  printf("Registration %lu\n", student.registration);
  for (int i = 0; i < AMOUNT_TEST; i++) {
    printf("%d test value %lf\n", i + 1, student.tests[i]);
  }
  printf("Mean value %lf\n", student.mean);
}
