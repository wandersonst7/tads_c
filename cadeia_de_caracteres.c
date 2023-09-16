#include <stdio.h>

void imprimeString(char * nome){
  int i;
  for(i = 0; nome[i] != '\0'; i++){
    printf("[%c]", nome[i]);
  }
}

int comprimento(char * nome){
  int i, n = 0;
  for(i = 0; nome[i] != '\0'; i++){
    n++;
  }
  return n;
}

int main(void) {
  int tam;
  char nome[61];
  scanf(" %[^\n]", nome);
  imprimeString(nome);
  tam = comprimento(nome);
  printf("\nA String \"%s\" tem %d caracteres", nome, tam);

  return 0;
}