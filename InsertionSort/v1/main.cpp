#include <iostream>
using namespace std;

int main(){

  int vetor[6];
  int fim = 0, aux, i;
  cout << "Informe o valor ~:> ";
  cin >> vetor[fim];
  fim++;
  while(fim < 6){
    cout << "Informe o valor ~:> ";
    cin >> aux;
    i = fim;
    while(i > 0 && aux < vetor[i - 1]){
      vetor[i] = vetor[i - 1];
      i--;
    }
    vetor[i] = aux;
    fim++;
  }

  for(int i = 0; i < 6; i++){
    cout << vetor[i] << "\t";
  }
  return 0;
}
