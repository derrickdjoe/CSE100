#include <iostream>
#include <limits.h>

using namespace std;

void bellFord(int size, int count){
	
	int s = 0;
	int d = 0;
	int w = 0;
	int distance[size];
	int **graph;
	graph = new int *[3];
	bool print = 1;

	for(int i = 0; i < size; i++){

		graph[i] = new int[count];

		for(int j = 0; j < size; j++){

			graph[i][j] = 0;

		}

	}

	for(int i = 0; i < count; i++){

		cin >> s;
		cin >> d;
		cin >> w;

		graph[0][i] = s;
		graph[1][i] = d;
		graph[2][i] = w;

	}
	
	for(int i = 0; i < size; i++){

		distance[i] = INT_MAX;

	}

	distance[0] = 0;

	for(int i = 1; i <= size - 1; i++){

		for(int j = 0; j < count; j++){

			int u = graph[0][j];
			int v = graph[1][j];
			int w = graph[2][j];

			if(distance[u] != INT_MAX && distance[u] + w < distance[v]){

				distance[v] = distance[u] + w;

			}

		}

	
	}

	for(int i = 0; i < count; i++){
	
		int u = graph[0][i];
		int v = graph[1][i];
		int w = graph[2][i];

		if(distance[u] != INT_MAX && distance[u] + w < distance[v]){

			cout << "FALSE" << endl;
			print = 0;

		}

	}

	if(print){

		cout << "TRUE" << endl;

		for(int i = 0; i < size; i++){

			if(distance[i] == INT_MAX){

				cout << "INFINITY" << endl;

			}else{
	
				cout << distance[i] << endl;

			}

		}

	}

}

int main(){

	int size;
	int count;

	cin >> size;
	cin >> count;

	bellFord(size, count);

}
	
