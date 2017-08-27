#include <iostream>
using namespace std;
void imprima(int*,int);
int main(){
  int vet[5] = {5, 4, 3, 2, 1};
  int count[5] = {0, 0, 0, 0, 0};
  int saida[5];
  int fim = 4;
  for(int i = 0; i < fim; i++){
    for(int j = i + 1; j <= fim; j++){
      if(vet[i] > vet[j]){
        count[i]++;
      }else{
        count[j]++;
      }
    }
  }

  for(int i = 0; i <= fim; i++){
    saida[count[i]] = vet[i];
  }

  imprima(saida, fim);
  return 0;
}

void imprima(int *vet, int f){
  for(int i = 0; i <= f; i++){
    cout << vet[i] << "\t";
  }
}
