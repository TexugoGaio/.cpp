#include <iostream>
using namespace std;

#define MAX 16

void showArray(int*);
void insertion(int*);

int main(){

  int vet[MAX] = {32, 18, 45, 29, 16, 41, 30, 27 , 14, 37, 29, 38, 20, 32, 17, 26};

  int increments[4] = {8, 4, 2, 1};
  int x = 0;

  while(increments[x] > 1){
    int i = 0;
    int j = increments[x];
    while(j < MAX){
      if(vet[i] > vet[j]){
        int aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
      }
      i++;
      j++;
    }
    x++;
  }
    insertion(vet);
    showArray(vet);
  return 0;
}

void showArray(int *v){
  cout << "[ ";
  for(int i = 0; i < MAX; i++){
    if(i < MAX - 1){
      cout << v[i] << ", ";
    }else{
      cout << v[i];
    }
  }
  cout << " ]" << endl;
}

void insertion(int *v){
  for(int i = 1; i < MAX; i++){
    int j = i;
    while(v[j] < v[j - 1] && j > 0){
      int aux = v[j - 1];
      v[j - 1] = v[j];
      v[j] = aux;
      j--;
    }
  }
}
