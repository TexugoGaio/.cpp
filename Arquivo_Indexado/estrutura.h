#include <iostream>
#include <fstream>
using namespace std;

#define T 5

struct Usuario {
	int id;
	string nome;
	bool status;
};

struct Indice {
	int cod;
	int pos;
};

void gerarDados(){		
	string nomes[T] = {"Jane", "Laura", "Logan", "Sam", "Zoe"};
	int ids[T] = {22, 35, 11, 56, 48};
	Indice index[5];
	
	ofstream arq;
	// gerando lista de usuários
	arq.open("files/userlist.txt");
	for(int i = 0; i < T; i++){
		arq << ids[i] << "\t" << nomes[i] << "\t" << true << "\n";
		index[i].cod = ids[i];
		index[i].pos = i; 
	}
	arq.close();
	
	// Ordenando arquivo de Indice ~ Bubblesort
	for(int i = 0; i < T - 1; i++){
		for(int j = i + 1; j < T; j++){
			if(index[i].cod > index[j].cod){
				Indice aux = index[i];
				index[i] = index[j];
				index[j] = aux;
			}
		} // fim for j
	} // fim for i
	
	// gerando arquivo de indice
	arq.open("files/indexlist.txt");
	for(int i = 0; i < T; i++){
		arq << index[i].cod << "\t" << index[i].pos << "\n";
	}
	arq.close();	
}

void showUsers(Usuario* u, int final){
	cout << "\nUsuarios" << endl;
	for(int i = 0; i <= final; i++){
		cout << "{id=" << u[i].id << ",\tnome=" << u[i].nome << ",\tstatus=" << u[i].status << "}\n";  
	}
}

void showIndex(Indice* index, int final){
	cout << "\nArquivo de Indice" << endl;
	for(int i = 0; i <= final; i++){
		cout << "{cod=" << index[i].cod << ",\tpos=" << index[i].pos << "}\n"; 
	}
}
