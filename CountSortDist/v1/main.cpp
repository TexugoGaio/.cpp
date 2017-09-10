#include <iostream>
using namespace std;

void imprima(int *vet,const int MAX){
  for(int i = 0; i < MAX; i++){
    cout << vet[i] << "\t";
  }
}

int main(){
  const int T = 12;
  int vet[T] = {26, 19, 34, 19, 23, 16, 31, 26, 31, 22, 21, 29};
    //imprima(vet, T);
  int saida[T];
  int maior = vet[0];
  int menor = maior;

  for(int i = 1; i < T; i++){
    if(vet[i] < menor){
      menor = vet[i];
    }else if(vet[i] > maior){
      maior = vet[i];
    }
  }

  int cont[maior + 1];
  for(int i = menor; i <= maior; i++){
    cont[i] = 0;
  }

  for(int i = 0; i < T; i++){
    cont[vet[i]]++;
  }

  for(int i = menor + 1; i <= maior; i++){
    cont[i] += cont[i - 1];
  }

  for(int j = 0; j < T; j++){
    int i = cont[vet[j]];
    saida[i - 1] = vet[j];
    cont[vet[j]]--;
  }

  imprima(saida, T);
  return 0;
}
