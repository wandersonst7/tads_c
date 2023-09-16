#include <iostream>

using namespace std;

void inserirMatriz(int (*mat)[3]){
  int i, j, n = 1;
  for(i = 0; i < 2; i++){
    for(j= 0; j < 3; j++){
      mat[i][j] = n;
      n++;
    }
  }
}
  
int main(){
  int mat[2][3];
  int i, j;
  inserirMatriz(mat);
  for(i = 0; i < 2; i++){
    for(j= 0; j < 3; j++){
      cout << "[" << mat[i][j] << "]";
      if(j == 2){
        cout << "\n";
      }
    }
  }
  return 0;
}