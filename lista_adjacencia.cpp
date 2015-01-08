//vetor de vertices (onde em cada vertice tem um lista com os vertices ligados)

// as colunas representam as arestas e as linhas representam os vertices 
// se a aresta ta ligada ao vertice, marca como true

#include <iostream>
#include <vector>
#include <list>
#define VERTICES 4

using namespace std;

enum Cor
{
	branco, cinza, preto
};

class No{
public:
	int tempo_descoberto;
	int tempo_finalizacao;
	Cor cor;
	list<int> vizinhos;
};

void print_grafo(std::vector<No> grafo){
	for (int i = 0; i < VERTICES; ++i)
	{
		cout << "[" << i << "] -- cor: " << grafo[i].cor << " -- tempo_descoberto: " << grafo[i].tempo_descoberto << " tempo_finalizacao: "<< grafo[i].tempo_finalizacao<<" -> ";
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

double dfs_visit(vector<No> *grafo, int posicao, int *tempo){
	*tempo = *tempo + 1;
	(*grafo)[posicao].cor = cinza;
	(*grafo)[posicao].tempo_descoberto = *tempo;
	auto end = (*grafo)[posicao].vizinhos.end();

	for(auto it = (*grafo)[posicao].vizinhos.begin(); it != end; ++it){
		if((*grafo)[*it].cor == branco){
			dfs_visit(grafo, *it, tempo);
		}
	}
	(*grafo)[posicao].cor = preto;
	*tempo = *tempo + 1;
	(*grafo)[posicao].tempo_finalizacao = *tempo;

	return 0;
}

bool dfs(vector<No> *grafo){
	int tempo = 0;

	for (int i = 0; i < VERTICES; ++i)
	{
		(*grafo)[i].cor = branco;
		(*grafo)[i].tempo_descoberto = 0;
		(*grafo)[i].tempo_finalizacao = 0;
	}
	for (int i = 0; i < VERTICES; ++i)
	{
		if((*grafo)[i].cor == branco){
			dfs_visit(grafo, i, &tempo);
		}
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


	dfs(&grafo);
	print_grafo(grafo);

	return 0;
}