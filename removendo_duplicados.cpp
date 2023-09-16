#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct lista{
  int info;
  lista * prox;
}Lista;

Lista * inicializa(){
  return NULL;
}

Lista * insere(Lista * l, int i){
  Lista * novo = (Lista *) malloc(sizeof(Lista));
  novo->info = i;
  novo->prox = l;
  return novo;
}

Lista * remover_dup(Lista * l){
  Lista * proxE = NULL;
  Lista * aux = l;

  //selection sort
  for(aux = l; aux != NULL; aux = aux->prox){
      for(proxE = aux->prox; proxE != NULL; proxE = proxE->prox){
        if(proxE->info == aux->info){
          aux->prox = proxE->prox;
        }
      }
  }

  return l;
}

int main() {

  // Inserindo elementos na lista
  Lista * l = inicializa();
  l = insere(l, 1);
  l = insere(l, 2);
  l = insere(l, 2);
  l = insere(l, 3);
  l = insere(l, 3);
  
  cout << "Lista Inicial:" << endl;
  Lista * aux = l;
  while(aux != NULL){
    cout << aux->info << endl;
    aux = aux->prox;
  }

  //Removendo elementos duplicados
  cout << "\n\nDepois da Remoção:" << endl;
  l = remover_dup(l);

  
  aux = l;
  while(aux != NULL){
    cout << aux->info << endl;
    aux = aux->prox;
  }

  





  return 0;
}