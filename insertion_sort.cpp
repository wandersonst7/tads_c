#include <iostream>

using namespace std;

int main() {
  int vetor[10] = {44, 55, 1, 2, 6, 9, 43, 22, 100, 25};
  int k, j, aux;

  for (k = 1; k <= 10 - 1; k++){
    printf("\n[%d] ", k);

    aux = vetor[k];
    j = k - 1;
    while (j >= 0 && aux < vetor[j]) {
      printf("%d, ", j);
      vetor[j+1] = vetor[j];
      j--;
    }

    vetor[j+1] = aux;
  }

  return 0;
}