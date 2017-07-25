#include <iostream>
#include <fstream>
#include "estrutura.h"
using namespace std;

void Inserir(Usuario*, Indice*, int&);
void Busca(Usuario*, Indice*, int);
void Remover(Usuario*, Indice*, int);
void Imprimir(Usuario*,int);
int Atualiza(Usuario*, Indice*,Usuario*, int);

int main(){
	Usuario u[10];
	Indice index[10];
	gerarDados();
	int final = T - 1;
	
	// carregando dados na estrutura Usuario
	ifstream arq;
	arq.open("files/userlist.txt");
	for(int i = 0; i <= final; i++){
		arq >> u[i].id >> u[i].nome >> u[i].status;
	}
	arq.close();
	cout << "Dados dos usuários carregados com sucesso!" << endl;
	
	//showUsers(u, final);
	
	// carregando dados na estrutura de Indice
	arq.open("files/indexlist.txt");
	for(int i = 0; i <= final; i++){
		arq >> index[i].cod >> index[i].pos;
	}
	arq.close();
	cout << "Arquivo de indice carregado com sucesso!" << endl;
	//showIndex(index, final);
	
	cout << "\nInserindo dados...";
	Inserir(u,index,final);
	showUsers(u, final);
	showIndex(index, final);
	
	cout << "\nBuscando dados..." << endl;
	Busca(u,index, final);
	
	cout << "\nRemovendo registro..." << endl;
	Remover(u,index,final);
	
	cout << "\nImprimindo dados..." << endl;
	Imprimir(u, final);
	
	cout << "\nAtualizando Lista..." << endl;
	Usuario listaAtualizada[10];
	final = Atualiza(u, index, listaAtualizada, final);
	
	showUsers(listaAtualizada, final);
	showIndex(index, final);
	
	// salvando dados da lista atualizada...
	ofstream salvar;
	salvar.open("files/listaAtualizada.txt");
	for(int i = 0; i <= final; i++){
		salvar << listaAtualizada[i].id << "\t" << listaAtualizada[i].nome << "\t" << listaAtualizada[i].status << "\n";
	}
	salvar.close();
	cout << "A lista foi atualizada e os dados foram salvos com sucesso!" << endl;
	
	return 0;
}

void Inserir(Usuario *u, Indice* index, int &final){
	if(final < 10){
		final++;
		u[final].id = 17;
		u[final].nome = "Lain";
		u[final].status = true;
		
		int aux = final - 1;
		while(aux >= 0 && u[final].id < index[aux].cod){
			index[aux + 1] = index[aux];
			aux--;
		}
		index[aux + 1].cod = u[final].id;
		index[aux + 1].pos = final;
	}
	
}

void Busca(Usuario *u, Indice* index, int final){
	int codigo;
	cout << "Informe o codigo de busca ~:> ";
	cin >> codigo;
	
	int inicio = 0;
	int meio = (inicio + final) / 2;
	while(codigo != index[meio].cod && inicio < final){
		if(codigo > index[meio].cod){
			inicio = meio + 1;
		}else{
			final = meio - 1;
		}
		meio = (inicio + final) / 2;
	}
	
	int i = index[meio].pos;
	
	if(codigo == u[i].id && u[i].status){
		cout << u[i].nome << " encontrado na posicao " << meio << " do indice, posicao " << i << " da lista." << endl;
	}else{
		cout << "Codigo nao existe na lista!" << endl;
	}
}

void Remover(Usuario *u, Indice* index, int final){
	int codigo;
	cout << "Informe o codigo de busca ~:> ";
	cin >> codigo;
	
	int inicio = 0;
	int meio = (inicio + final) / 2;
	while(codigo != index[meio].cod && inicio < final){
		if(codigo > index[meio].cod){
			inicio = meio + 1;
		}else{
			final = meio - 1;
		}
		meio = (inicio + final) / 2;
	}
	
	int i = index[meio].pos;
	
	if(codigo == u[i].id && u[i].status){
		u[i].status = false;
		cout << u[i].nome << " removido logicamente" << endl;
	}else{
		cout << "Codigo nao existe na lista!" << endl;
	}
}

void Imprimir(Usuario* u, int final){
	cout << "\nUsuarios" << endl;
	for(int i = 0; i <= final; i++){
		if(u[i].status){ // imprime apenas quando status for true
			cout << "{id=" << u[i].id << ",\tnome=" << u[i].nome << ",\tstatus=" << u[i].status << "}\n";  
		}
	}	
}

int Atualiza(Usuario* oldList, Indice* index, Usuario* newList, int final){ // Atualiza a lista e retorna um novo final
	int i = 0, k = 0;
	while(i <= final){
		int j = index[i].pos;
		if(oldList[j].status){
			newList[k] = oldList[j];
			index[k].cod = newList[k].id;
			index[k].pos = k;
			k++;
		}
		i++;
	}
	return k - 1;
}
