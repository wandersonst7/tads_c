#include <iostream>

using namespace std;

//Estruturas
typedef struct lista{
  float info;
  struct lista * prox;
}Lista;

typedef struct pilha{
  Lista * prim;
}Pilha;

//Funções

//cria pilha
Pilha * pilha_cria(void){
  Pilha * p = (Pilha *) malloc(sizeof(Pilha));
  p->prim = NULL;
  return p;
}

//verifica se a pilha está vazia
int pilha_vazia(Pilha * p){
  return(p->prim == NULL);
}

//insere elemento na lista
void pilha_push(Pilha * p, float v){
  lista * n = (lista *) malloc(sizeof(lista));
  n->info = v;
  n->prox = p->prim;
  p->prim = n;
}

//remove elemento da lista
float pilha_pop(Pilha * p){
  Lista * t;
  float v;
  if(pilha_vazia(p)){
    cout << "Pilha vazia.\n";
    exit(1); //*Aborta o programa
  }
  t = p->prim;
  v = t->info;
  p->prim = t->prox;
  free(t);
  return v;
}

//libera todos elementos da lista e depois a pilha
void pilha_libera(Pilha * p){
  Lista * q = p->prim;
  while(q != NULL){
    Lista * t = q->prox;
    free(q);
    q = t;
  }
  free(p);
}

void imprime(Pilha * p){
  Lista * aux = p->prim;
  while(aux != NULL){
    cout << aux->info << "\n";
    aux = aux->prox;
  }
}

int main() {

  float valor;
  Pilha * p;
  p = pilha_cria();
  pilha_push(p, 1);
  pilha_push(p, 2);
  pilha_push(p, 3);
  imprime(p);
  valor = pilha_pop(p);
  cout << "===========" << "\n";
  imprime(p);
  pilha_libera(p);
  cout << "===========" << "\n";
  
  return 0;
}  