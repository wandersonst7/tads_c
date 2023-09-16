#include <stdio.h>

int main(void) {

  int inteiro = 1;
  float real = 2.5;
  char caractere = 'c';

  int * i;
  float * r;
  char * c;

  i = &inteiro;
  r = &real;
  c = &caractere;

  *i = 2;
  *r = 3.5;
  *c = 'M';

  printf("Numero inteiro: %d\n", *i);
  printf("Numero real: %f\n", *r);
  printf("Caractere: %c\n", *c);
 
  return 0;
}