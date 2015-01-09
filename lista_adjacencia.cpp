//vetor de vertices (onde em cada vertice tem um lista com os vertices ligados)

// as colunas representam as arestas e as linhas representam os vertices 
// se a aresta ta ligada ao vertice, marca como true

#include <iostream>
#include <vector>
#include <list>
#define VERTICES 4

using namespace std;

void print_grafo(std::vector< list<int> > grafo){
	for (int i = 0; i < VERTICES; ++i)
	{
		cout << "[" << i << "] -> ";
		bool j = false;

		auto end = grafo[i].end();
		for(auto it = grafo[i].begin(); it != end; ++it)
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

int main() {
	vector< list<int> > grafo;

	// Set up size. (VERTICES)
	grafo.resize(VERTICES);


	// 0<->2
	// 0<->3
	// 1<->3
	// 2<->3
	grafo[0].push_back(2);
	grafo[0].push_back(3);

	grafo[1].push_back(3);

	grafo[2].push_back(0);
	grafo[2].push_back(3);

	grafo[3].push_back(0);
	grafo[3].push_back(1);
	grafo[3].push_back(2);



	print_grafo(grafo);

	return 0;
}