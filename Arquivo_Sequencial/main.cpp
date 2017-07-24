#include <iostream>
#include <stdio.h>
#include <fstream>
#include "estruturas.h"
using namespace std;

void gravar(Usuario*,int); // grava os valores da struct num arquivo.txt
void lerArquivo(Usuario*,int); // pega os valores do arquivo.txt e coloca na struct
void showList(Usuario*,int,string);
void ler(Usuario*,int);

int main(){
	Usuario u[6];
	lerArquivo(u, 5);
	showList(u, 5, "Lista de Usuarios");
	
	Usuario lote[4];
	gerarLote(lote);
	showList(lote, 3, "\nLote");
	
	// gravando conteudo do lote
	ofstream file;
	file.open("lote.txt");
	for(int i = 0; i < 4; i++){
		file << lote[i].id << "\t" << lote[i].nome << "\t" << lote[i].email;
		file << "\t" << lote[i].idade << "\t" << lote[i].status <<"\n";
	}
	file.close();
	
	// Criando uma nova lista
	Usuario novaLista[10];
	Inserir(u, lote, novaLista, 5, 3);
	showList(novaLista, 9, "\nNova Lista");
	
	//gravando conteudo da nova lista
	file.open("newList.txt");
	for(int i = 0; i < 10; i++){
		file << novaLista[i].id << "\t" << novaLista[i].nome << "\t" << novaLista[i].email;
		file << "\t" << novaLista[i].idade << "\t" << novaLista[i].status <<"\n";
	}
	file.close();
	
	cout << "\nBuscando Usuario..." << endl;
	Busca(novaLista, 9);
	
	cout << "\nRemovendo Lote..." << endl;
	Usuario listaAtualizada[6];
	int novoLote[4] = {0, 13, 22, 51}; // este lote receberá apenas os codigo de acesso 
	Remover(novaLista, novoLote, listaAtualizada, 9, 3);
	showList(listaAtualizada, 5, "\nLista Atualizada");
	// gravando a lista atualizado num arquivo.txt
	file.open("attList.txt");
	for(int i = 0; i < 6; i++){
	  	file << listaAtualizada[i].id << "\t" << listaAtualizada[i].nome << "\t" << listaAtualizada[i].email;
		file << "\t" << listaAtualizada[i].idade << "\t" << listaAtualizada[i].status <<"\n";
	}
	file.close();
	
	
	return 0;
}

void gravar(Usuario* u, int final){
	ofstream arquivo;
	arquivo.open("userlist.txt", std::ios_base::app); // escreve sem apagar o conteudo ja existente
	for(int i = 0; i <= final; i++){
		arquivo << u[i].id << "\t" << u[i].nome << "\t" << u[i].email << "\t" << u[i].idade << "\t" << u[i].status <<"\n";
	}
	arquivo.close();
}

void lerArquivo(Usuario* u, int final){
	ifstream arquivo;
	arquivo.open("userlist.txt");
	for(int i = 0;  i <= final; i++){
		// passando o conteudo do arquivo.txt para a struct
		arquivo >> u[i].id >> u[i].nome >> u[i].email >> u[i].idade >> u[i].status;
		// cada valor separado por espaços em branco e colocado em cada variavel
	} 
	arquivo.close();
}

void showList(Usuario* list, int final, string titulo){
    cout << titulo << endl;
    for(int i = 0; i <= final; i++){
    	cout << "{id=" << list[i].id << ",\t";
    	cout << "nome= " << list[i].nome << ",\t";
    	cout << "email=" << list[i].email << ",\t";
    	cout << "idade=" << list[i].idade << ",\t";
    	cout << "status=" << list[i].status << "}" << endl;
	}
}
