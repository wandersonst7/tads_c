#include <iostream>

using namespace std;

int main() {
  int numeros[10] = {5, 10, 20, 55, 1, 32, 0, 34, 11, 77};
  int i, j, aux;

  for(i = 0; i < 9; i++){
    for(j = 1 + i; j < 10; j++){
      if(numeros[i] > numeros[j]){
        aux = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = aux;
      }
    }
  }

  for(i = 0; i < 10; i++){
    cout << numeros[i] << "\n";
  }

  return 0;
}