#include <iostream>
#include <string>
using namespace std;

struct Usuario {
	int id;
	string nome;
	string email;
	int idade;
	bool status;
};

void Inserir(Usuario* list,Usuario* lote, Usuario* newList, int fimList, int fimLote){
	int i = 0, j = 0, k = 0;
	while(i <= fimList && j <= fimLote){
		if(list[i].id < lote[j].id){
			newList[k] = list[i];
			i++;
		}else{
			newList[k] = lote[j];
			j++;
		}
		k++;
	}
	
	while(i <= fimList){
	   newList[k] = list[i];
	   i++;
	   k++;	
	}
	
	while(j <= fimLote){
		newList[k] = lote[j];
	    j++;
	    k++;
	}
}

void Remover(Usuario* list,int* lote, Usuario* newList, int fimList, int fimLote){
	int i = 0, j = 0, k = 0;
	while(j <= fimLote){
		if(list[i].id != lote[j]){
			newList[k] = list[i];
			cout << "Lista[" << k << "] recebe " << list[i].id << endl;
			k++;
		}else{
			cout << lote[j] << " removido!" << endl;
			j++;
		}
		i++;
	}
	while(i <= fimList){
		newList[k] = list[i];
		cout << "Lista[" << k << "] recebe " << list[i].id << endl;
		k++;
		i++;
	}
}

void Busca(Usuario* list, int f){
	int codigo;
	cout << "Informe o codigo de busca ~:> ";
	cin >> codigo;
	int inicio = 0;
	int meio = (inicio + f) / 2;
	while(codigo != list[meio].id && inicio < f){
		if(codigo > list[meio].id){
			inicio = meio + 1;
		}else{
			f = meio - 1;
		}
		meio = (inicio + f) / 2;
	}
	if(codigo == list[meio].id){
		cout << list[meio].id << " encontrado na posicao " << meio <<endl;
	}else{
		cout << "Codigo nao existe na lista!" << endl;
	}
}

void gerarLote(Usuario* lote){
	// 1, 19, 26, 98
	// Sam, Tia, June, Ruppert
	lote[0].id = 1;
	lote[0].nome = "Sam";
	lote[0].email = "sam@email.com";
	lote[0].idade = 30;
	lote[0].status = true;
	
	lote[1].id = 19;
	lote[1].nome = "Tia";
	lote[1].email = "tia@email.com";
	lote[1].idade = 25;
	lote[1].status = true;
	
	lote[2].id = 26;
	lote[2].nome = "June";
	lote[2].email = "jun@email.com";
	lote[2].idade = 6;
	lote[2].status = true;
	
    lote[3].id = 98;
	lote[3].nome = "Ruppert";
	lote[3].email = "ruppy@email.com";
	lote[3].idade = 50;
	lote[3].status = true;
}

