// Busca em largura (menor caminho)

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
#define VERTICES 4

using namespace std;

enum Cor
{
	branco, cinza, preto
};

class No{
public:
	long pai;
	long distancia;
	Cor cor;
	list<int> vizinhos;
};

void print_grafo(std::vector<No> grafo){
	for (int i = 0; i < VERTICES; ++i)
	{
		cout << "[" << i << "] -- cor: " << grafo[i].cor << " -- pai: ";
		cout << grafo[i].pai << " -- distancia: " << grafo[i].distancia <<" -> ";
		bool j = false;

		auto end = grafo[i].vizinhos.end();
		for(auto it = grafo[i].vizinhos.begin(); it != end; ++it)
		{
			if(j){
				cout << ", "; 
			}
			else{
				cout << "[";
				j=true;
			}

			cout << *it;
		}
		cout << "]" << endl;
	}
}


bool bfs(vector<No> *grafo, int origem){

	for (int i = 0; i < VERTICES; ++i)
	{
		if(i == origem){
			continue;
		}
		(*grafo)[i].cor = branco;
		(*grafo)[i].distancia = LONG_MAX;
		(*grafo)[i].pai = LONG_MAX;
	}
	(*grafo)[origem].cor = cinza;
	(*grafo)[origem].distancia = 0;
	(*grafo)[origem].pai = LONG_MAX;

	// O certo era enfileirar o nó, mas fiz o indice por ser mais fácil.
	queue<int> fila;

	fila.push(origem);

	while(!fila.empty()){
		int aux = fila.front();
		fila.pop();

		auto end = (*grafo)[aux].vizinhos.end();

		for(auto it = (*grafo)[aux].vizinhos.begin(); it != end; ++it){
			if((*grafo)[*it].cor == branco){
				(*grafo)[*it].cor = cinza;
				(*grafo)[*it].distancia = (*grafo)[aux].distancia + 1;
				(*grafo)[*it].pai = aux;
				//se for o procurado dá o break e retorna
				fila.push(*it);
			}
		}
		(*grafo)[aux].cor = preto;
	}
	return false;
}


int main() {
	vector<No> grafo;

	// Set up size. (VERTICES)
	grafo.resize(VERTICES);


	// 0<->2
	// 0<->3
	// 1<->3
	// 2<->3
	grafo[0].vizinhos.push_back(2);
	grafo[0].vizinhos.push_back(3);

	grafo[1].vizinhos.push_back(3);

	grafo[2].vizinhos.push_back(0);
	grafo[2].vizinhos.push_back(3);

	grafo[3].vizinhos.push_back(0);
	grafo[3].vizinhos.push_back(1);
	grafo[3].vizinhos.push_back(2);


	bfs(&grafo, 0);
	print_grafo(grafo);

	return 0;
}