#include <iostream>
using namespace std;

int main(){	
	int vetor[5] = {5, 4, 3, 2, 1};
	int MAX = 4;
	int troca = 1;
	while(troca != 0){
		troca = 0;
		for(int i = 0; i <= MAX - 1; i++){		
			if(vetor[i] > vetor[i + 1]){
				int aux = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = aux;
				troca = 1;
			}
		}
		MAX--;
	}
	
	for(int  i = 0; i <= 4; i++){
		cout << vetor[i] << "\t";
	}
	return 0;
}
