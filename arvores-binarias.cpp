#include <iostream>
#include <string>

using namespace std;

typedef struct arv{
  string info;
  struct arv * esq;
  struct arv * dir;
}Arvore;

int main() {
  Arvore raiz;
  raiz.info = "raiz";
  raiz.dir = NULL;
  raiz.esq = NULL;

  Arvore esquerda;
  Arvore direita;

  esquerda.info = "filho-esquerdo";
  esquerda.dir = NULL;
  esquerda.esq = NULL;
  
  direita.info = "filho-direito";
  direita.dir = NULL;
  direita.esq = NULL;

  raiz.esq = &esquerda;
  raiz.dir = &direita;

  cout << "--- " << raiz.info << " ---" << "\n\n";
  cout << raiz.esq->info << " ----- " << raiz.dir->info << "\n";
  
}