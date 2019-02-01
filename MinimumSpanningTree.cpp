#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int vert = 0;
int edge = 0;

int minKey(int key[], bool mst[]){

	int min = INT_MAX;
	int index = 0;

	for(int i = 0; i < vert; i++){

		if(mst[i] == false && key[i] < min){

			min = key[i];
			index = i;

		}

	}

	return index;

}

void MST(int vert, int edge){
	
	//have to be here because vert is not known at compile time

	int x = 0;
	int y = 0;
	int w = 0;
	int graph[vert][vert];

	for(int i = 0; i < vert; i++){

		for(int j = 0; j < vert; j++){

			graph[i][j] = 0;

		}

	}

	for(int i = 0; i < edge; i++){

		cin >> x;
		cin >> y;
		cin >> w;

		graph[x][y] = w;
		graph[y][x] = w;

	}

	int weight[vert];
	int key[vert];
	bool mst[vert];

	for(int i = 0; i < vert; i++){

		key[i] = INT_MAX;
		mst[i] = false;

	}

	key[0] = 0;

	for(int i = 0; i < vert - 1; i++){

		int u = minKey(key, mst);
		mst[u] = true;

		for(int j = 0; j < vert; j++){

			if(graph[u][j] && mst[j] == false && graph[u][j] < key[j]){

				weight[j] = u;
				key[j] = graph[u][j];

			}

		}

	}

	for(int i = 1; i < vert; i++){

		cout << weight[i] << endl;

	}

}

int main(){

	int x;
	int y;
	int w;

	cin >> vert;
	cin >> edge;

	/*int graph[vert][vert];

	for(int i = 0; i < vert; i++){

		for(int j = 0; j < vert; j++){

			graph[i][j] = 0;

		}

	}

	for(int i = 0; i < edge; i++){

		cin >> x;
		cin >> y;
		cin >> w;

		graph[x][y] = w;
		graph[y][x] = w;

	} */

	MST(vert, edge);


}


	
