#include <iostream>

struct ponto{
    float x;
    float y;
};

void preencheStruct(ponto * p){
  (*p).x = 15; 
  p->y = 20;
}

int main() {

  struct ponto p1;
  p1.x = 5;
  p1.y = 3;

  struct ponto p2;
  p2.x = 3.1;
  p2.y = 5.1;

  preencheStruct(&p2);

  std::cout << "|Ponto 1|\n";
  std::cout << "x= " << p1.x << " y= " << p1.y;

  std::cout << "\n|Ponto 2|\n";
  std::cout << "x= " << p2.x << " y= " << p2.y;

  struct circulo{
    ponto p;
    float raio;
  };

  circulo c1;
  c1.p = p1;
  c1.raio = 3.14;

  ponto p3[3] = {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}};

  return 0;
}