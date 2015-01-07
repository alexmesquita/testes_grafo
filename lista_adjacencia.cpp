//vetor de vertices (onde em cada vertice tem um lista com os vertices ligados)

// as colunas representam as arestas e as linhas representam os vertices 
// se a aresta ta ligada ao vertice, marca como true

#include <iostream>
#include <vector>
#include <queue>
#define VERtICES 4

using namespace std;

void print_grafo(std::vector< queue<int> > grafo){
	for (int i = 0; i < VERtICES; ++i)
	{
		cout << "[" << i << "] -> ";
		bool j = false;
		while(!grafo[i].empty())
		{
			if(j){
				cout << ", "; 
			}
			else{
				cout << "[";
				j=true;
			}

			cout << grafo[i].front();
			grafo[i].pop();
		}
		cout << "]" << endl;
	}
}

int main() {
	vector< queue<int> > grafo;

	// Set up size. (VERtICES)
	grafo.resize(VERtICES);


	// 0<->2
	// 0<->3
	// 1<->3
	// 2<->3
	grafo[0].push(2);
	grafo[0].push(3);

	grafo[1].push(3);

	grafo[2].push(0);
	grafo[2].push(3);

	grafo[3].push(0);
	grafo[3].push(1);
	grafo[3].push(2);



	print_grafo(grafo);

	return 0;
}