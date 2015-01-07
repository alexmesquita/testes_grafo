// matriz nxn, as colunas e as linhas representam vertices
// se Aij = 1, significa q existe uma aresta entre os vertices i e j

#include <iostream>
#include <vector>
#define HEIGHT 4
#define WIDTH 4

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

	for (int i = 0; i < HEIGHT; ++i)
	{
		for(int j = 0; j < WIDTH; j++)
		{
			if(j != i){
				grafo[i][j] = true;
			}
			else{
				grafo[i][j] = false;
			}
		}
	}

	print_grafo(grafo);

	return 0;
}