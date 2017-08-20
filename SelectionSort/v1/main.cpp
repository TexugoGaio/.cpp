#include <iostream>
using namespace std;

int main(){
  int vetor[5] = {5, 4, 3, 2, 1};
  int fim = 4;
  for(int i = 0; i < fim; i++){
    int menor = i;
    for(int j = i + 1; j <= fim; j++){
      if(vetor[menor] > vetor[j]){
        menor = j;
      }
    }
    int aux = vetor[i];
    vetor[i] = vetor[menor];
    vetor[menor] = aux;
  }

  for(int i = 0; i <= fim; i++){
    cout << vetor[i] << "\t";
  }
  return 0;
}
