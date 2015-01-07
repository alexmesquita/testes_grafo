// as colunas representam as arestas e as linhas representam os vertices 
// se a aresta ta ligada ao vertice, marca como true

#include <iostream>
#include <vector>
#define HEIGHT 3
#define WIDTH 2

using namespace std;

void print_grafo(std::vector< std::vector<bool> > grafo){
	for (int i = 0; i < HEIGHT; ++i)
	{
		for(int j = 0; j < WIDTH; j++)
		{
			if(j){
				cout << ", "; 
			}
			else{
				cout << "[";
			}

			cout << grafo[i][j];
		}
		cout << "]" << endl;
	}
}

int main() {
	vector< vector<bool> > grafo;

	// Set up sizes. (HEIGHT x WIDTH)
	grafo.resize(HEIGHT);
	for (int i = 0; i < HEIGHT; ++i)
		grafo[i].resize(WIDTH);

	// a<->b
	// b<->c

	grafo[0][0] = true;
	grafo[1][0] = true;
	grafo[1][1] = true;
	grafo[2][1] = true;
	print_grafo(grafo);

	return 0;
}