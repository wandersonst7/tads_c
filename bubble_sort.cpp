#include <iostream>

using namespace std;
int main() {
  int vet[5] = {10, 7, 2, 9, 6};
  int i, contador, aux;
  
  for(contador = 1; contador < 5; contador++){
    for(i = 0; i < 4; i++){
      if(vet[i] > vet[i + 1]){
        aux = vet[i];
        vet[i] = vet[i + 1];
        vet[i + 1] = aux; 
      }
    }
  }

  for(i = 0; i < 5; i++){
    cout << vet[i] << "\n";
  }


  return 0;
}