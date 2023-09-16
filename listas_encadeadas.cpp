#include <iostream>

using namespace std;

struct lista{
  int info;
  struct lista* prox;
};

typedef struct lista Lista;
typedef struct lista No;

Lista * lst_cria(){
  return NULL;
}

Lista * lst_insere_inicio(Lista * lista, int info){
  Lista * nova = (Lista *) malloc(sizeof(Lista));
  (*nova).info = info;
  (*nova).prox = lista;
  return nova;
}

Lista * lst_insere_final(Lista * lista, int info){
  Lista *aux, *nova = (Lista *) malloc(sizeof(Lista));
  (*nova).info = info;
  (*nova).prox = NULL;
  
    if(lista == NULL){
      lista = nova;
    }else{
      aux = lista;
      while(aux->prox != NULL)
        aux = aux->prox;
      aux->prox = nova;
    }
  return nova;
}

void lst_busca(Lista * lista, int valor){
  Lista * aux;
  for(aux = lista; aux != NULL; aux = aux->prox){
    if(aux->info == valor){
      cout << "valor encontrado" << "\n";
      aux = NULL;
      break;
    }
  }
}

int main() {
  Lista * l;
  l = lst_cria();
  l = lst_insere_inicio(l, 22);
  l = lst_insere_inicio(l, 34);
  lst_busca(l, 22);
  cout << l->info << "\n";
  cout << l->prox->info << "\n";

  return 0;
}