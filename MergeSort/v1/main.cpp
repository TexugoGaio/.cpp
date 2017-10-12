#include <iostream>
using namespace std;

int main(){
  int vet1[5] = {2, 4, 6, 8, 10};
  int vet2[5] = {1, 3, 5, 7, 9};
  int vet3[10];

  int i = 0, j = 0, k = 0;
  while(i < 5 && j < 5){
    if(vet1[i] < vet2[j]){
      vet3[k] = vet1[i];
      i++;
    }else{
      vet3[k] = vet2[j];
      j++;
    }
    k++;
  }

  while(i < 5){
    vet3[k] = vet1[i];
    i++;
    k++;
  }

  while(j < 5){
    vet3[k] = vet2[j];
    j++;
    k++;
  }

  cout << "[ ";
  for(int i = 0; i < 10; i++){
    if(i < 10 - 1){
      cout << vet3[i] << ", ";
    }else{
      cout << vet3[i];
    }
  }
  cout << " ]" << endl;
  return 0;
}
