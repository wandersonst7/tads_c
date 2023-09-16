#include <iostream>

using namespace std;

typedef struct lista{
  int info;
  struct lista * prox;
}Lista;

typedef struct fila{
  int qtd;
  struct lista * inicio;
}Fila;

Fila * fila_cria(){
  Fila * f = (Fila *) malloc(sizeof(Fila));
  f->qtd = 0;
  f->inicio = NULL;
  return f;
}

void fila_insere(Fila * f, int info){
  Lista * lista = (Lista *) malloc(sizeof(Lista));
  if(lista){
    lista->info = info;
    lista->prox = NULL;
    if(f->inicio == NULL){
      f->inicio = lista;
    }else{
      Lista * aux = f->inicio;
      while(aux->prox != NULL){
        aux = aux->prox;
      }
      aux->prox = lista;
    }
    f->qtd++;
  }else{
    cout << "ERRO\n";
  }
}


int fila_vazia(Fila * f){
  if(f->inicio == NULL){
    return 1;
  }

  return 0;
}

void fila_remove(Fila * f){
  if(fila_vazia(f)){
    cout << "Fila vazia" << "\n";
    exit(1);
  }
  Lista * l = f->inicio->prox;
  free(f->inicio);
  f->inicio = l;
  f->qtd--;
  if(f->qtd > 0){
    cout << "Você removeu um elemento! ";
    cout << "Restam " << f->qtd << " elemento(s)!\n";
  }else{
    cout << "Você removeu todos os elementos!\n";
  }  
}


int main() {
  Fila * fila;
  fila = fila_cria();
  fila_insere(fila, 1);
  fila_insere(fila, 2);
  fila_insere(fila, 3);
  fila_insere(fila, 4);
  
  Lista * aux = fila->inicio;
  while(aux != NULL){
    cout << "Lista " << aux->info <<"\n";
    aux = aux->prox;
  }

  cout << "\n";   
  
  fila_remove(fila);
  fila_remove(fila);
  
  cout << "\n";
  
  aux = fila->inicio;
  while(aux != NULL){
    cout << "Lista " << aux->info <<"\n";
    aux = aux->prox;
  }
}