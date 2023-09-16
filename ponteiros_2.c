#include <stdio.h>

int main(void) {

  int num1 = 5;
  int num2 = 3;
  
  int * n1;
  int * n2;

  n1 = &num1;
  n2 = &num2;

  if(n1 > n2){
    printf("O endereco de n1 é maior que o endereco de n2");
  }else{
    printf("O endereco de n2 é maior que o endereco de n1");
  }
 
  return 0;
}