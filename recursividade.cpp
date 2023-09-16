#include <iostream>
#include <cstdlib>

using namespace std;

int fatorial(int n){
  if(n == 0){
    return 1;
  }else{
    return n * fatorial(n-1);
  }
}

int main() {
  int n, r;
  cout << "Digite um numero: ";
  cin >> n;
  r = fatorial(n);
  cout << "Fatorial: " << r;
  return 0;
}